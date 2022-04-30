#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MAX_BUF
#define MAX_BUF 1024
#endif


int main() {

    FILE *path;
    FILE *tree;
    FILE *log;
    char directory[MAX_BUF];
    char c;


    //Print current directory
    printf("\nCurrent working directory:\n\n");
    sleep(2);

    system("pwd");
    sleep(1);

    //open t2.txt in write mode
    path = fopen("t2.txt", "w");

    printf("\nWriting current directory to t2.txt\n\n");
    sleep(2);

    //t2.txt cannot open error
    if(path == NULL || tree == NULL){
        printf("\nCannot open file!\n");
        exit(0);
    }

    //Write current working directory to t2.txt
    getcwd(directory, MAX_BUF);
    int results = fputs(directory, path);
    if(results == EOF)
    {
        printf("\nError writing current directory to file");
    };

    printf("Compelete!");
    fclose(path);           //close t2.txt in write mode
    sleep(1);


    //Rename t2.txt to path
    printf("\n\nRenaming t2.txt to path.txt\n");
    sleep(2);

    rename("t2.txt", "path.txt");
    if( access( "path.txt", F_OK ) == 0 ) {
        printf("DONE!\n");
        system("ls");
        sleep(1);
    } else {
        printf("FAILED TO RENAME!");
        exit(0);
    }


    //Create final txt file, log.txt contains tree.txt and path.txt contents
    printf("\n\nAccessing t3.txt\n");
    sleep(2);
    log = fopen("t3.txt", "a");
    if(log == NULL){
        printf("File write error");
        exit(0);
    }

    printf("COMPLETE!\n");
    sleep(1);


    //open tree.txt and path.txt in read mode
    tree = fopen("tree.txt", "r");
    path = fopen("path.txt", "r");


    printf("\n\nAdding contents to log.txt file\n");
    c = fgetc(tree);
    while((c != EOF)) {
        fputc(c, log);
        c = fgetc(tree);
    }
    c = fgetc(path);
    while((c != EOF)) {
        fputc(c, log);
        c = fgetc(path);
    }

    sleep(2);
    printf("DONE!\n");

    fclose(path);
    fclose(tree);
    fclose(log);

    //Rename t3.txt to log
    printf("\n\nRenaming t3.txt to log.txt\n");
    sleep(2);

    rename("t3.txt", "log.txt");
    if( access( "log.txt", F_OK ) == 0 ) {
        printf("DONE!\n");
        system("ls");
        sleep(1);
    } else {
        printf("FAILED TO RENAME!");
        exit(0);
    }


    //delete tree.txt and path.txt
    printf("\n\nDeleting tree.txt\n");
    sleep(1);
    if(remove("tree.txt")==0){
        printf("tree.txt has been deleted!\n");
        sleep(1);
    } else{
        printf("Deleting tree.txt failed!\n");
        exit(1);
    };

    printf("\n\nDeleting path.txt\n");
    sleep(1);
    if(remove("path.txt")==0){
        printf("path.txt has been deleted!\n");
    } else{
        printf("Deleting tree.txt failed!\n");
    };


}

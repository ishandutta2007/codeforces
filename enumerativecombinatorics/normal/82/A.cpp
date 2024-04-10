#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int minus=5;
    while(minus<a){
        a-=minus;
        minus*=2;
    }
    a--;
    minus/=5;
    switch(a/minus){
        case 0:printf("Sheldon\n");break;
        case 1:printf("Leonard\n");break;
        case 2:printf("Penny\n");break;
        case 3:printf("Rajesh\n");break;
        case 4:printf("Howard\n");break;
    }
}
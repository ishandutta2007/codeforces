#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int now=1;
    for(int i=0;i<a-1;i++)now=(now*3)%1000003;
    printf("%d\n",now);
}
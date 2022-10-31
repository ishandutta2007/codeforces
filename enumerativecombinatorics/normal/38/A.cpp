#include<stdio.h>
int s[123];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a-1;i++)scanf("%d",s+i);
    int b,c;
    scanf("%d%d",&b,&c);
    int ret=0;
    for(int i=b-1;i<c-1;i++)ret+=s[i];
    printf("%d\n",ret);
}
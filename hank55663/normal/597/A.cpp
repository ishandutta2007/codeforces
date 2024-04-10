#include<stdio.h>
#include<cstring>
main(){
    long long int k,a,b;
    scanf("%I64d %I64d %I64d",&k,&a,&b);
    int num=0;
    if(a%k==0)
        num++;
    if(b<0&&b%k!=0)
        num--;
    if(a<0&&a%k!=0)
        num++;
    printf("%I64d",b/k-a/k+num);
}
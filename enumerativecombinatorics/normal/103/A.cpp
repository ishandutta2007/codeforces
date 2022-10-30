#include<stdio.h>
int main(){
    int a;
    long long ret=0;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int b;
        scanf("%d",&b);
        ret+=(long long)(b-1)*(i+1);
    }
    printf("%I64d\n",ret+a);
}
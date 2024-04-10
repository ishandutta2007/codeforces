#include<stdio.h>
using namespace std;
long long abs(long long n){
    if(n>0)
        return n;
    else
        return n*-1;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    long long n,i=0;
    scanf("%I64d",&n);
    while(i*(i+1)/2<abs(n)||(abs(n)-i*(i+1)/2)%2!=0)
        i++;
    printf("%I64d",i);
    return 0;
}
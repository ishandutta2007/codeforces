#include<cstdio>
#include<cmath>
int main(){
    int n,a,b,c,d,e;
    scanf("%1d%1d%1d%1d%1d",&a,&b,&c,&d,&e);
    n=(((a*10+c)*10+e)*10+d)*10+b;
    printf("%05I64d\n",1LL*n*n%100000*n%100000*n%100000*n%100000);
}
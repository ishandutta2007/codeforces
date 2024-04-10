#include <stdio.h>
long long int n,m,a,x,y;
int main (){
    scanf("%lld %lld %lld",&n,&m,&a);
    x=n/a;
    if(n%a!=0) x++;
    y=m/a;
    if(m%a!=0) y++;
    printf("%lld\n",x*y);
    return 0;
}
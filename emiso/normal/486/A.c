#include <stdio.h>

int main()
{
    long long x;
    scanf("%lld",&x);
    if(x%2==1) printf("-");
    x++;
    printf("%lld\n",x/2);
    return 0;
}
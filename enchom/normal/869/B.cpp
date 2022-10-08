#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int a,b;

int main()
{
    Int i;
    Int ans;

    scanf("%lld %lld",&a,&b);

    if (a==b)
    {
        printf("1\n");
        return 0;
    }

    ans=(a+1LL)%10LL;
    for (i=a+2;i<=b;i++)
    {
        ans*=(i%10LL);
        ans%=10LL;

        if (ans==0)
        break;
    }

    printf("%lld\n",ans);

    return 0;
}
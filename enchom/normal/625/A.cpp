#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    Int n,a,b,c;
    Int ans;

    scanf("%lld %lld %lld %lld",&n,&a,&b,&c);

    if (a<=b-c)
    {
        printf("%lld\n",n/a);
    }
    else
    {
        if (n>b)
        ans=(n-b)/(b-c);
        else
        ans=0;

        n-=ans*(b-c);

        while(n>=b)
        {
            n-=(b-c);
            ans++;
        }

        ans+=n/a;
        n%=a;

        printf("%lld\n",ans);
    }

    return 0;
}
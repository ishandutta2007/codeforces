#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int x,y,a,b;

Int gcd(Int a,Int b)
{
    Int r;

    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int main()
{
    Int nok;
    Int l,r;

    scanf("%I64d %I64d %I64d %I64d",&x,&y,&a,&b);

    nok=(x*y)/gcd(x,y);

    r=b/nok;
    l=a/nok;

    if (a%nok!=0)
    {
        l++;
    }

    printf("%I64d\n",r-l+1);

    return 0;
}
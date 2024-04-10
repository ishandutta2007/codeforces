#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int gcd(Int a,Int b)
{
    Int r;
    Int total=0;

    while(b!=0)
    {
        total=total+a/b;

        r=a%b;
        a=b;
        b=r;
    }

    return total;
}

int main()
{
    Int a,b;

    scanf("%I64d %I64d",&a,&b);

    printf("%I64d\n",gcd(a,b));

    return 0;
}
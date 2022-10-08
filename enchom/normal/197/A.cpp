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
    Int a,b,r;

    scanf("%I64d %I64d %I64d",&a,&b,&r);

    if (2*r>MIN(a,b))
    {
        printf("Second\n");
    }
    else
    {
        printf("First\n");
    }

    return 0;
}
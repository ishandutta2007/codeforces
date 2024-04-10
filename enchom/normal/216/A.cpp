#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int a,b,c;
    Int total=0;

    scanf("%I64d %I64d %I64d",&a,&b,&c);

    total=a*b+a*c+b*c-a-b-c+1;

    printf("%I64d\n",total);
    return 0;
}
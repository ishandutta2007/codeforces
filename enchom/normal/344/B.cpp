#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int a,b,c;
    Int i;
    Int A,B,C;

    scanf("%I64d %I64d %I64d",&a,&b,&c);

    if ( (a+b+c)%2!=0 )
    {
        printf("Impossible\n");
        return 0;
    }

    for (i=0;i<=a;i++)
    {
        A=i;
        B=b-i;
        C=(a+b+c)/2-A-B;


        if (A<0 || B<0 || C<0 || A+B!=b || B+C!=c || C+A!=a)
        {
            continue;
        }
        else
        {
            printf("%I64d %I64d %I64d\n",A,B,C);
            return 0;
        }
    }

    printf("Impossible\n");

    return 0;
}
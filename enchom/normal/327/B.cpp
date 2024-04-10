#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int n;
bool er[10000001];

int main()
{
    Int i,j;
    Int ctr=0;

    scanf("%I64d",&n);

    memset(er,true,sizeof(er));

    for (i=2;i<=10000000;i++)
    {
        if (er[i])
        {
            printf("%I64d",i);

            ctr++;
            if (ctr==n)
            break;

            printf(" ");

            for (j=i+i;j<=10000000;j+=i)
            {
                er[j]=false;
            }
        }
    }
    printf("\n");

    return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;

int n;
bool Prime[2000111];

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=2000000;i++)
    {
        Prime[i]=true;
    }

    Prime[1]=false;
    for (i=2;i<=2000000;i++)
    {
        if (Prime[i])
        {
            for (j=i+i;j<=2000000;j+=i)
            {
                Prime[j]=false;
            }
        }
    }

    for (i=1;i<=1000;i++)
    {
        if ( !Prime[i*n+1] )
        {
            printf("%d\n",i);
            break;
        }
    }

    return 0;
}
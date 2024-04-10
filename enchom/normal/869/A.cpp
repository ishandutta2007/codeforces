#include <iostream>
#include <stdio.h>
using namespace std;

bool exists[2000111];
int x[2111];
int y[2111];
int n;

int main()
{
    int i,j;
    int val;
    int ans=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);

        exists[ x[i] ]=true;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&y[i]);

        exists[ y[i] ]=true;
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            val=x[i]^y[j];

            if (val>2000000)
            continue;

            if (exists[ val ])
            ans++;
        }
    }

    if (ans%2==0)
    {
        printf("Karen\n");
    }
    else
    {
        printf("Koyomi\n");
    }

    return 0;
}
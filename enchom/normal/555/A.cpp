#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;

int chain[100111];

int main()
{
    int i,j;
    int L;
    int a;
    int total=0;
    bool gonebad;
    int cur,longest;

    scanf("%d %d",&n,&k);

    total=n-1+(n-k);
    longest=0;

    for (i=1;i<=k;i++)
    {
        scanf("%d",&L);

        cur=0;

        gonebad=false;
        for (j=1;j<=L;j++)
        {
            scanf("%d",&chain[j]);

            if (gonebad)
            continue;

            if (j==1 && chain[j]!=1)
            gonebad=true;

            if (j>1)
            {
                if (chain[j]==chain[j-1]+1) ///okay
                {
                    cur++;
                }
                else
                {
                    gonebad=true;
                }
            }
        }

        if (cur>longest)
        longest=cur;
    }

    printf("%d\n",total-2*longest);

    return 0;
}
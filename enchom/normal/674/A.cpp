#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n;
int nums[5111];
int ctr[5111];
int ans[5111];

int main()
{
    int i,j;
    int maxcol,maxseen;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    for (i=1;i<=n;i++)
    {
        memset(ctr,0,sizeof(ctr));

        maxcol=0;
        maxseen=0;

        for (j=i;j<=n;j++)
        {
            ctr[ nums[j] ]++;

            if (ctr[ nums[j] ]>maxseen || (ctr[nums[j]]==maxseen && nums[j]<maxcol))
            {
                maxseen=ctr[ nums[j] ];
                maxcol=nums[j];
            }

            ans[maxcol]++;
        }
    }

    for (i=1;i<=n;i++)
    {
        printf("%d",ans[i]);

        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}
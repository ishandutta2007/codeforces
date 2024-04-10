#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;

int main()
{
    int i;
    int l,r;
    int cur;

    scanf("%d %d",&n,&k);

    if (k==1)
    {
        for (i=1;i<=n;i++)
        {
            printf("%d",i);
            if (i!=n)
            printf(" ");
        }
        printf("\n");
    }
    else
    {
        l=1;
        r=n;
        for (i=1;i<=k;i++)
        {
            if (i%2==1)
            {
                printf("%d",l);
                l++;
            }
            else
            {
                printf("%d",r);
                r--;
            }
            if (i!=k)
            printf(" ");
        }

        if (k%2==0)
        {
            for (i=r;i>=l;i--)
            {
                printf(" %d",i);
            }
            printf("\n");
        }
        else
        {
            for (i=l;i<=r;i++)
            {
                printf(" %d",i);
            }
            printf("\n");
        }
    }

    return 0;
}
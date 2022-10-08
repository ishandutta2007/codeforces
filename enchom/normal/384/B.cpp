#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m,k;
    int actions;
    int i,j;

    scanf("%d %d %d",&n,&m,&k);

    actions=( m*(m-1) )/2;

    printf("%d\n",actions);

    if (k==0)
    {
        for (i=1;i<=m-1;i++)
        {
            for (j=1;j<=m-i;j++)
            {
                printf("%d %d\n",j,j+1);
            }
        }
    }
    else
    {
        for (i=1;i<=m-1;i++)
        {
            for (j=m;j>=i+1;j--)
            {
                printf("%d %d\n",j,j-1);
            }
        }
    }

    return 0;
}
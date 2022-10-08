#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int sum=0;

int main()
{
    int i,j;
    int num;
    int q;
    int cm;
    int rc;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%d",&num);

            if (i==j)
            {
                sum+=num;
            }
        }
    }

    sum%=2;

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d",&cm);

        if (cm==3)
        {
            printf("%d",sum);
        }
        else
        {
            scanf("%d",&rc);

            sum=sum^1;
        }
    }

    printf("\n");

    return 0;
}
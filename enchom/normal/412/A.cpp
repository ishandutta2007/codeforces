#include <iostream>
#include <stdio.h>
using namespace std;

char slogan[101];
int n,k;
bool painted[101];

void Paint(int p)
{
    if (painted[p])
    return;

    painted[p]=true;

    printf("PRINT %c\n",slogan[p]);

    return;
}

int main()
{
    int i;
    int lefty,righty;

    scanf("%d %d",&n,&k);

    scanf("%s",slogan+1);

    lefty=k-1;
    righty=n-k;

    if (lefty<=righty)
    {
        for (i=k;i>=2;i--)
        {
            Paint(i);

            printf("LEFT\n");
        }

        for (i=1;i<=n;i++)
        {
            Paint(i);

            if (i!=n)
            printf("RIGHT\n");
        }
    }
    else
    {
        for (i=k;i<n;i++)
        {
            Paint(i);

            printf("RIGHT\n");
        }

        for (i=n;i>=1;i--)
        {
            Paint(i);

            if (i!=1)
            printf("LEFT\n");
        }
    }

    return 0;
}
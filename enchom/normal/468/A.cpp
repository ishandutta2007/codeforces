#include <iostream>
#include <stdio.h>
using namespace std;

int n;

int main()
{
    int i;

    scanf("%d",&n);

    if (n>=6)
    {
        printf("YES\n");

        printf("%d + %d = %d\n",n-1,1,n);
        printf("%d - %d = %d\n",n,n,0);

        for (i=n-2;i>=5;i--)
        {
            printf("%d * %d = %d\n",0,i,0);
        }

        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
        printf("24 + 0 = 24\n");
    }
    else
    {
        if (n==1 || n==2 || n==3)
        {
            printf("NO\n");
        }
        else if (n==4)
        {
            printf("YES\n");
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
        }
        else if (n==5)
        {
            printf("YES\n");
            printf("5 * 4 = 20\n");
            printf("3 + 2 = 5\n");
            printf("5 - 1 = 4\n");
            printf("20 + 4 = 24\n");
        }
    }

    return 0;
}
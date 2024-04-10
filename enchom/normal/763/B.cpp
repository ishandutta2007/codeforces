#include <iostream>
#include <stdio.h>
using namespace std;

int n;

int ABS(int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

int main()
{
    int x1,y1,x2,y2;
    int i;

    scanf("%d",&n);

    printf("YES\n");

    for (i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        x1=ABS(x1);
        y1=ABS(y1);

        if (y1%2==0)
        {
            if (x1%2==0)
            printf("1\n");
            else
            printf("2\n");
        }
        else
        {
            if (x1%2==0)
            printf("3\n");
            else
            printf("4\n");
        }
    }

    return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;

int a[301];
int n;

void UselessMove(int ind)
{
    if (ind==1)
    printf("RL");
    else
    printf("LR");
}

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=a[i];j++)
        {
            printf("P");
            UselessMove(i);
        }

        if (i!=n)
        printf("R");
    }

    printf("\n");

    return 0;
}
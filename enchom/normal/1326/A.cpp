#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    int t;
    int test;
    int i,j;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);
        if (n == 1)
        {
            printf("-1\n");
            continue;
        }

        printf("5");
        for (i=1;i<n;i++)
        {
            printf("3");
        }
        printf("\n");
    }
}
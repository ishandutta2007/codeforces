#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int t;
    int i, j;
    int test;
    int n;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        if (n % 2 == 1)
        {
            printf("NO\n");
            continue;
        }

        while(n % 2 == 0)
            n /= 2;

        int sq = floor(sqrt((double)n) + 0.5);

        if (sq * sq == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
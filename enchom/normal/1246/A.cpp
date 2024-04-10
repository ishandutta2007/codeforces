#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int getBits(llong num)
{
    int ans = 0;

    while(num > 0)
    {
        ans += num % 2LL;
        num /= 2LL;
    }

    return ans;
}

int main()
{
    int n, p;
    int i;

    scanf("%d %d",&n,&p);

    for (i=1;i<=100;i++)
    {
        llong goal = (llong)n - (llong)p * (llong)i;

        if (goal <= 0)
            continue;

        int minpos = getBits(goal);

        if (minpos <= i && i <= goal)
        {
            printf("%d\n",i);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}
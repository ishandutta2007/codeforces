#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1020
#define int long long
#pragma GCC optimize("O3")
using namespace std;

int l[N], r[N];

void Solve(void)
{
    int n;
    int i, t;

    scanf("%I64d", &n);
    for(i = 0;i < n;i ++)
        scanf("%I64d %I64d", &l[i], &r[i]);
    
    for(i = t = 0;i < n;i ++)
    {
        t = max(t, l[i]);
        if(t > r[i])
            printf("0 ");
        else
        {
            printf("%I64d ", t);
            t ++;
        }
    }
    printf("\n");

    return;
}

signed main()
{
    int t;

    scanf("%I64d", &t);
    while(t --)
        Solve();

    return 0;
}
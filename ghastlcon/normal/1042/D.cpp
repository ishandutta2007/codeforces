#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
using namespace std;

long long f[N];
long long t, o;

void CDQ(int l, int r)
{
    int m;
    int i, j;

    if(l >= r)
        return;

    m = (l + r) >> 1;
    CDQ(l    , m);
    CDQ(m + 1, r);

    sort(f + l    , f + m + 1);
    sort(f + m + 1, f + r + 1);
    for(i = l, j = m; i <= m; i ++)
    {
        while(j + 1 <= r && f[j + 1] < f[i] + t)
            j ++;
        o += j - m;
    }

    return;
}

int main(void)
{
    int n, x;
    int i;

    scanf("%d %lld", &n, &t);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &x);
        f[i] = f[i - 1] + x;
    }

    CDQ(0, n);
    printf("%lld\n", o);

    return 0;
}

//
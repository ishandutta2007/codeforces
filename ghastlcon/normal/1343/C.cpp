#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#define N 200020
using namespace std;

int a[N];
int f[N];
long long g[N];
map<int, long long> h[2];

int main(void)
{
    int t, n;
    int i, c;
    long long o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i ++)
            scanf("%d", &a[i]);

        h[0].clear();
        h[1].clear();
        for(i = 1, c = -1; i <= n; i ++)
        {
            f[i] = 1;
            g[i] = a[i];
            if(a[i] < 0)
            {
                if(!h[0].empty())
                {
                    f[i] = h[0].rbegin() -> first + 1;
                    g[i] = h[0].rbegin() -> second + a[i];
                }
                if(!h[1].count(f[i]))
                    h[1][f[i]] = g[i];
                else
                    h[1][f[i]] = max(h[1][f[i]], g[i]);
            }
            else
            {
                if(!h[1].empty())
                {
                    f[i] = h[1].rbegin() -> first + 1;
                    g[i] = h[1].rbegin() -> second + a[i];
                }
                if(!h[0].count(f[i]))
                    h[0][f[i]] = g[i];
                else
                    h[0][f[i]] = max(h[0][f[i]], g[i]);
            }

            if(f[i] > c)
            {
                c = f[i];
                o = g[i];
            }
            else if(f[i] == c)
                o = max(o, g[i]);
        }
        printf("%I64d\n", o);
    }

    return 0;
}
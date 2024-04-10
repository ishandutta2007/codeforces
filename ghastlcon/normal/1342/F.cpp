#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#define N 16
using namespace std;

int a[N];
int f[N][1 << N | 1], g[N][1 << N | 1], h[1 << N | 1];
int p[N];

int main(void)
{
    int t, n;
    int i, j, k, s, l;
    vector<int> y, x;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i ++)
            scanf("%d", &a[i]);

        for(l = 0; l < n; l ++)
        {
            for(s = 0; s < (1 << n); s ++)
                if(__builtin_popcount(s) == l)
                {
                    x.clear();
                    y.clear();
                    x.push_back(0);
                    for(i = 0; i < n; i ++)
                        (s & (1 << i) ? y : x).push_back(i);

                    for(i = 0; i < (1 << y.size()); i ++)
                        for(j = h[i] = 0; j < (signed)y.size(); j ++)
                            if(i & (1 << j))
                                h[i] += a[y[j]];

                    for(i = 0; i < (1 << y.size()); i ++)
                        f[0][i] = INT_MAX;
                    f[0][0] = 0;
                    for(i = 1; i < (signed)x.size(); i ++)
                        for(j = 0; j < (1 << y.size()); j ++)
                        {
                            f[i][j] = INT_MAX;
                            if(a[x[i]] > f[i - 1][j])
                            {
                                f[i][j] = a[x[i]];
                                g[i][j] = 0;
                            }
                            else
                                for(k = j; k; k = (k - 1) & j)
                                    if(a[x[i]] + h[k] > f[i - 1][j ^ k] && a[x[i]] + h[k] < f[i][j])
                                    {
                                        f[i][j] = a[x[i]] + h[k];
                                        g[i][j] = k;
                                    }
                        }

                    if(f[x.size() - 1][(1 << y.size()) - 1] != INT_MAX)
                        break;
                }
            if(s < (1 << n))
                break;
        }

        printf("%d\n", l);
        for(i = 0; i < n; i ++)
            p[i] = i;
        for(i = (signed)x.size() - 1, k = (1 << y.size()) - 1; i > 0; i --)
        {
            for(j = 0; j < (signed)y.size(); j ++)
                if(g[i][k] & (1 << j))
                {
                    printf("%d %d\n", p[y[j]] + 1, p[x[i]] + 1);
                    for(l = y[j]; l < n; l ++)
                        p[l] --;
                }
            k ^= g[i][k];
        }
    }

    return 0;
}
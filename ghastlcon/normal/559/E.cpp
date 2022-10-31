#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <utility>
#define N 120
using namespace std;

pair<int, int> a[N];
int f[N][N][2];

int main(void)
{
    int n;
    int i, j, k, s, o;
    int l, r, v, x, y, t;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d %d", &a[i].first, &a[i].second);

    sort(a + 1, a + n + 1);
    a[0].first = INT_MIN >> 2;
    for(i = 0; i <= n; i ++)
        for(j = 0; j <= i; j ++)
            for(k = 0; k <= 1; k ++)
            {
                l = a[j].first + k * a[j].second;
                v = INT_MIN >> 2;
                for(t = i + 1; t <= n; t ++)
                    for(s = 0; s <= 1; s ++)
                    {
                        r = a[t].first + s * a[t].second;
                        if(r > v)
                        {
                            v = r;
                            x = t;
                            y = s;
                        }
                        f[t][x][y] = max(f[t][x][y], f[i][j][k] + min(a[t].second, r - l) + v - r);
                    }
            }

    for(i = o = 0; i <= n; i ++)
        for(j = 0; j <= i; j ++)
            o = max(o, max(f[i][j][0], f[i][j][1]));
    printf("%d\n", o);

    return 0;
}
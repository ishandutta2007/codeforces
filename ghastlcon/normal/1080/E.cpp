#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 260
#define M 26
#define K 389
#define MOD 1610612741
#pragma GCC optimize("O3")
using namespace std;

char s[N][N];
int f[N][M], c[N], g[N], k[N];
int h[N << 1], l[N << 1];

int main(void)
{
    int n, m;
    int i, j, t, p;
    long long o;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
        scanf("%s", s[i] + 1);
    for(i = k[0] = 1; i < N; i ++)
        k[i] = (long long)k[i - 1] * K % MOD;

    for(i = 1, o = 0; i <= m; i ++)
    {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(h, 0, sizeof(h));
        memset(c, 0, sizeof(c));
        memset(l, 0, sizeof(l));
        for(j = i; j <= m; j ++)
        {
            h[1] = 0;
            for(t = 1; t <= n; t ++)
            {
                f[t][s[t][j] - 97] ++;
                g[t] = ((long long)g[t] + k[s[t][j] - 97]) % MOD;
                if(f[t][s[t][j] - 97] & 1)
                    c[t] ++;
                else
                    c[t] --;

                h[t * 2] = c[t] <= 1 ? g[t] : -t;
                h[t * 2 + 1] = 0;
            }

            // printf("%d-%d:\n",i,j);
            // for(t=1;t<=n*2+1;t++)printf("%d ",h[t]);cout<<endl;

            for(t = p = 1; t <= n * 2 + 1; t ++)
            {
                l[t] = (t < p + l[p] ? min(l[p * 2 - t], p + l[p] - t) : 1);
                while(t - l[t] >= 1 && t + l[t] <= n * 2 + 1 && h[t - l[t]] == h[t + l[t]])
                    l[t] ++;
                if(t + l[t] > p + l[p])
                    p = t;

                if(h[t] >= 0)
                {
                    // printf("add %d %d\n", t, l[t] - (t & 1));
                    o += l[t] / 2;
                }
            }
            // for(t=1;t<=n*2+1;t++)printf("%d ",l[t]);cout<<endl;
        }
    }
    printf("%lld\n", o);

    return 0;
}
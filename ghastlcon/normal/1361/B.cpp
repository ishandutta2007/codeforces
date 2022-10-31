#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 10000020
#define MOD 1000000007
using namespace std;

int a[N];
int g[N], s[N];

int Power(int x, int y)
{
    int o;

    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % MOD;
        x = (long long)x * x % MOD;
    }

    return o;
}

int main(void)
{
    int t, n, p;
    int i, j, c, v, f;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &p);
        for(i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        sort(a, a + n);

        if(p == 1)
        {
            printf("%d\n", n & 1);
            continue;
        }

        for(i = n - 1, f = -1, c = 0; i > -1; i --)
            if(f == -1)
                f = a[i];
            else
            {
                g[a[i]] ++;
                s[c ++] = a[i];
                for(j = a[i]; g[j] == p; j ++)
                {
                    g[j] = 0;
                    g[j + 1] ++;
                    s[c ++] = j + 1;
                }

                if(j == f)
                {
                    // printf("removed %d : %d\n", )
                    g[j] = 0;
                    f = -1;
                }
            }

        if(f == -1)
            printf("0\n");
        else
        {
            v = Power(p, f);
            sort(s, s + c);
            c = (int)(unique(s, s + c) - s);
            for(i = 0; i < c; i ++)
                v = (v - (long long)g[s[i]] * Power(p, s[i]) % MOD + MOD) % MOD;
            printf("%d\n", v);
        }

        for(i = 0; i < c; i ++)
            g[s[i]] = 0;
    }

    return 0;
}
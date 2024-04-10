#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <utility>
#define N 1020
#define M 400020
#define K 14
#define S 26
using namespace std;

class Node
{
public:
    int s[S];
    int f;
    long long g;

    Node(void) : f(0), g(0)
    {
        memset(s, 0, sizeof(s));

        return;
    }
};

char a[M];
Node f[N];
int c;
long long g[1 << K | 1][N];
pair<int, long long> h[K][N];

void InsertACAM(char *s, int v)
{
    int i, p;

    for(i = p = 0; s[i]; i ++)
    {
        if(!f[p].s[s[i] - 97])
            f[p].s[s[i] - 97] = c ++;
        p = f[p].s[s[i] - 97];
    }
    f[p].g += v;

    return;
}

void InitACAM(void)
{
    static int q[N];
    int l, r;
    int i, s, t;

    l = r = 0;
    for(i = 0; i < S; i ++)
        if(f[0].s[i])
            q[r ++] = f[0].s[i];

    for(; l < r; l ++)
    {
        s = q[l];
        f[s].g += f[f[s].f].g;
        for(i = 0; i < S; i ++)
            if(f[s].s[i])
            {
                t = f[s].s[i];
                for(f[t].f = f[s].f; f[t].f && !f[f[t].f].s[i]; f[t].f = f[f[t].f].f)
                    ;
                f[t].f = f[f[t].f].s[i];
                q[r ++] = t;
            }
            else
                f[s].s[i] = f[f[s].f].s[i];
    }

    return;
}

int main(void)
{
    int n, m, p;
    int i, j, l, b, t;
    long long s;
    vector<int> k;

    scanf("%d", &n);
    for(i = 0, c = 1; i < n; i ++)
    {
        scanf("%s %d", a, &p);
        InsertACAM(a, p);
    }
    InitACAM();

    scanf("%s", a);
    n = (int)strlen(a);
    for(i = 0; i < n; i ++)
        if(a[i] == '?')
            k.push_back(i);

    m = (int)k.size();
    k.push_back(n);
    for(i = p = s = 0; i < k.front(); i ++)
    {
        p = f[p].s[a[i] - 97];
        s += f[p].g;
    }

    for(i = 0; i < (1 << K); i ++)
        for(j = 0; j < c; j ++)
            g[i][j] = LLONG_MIN >> 2;
    for(i = 0; i < m; i ++)
        for(j = 0; j < c; j ++)
        {
            h[i][j].first = j;
            for(b = k[i] + 1; b < k[i + 1]; b ++)
            {
                h[i][j].first = f[h[i][j].first].s[a[b] - 97];
                h[i][j].second += f[h[i][j].first].g;
            }
        }

    g[0][p] = s;
    for(i = 0; i < (1 << K); i ++)
        if((t = __builtin_popcount(i)) < m)
            for(j = 0; j < c; j ++)
                if(g[i][j] != (LLONG_MIN >> 2))
                    for(l = 0; l < K; l ++)
                        if(~i & (1 << l))
                        {
                            p = f[j].s[l];
                            s = f[p].g;
                            g[i | (1 << l)][h[t][p].first] = max(g[i | (1 << l)][h[t][p].first], g[i][j] + s + h[t][p].second);
                        }

    for(i = 0, s = LLONG_MIN >> 2; i < (1 << K); i ++)
        if(__builtin_popcount(i) == m)
            for(j = 0; j < c; j ++)
                s = max(s, g[i][j]);
    printf("%I64d\n", s);

    return 0;
}
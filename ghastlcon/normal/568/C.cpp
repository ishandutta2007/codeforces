#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <bitset>
#define N 502
using namespace std;

char s[N];
vector<int> e[2][N];
bool a[N], o[N];
int b[N];
vector<vector<int> > c;
bitset<N> f[N];

void Tarjan(int x)
{
    static int d[N], l[N];
    static bool u[N];
    static int k;
    static vector<int> v;
    int i;

    if(d[x])
        return;
    d[x] = l[x] = ++ k;
    u[x] = true;
    v.push_back(x);

    for(i = 0; i < (signed)e[0][x].size(); i ++)
        if(!d[e[0][x][i]])
        {
            Tarjan(e[0][x][i]);
            l[x] = min(l[x], l[e[0][x][i]]);
        }
        else if(u[e[0][x][i]])
            l[x] = min(l[x], d[e[0][x][i]]);

    if(d[x] == l[x])
    {
        c.push_back(vector<int>());
        do
        {
            i = v.back();
            v.pop_back();
            u[i] = false;
            b[i] = (int)c.size() - 1;
            c.back().push_back(i);
        }
        while(x != i);
    }

    return;
}

void DFS(int x)
{
    static bitset<N> g[N];
    static bool u[N];
    int i;

    if(u[x])
        return;
    u[x] = true;

    for(i = 0; i < (signed)c[x].size(); i ++)
        g[x].set(c[x][i]);
    for(i = 0; i < (signed)e[1][x].size(); i ++)
    {
        DFS(e[1][x][i]);
        g[x] |= g[e[1][x][i]];
    }
    for(i = 0; i < (signed)c[x].size(); i ++)
        f[c[x][i]] = g[x];

    return;
}

bool Valid(int n, bitset<N> &g, bitset<N> &h)
{
    int i;

    for(i = 1; i <= n; i ++)
        if((g.test(i) && h.test(i + n)) || (g.test(i + n) && h.test(i)))
            return false;

    return true;
}

bool Check(int l, int n, bitset<N> &g, bitset<N> &h)
{
    int i, v;

    g.reset();
    h.reset();
    for(i = 1; i <= l; i ++)
    {
        v = i + a[s[i] - 97] * n;
        g.set(v);
        h |= f[v];
    }

    return Valid(n, g, h);
}

int main(void)
{
    int n, m, l, u, v;
    int i, j, k, p, t[2];
    char x, y;
    bitset<N> g, h, d;

    for(l = 0; (i = getchar()) == 'V' || i == 'C'; a[l ++] = i == 'C')
        ;
    scanf("%d %d", &n, &m);
    while(m --)
    {
        scanf("%d %c %d %c", &u, &x, &v, &y);
        e[0][u + (x == 'C') * n].push_back(v + (y == 'C') * n);
        e[0][v + (y == 'V') * n].push_back(u + (x == 'V') * n);
    }
    scanf("%s", s + 1);

    for(i = 1; i <= n + n; i ++)
        Tarjan(i);
    for(i = 1; i <= n + n; i ++)
        for(j = 0; j < (signed)e[0][i].size(); j ++)
            if(b[i] != b[e[0][i][j]])
                e[1][b[i]].push_back(b[e[0][i][j]]);
    for(i = 0; i < (signed)c.size(); i ++)
        DFS(i);
    // for(i=1;i<=n+n;i++){for(j=1;j<=n+n;j++)cout<<f[i][j]<<' ';cout<<endl;}

    if(Check(n, n, g, h))
    {
        printf("%s\n", s + 1);

        return 0;
    }

    t[0] = t[1] = l;
    for(i = 0; i < l; i ++)
        t[a[i]] = min(t[a[i]], i);

    for(i = n - 1; i >= 0; i --)
        for(j = s[i + 1] + 1; j < l + 97; j ++)
        {
            s[i + 1] = (char)j;
            if(Check(i + 1, n, g, h))
            {
                // printf("enter %d\n", i);
                for(k = i + 2; k <= n; k ++)
                {
                    if(t[0] < t[1])
                    {
                        for(p = 0; p <= 1; p ++)
                            if(t[p] < l)
                            {
                                g.set(k + p * n);
                                g.reset(k + !p * n);
                                d = h | f[k + p * n];
                                if(Valid(n, g, d))
                                    break;
                            }
                    }
                    else
                        for(p = 1; p >= 0; p --)
                            if(t[p] < l)
                            {
                                g.set(k + p * n);
                                g.reset(k + !p * n);
                                d = h | f[k + p * n];
                                if(Valid(n, g, d))
                                    break;
                            }

                    if(p == -1 || p == 2)
                        break;
                    h |= f[k + p * n];
                    o[k] = p;
                }

                if(k > n)
                {
                    // printf("fetch %d\n",i+1);
                    for(k = 1; k <= i + 1; k ++)
                        printf("%c", s[k]);
                    for(k = i + 2; k <= n; k ++)
                        printf("%c", t[o[k]] + 97);
                    printf("\n");

                    return 0;
                }
            }
        }
    printf("-1\n");

    return 0;
}
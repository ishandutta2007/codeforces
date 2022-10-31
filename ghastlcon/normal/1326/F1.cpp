#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define N 18
using namespace std;

char a[N][N];
long long f[N][1 << N | 1], g[N + 1][1 << N | 1], t[N + 1][1 << N | 1];
vector<int> v;
map<vector<int>, long long> h;

void FWT(long long *f, int n, int w)
{
    int i, j, l;

    for(l = 0; l < n; l ++)
        for(i = 0; i < (1 << n); i += 2 << l)
            for(j = 0; j < (1 << l); j ++)
                if(w == 1)
                    f[i + j + (1 << l)] += f[i + j];
                else
                    f[i + j] -= f[i + j + (1 << l)];

    return;
}

void DFS(int p, int n, int r, int m)
{
    int i, j;
    long long s;

    if(!r)
    {
        for(i = s = 0; i < (1 << n); i ++)
            s += (__builtin_parity((1 << n) - 1 - i) ? -1 : 1) * t[p][i];
        h[v] = s;
        // for(int xx:v)cout<<xx<<' ';cout<<endl;cout<<s<<endl;

        return;
    }

    for(i = m; i <= r; i ++)
    {
        v.push_back(i);
        for(j = 0; j < (1 << n); j ++)
            t[p + 1][j] = t[p][j] * g[i][j];
        DFS(p + 1, n, r - i, i);
        v.pop_back();
    }

    return;
}

int main(void)
{
    int n;
    int i, j, k;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%s", a[i]);

    for(i = 0; i < n; i ++)
        f[i][1 << i] = 1;
    for(i = 1; i < (1 << n); i ++)
        for(j = 0; j < n; j ++)
            if(f[j][i])
            {
                g[__builtin_popcount(i)][i] += f[j][i];
                for(k = 0; k < n; k ++)
                    if(~i & (1 << k) && a[j][k] == '1')
                        f[k][i | (1 << k)] += f[j][i];
            }
    for(i = 1; i <= n; i ++)
        FWT(g[i], n, 1);

    for(i = 0; i < (1 << n); i ++)
        t[0][i] = 1;
    DFS(0, n, n, 1);

    n --;
    for(i = 0; i < (1 << n); i ++)
    {
        v.clear();
        for(j = 0, k = 1; j <= n; j ++)
            if(~i & (1 << j))
            {
                v.push_back(k);
                k = 1;
            }
            else
                k ++;
        sort(v.begin(), v.end());
        t[0][i] = h[v];
    }
    
    FWT(t[0], n, -1);
    for(i = 0; i < (1 << n); i ++)
        printf("%I64d%c", t[0][i], " \n"[i == (1 << n) - 1]);

    return 0;
}
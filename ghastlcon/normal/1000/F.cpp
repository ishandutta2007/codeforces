#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 500020
using namespace std;

int n, a[N];
int f[N << 1], g[N], p[N];
vector<pair<int, int> > q[N];
int o[N];

void InitSegwin(void)
{
    int i;

    for(i = 0; i < (n << 1); i ++)
        f[i] = N;

    return;
}

void SetSegwin(int p, int x)
{
    for(f[p += n] = x; p >>= 1; )
        f[p] = min(f[p << 1], f[p << 1 | 1]);

    return;
}

int MinSegwin(int l, int r)
{
    int o;

    for(o = N, l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            o = min(o, f[l ++]);
        if(r & 1)
            o = min(o, f[-- r]);
    }

    return o;
}

int main(void)
{
    int m, l, r;
    int i, j, k;

    scanf("%d", &n);
    InitSegwin();
    for(i = 0; i < N; i ++)
        p[i] = -i;
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        g[i] = p[a[i]];
        p[a[i]] = i;        
    }
    // for(i = 0; i < n; i ++) cout << g[i] << ' '; cout << endl;

    scanf("%d", &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &l, &r);
        q[-- r].push_back(make_pair(-- l, i));
    }

    for(i = 0; i < n; i ++)
    {
        if(g[i] > -1)
            SetSegwin(g[i], N);
        SetSegwin(i, g[i]);

        for(j = 0; j < (signed)q[i].size(); j ++)
        {
            k = q[i].at(j).second;
            o[k] = MinSegwin(q[i].at(j).first, i);
            if(o[k] < 0)
                o[k] = -o[k];
            else if(o[k] != N && o[k] < q[i].at(j).first)
                o[k] = a[o[k]];
            else
                o[k] = 0;
        }
    }

    for(i = 0; i < m; i ++)
        printf("%d\n", o[i]);

    return 0;
}
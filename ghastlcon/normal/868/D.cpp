#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#define N 220
#define M 100020
using namespace std;

class Node
{
public:
    int s[2];
    int f;
    int l;

    Node(void) : f(-1), l(0)
    {
        s[0] = s[1] = 0;

        return;
    }
};

string a[N];
int c, d;
Node f[M];

void InitSAM(void)
{
    int i;

    for(i = 0; i < c; i ++)
        f[i] = Node();
    c = 1;
    d = 0;

    return;
}

void InsertSAM(int k)
{
    int p, b, q;

    p = d;
    f[d = c ++].l = f[p].l + 1;
    for(; p != -1 && !f[p].s[k]; p = f[p].f)
        f[p].s[k] = d;

    if(p == -1)
        f[d].f = 0;
    else
    {
        q = f[p].s[k];
        if(f[q].l == f[p].l + 1)
            f[d].f = q;
        else
        {
            f[b = c ++] = f[q];
            f[b].l = f[p].l + 1;
            f[d].f = f[q].f = b;

            for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                f[p].s[k] = b;
        }
    }

    return;
}

bool CheckSAM(int x, int l)
{
    int i, p, t;

    for(i = p = 0; i < l; i ++)
    {
        t = x >> i & 1;
        if(f[p].s[t])
            p = f[p].s[t];
        else
            return false;
    }

    return true;
}

int main(void)
{
    int n, m, u, v;
    int i, j, s, l;

    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < n; i ++)
        cin >> a[i];

    cin >> m;
    for(i = n; i < n + m; i ++)
    {
        cin >> u >> v;
        a[i] = a[-- u] + a[-- v];
        if(a[i].size() > 50000)
            a[i] = a[i].substr(0, 25000) + a[i].substr(a[i].size() - 25000, 25000);

        InitSAM();
        for(j = 0; j < (signed)a[i].size(); j ++)
            InsertSAM(a[i][j] - 48);

        for(l = 1; true; l ++)
        {
            for(s = 0; s < (1 << l); s ++)
                if(!CheckSAM(s, l))
                    break;
            if(s < (1 << l))
                break;
        }
        cout << l - 1 << endl;
    }

    return 0;
}
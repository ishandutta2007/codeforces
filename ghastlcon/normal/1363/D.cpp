#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <numeric>
#define N 1020
using namespace std;

vector<int> f[N];
int o[N];

int Query(vector<int> v)
{
    int i;

    cout << "? " << v.size() << ' ';
    for(i = 0; i < (signed)v.size(); i ++)
        cout << v[i] << " \n"[i == (signed)v.size() - 1];
    cout.flush();
    cin >> i;

    return i;
}

void Answer(int *o, int n)
{
    int i;
    string t;

    cout << "! ";
    for(i = 1; i <= n; i ++)
        cout << o[i] << " \n"[i == n];
    cout.flush();
    cin >> t;

    return;
}

int BSFind(int v, int n)
{
    int l, m, r;
    vector<int> k;

    for(l = 0, r = n; l + 1 < r; )
    {
        m = (l + r) >> 1;
        k.resize(m);
        iota(k.begin(), k.end(), 1);
        if(Query(k) >= v)
            r = m;
        else
            l = m;
    }

    return r;
}

int main(void)
{
    int t, n, m, l;
    int i, j, v, p;
    vector<int> k;

    cin >> t;
    while(t --)
    {
        for(i = 0; i < N; i ++)
            f[i].clear();

        cin >> n >> m;
        for(i = 1; i <= m; i ++)
        {
            cin >> l;
            f[i].resize(l);
            for(j = 0; j < l; j ++)
                cin >> f[i][j];
        }

        k.resize(n);
        iota(k.begin(), k.end(), 1);
        v = Query(k);
        p = BSFind(v, n);
        // printf("max %d, val %d\n", p, v);

        for(i = 1; i <= m; i ++)
            if(find(f[i].begin(), f[i].end(), p) == f[i].end())
                o[i] = v;
            else
            {
                k.clear();
                for(j = 1; j <= n; j ++)
                    if(find(f[i].begin(), f[i].end(), j) == f[i].end())
                        k.push_back(j);
                o[i] = Query(k);
            }
        Answer(o, m);
    }

    return 0;
}
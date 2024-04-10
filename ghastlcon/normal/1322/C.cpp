#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define N 500020
using namespace std;

long long a[N];
vector<int> e[N];

int main(void)
{
    int t, n, m, u, v;
    int i;
    long long o;
    map<vector<int>, long long> f;
    map<vector<int>, long long>::iterator j;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; i ++)
        {
            e[i].clear();
            scanf("%I64d", &a[i]);
        }
        while(m --)
        {
            scanf("%d %d", &u, &v);
            e[v].push_back(u);
        }

        f.clear();
        for(i = 1; i <= n; i ++)
        {
            sort(e[i].begin(), e[i].end());
            f[e[i]] += a[i];
        }

        o = 0;
        for(j = f.begin(); j != f.end(); j ++)
            if(!j -> first.empty())
                o = __gcd(o, j -> second);
        printf("%I64d\n", o);
    }

    return 0;
}
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <tuple>
#define N 300020
using namespace std;

long long a[N];
map<vector<tuple<int, int, int> >, int> f;
vector<tuple<int, int, int> > g[N], v;

inline int Mex(int x, int y, int z)
{
    if(x && y && z)
        return 0;
    if(x != 1 && y != 1 && z != 1)
        return 1;

    return 3 - (x != 2 && y != 2 && z != 2);
}

inline int Switch(tuple<int, int, int> x, int k)
{
    return !k ? get<0>(x) : k == 1 ? get<1>(x) : get<2>(x);
}

inline int SG(long long n, int k)
{
    return n < f[v] ? Switch(g[n].back(), k) : Switch(g[(n - f[v]) % (f.size() - f[v]) + f[v]].back(), k);
}

int main(void)
{
    int t, n, x, y, z;
    int i, s, o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d %d %d", &n, &x, &y, &z);
        for(i = 0; i < n; i ++)
            scanf("%I64d", &a[i]);

        f.clear();
        v.clear();
        v.push_back(make_tuple(0, 0, 0));
        for(i = 1; i < 5 || !f.count(v); i ++)
        {
            f[v] = i - 1;
            g[i - 1] = v;
            v.push_back(make_tuple(Mex(get<0>(v[max(0, (signed)v.size() - x)]), get<1>(v[max(0, (signed)v.size() - y)]), get<2>(v[max(0, (signed)v.size() - z)])), Mex(get<0>(v[max(0, (signed)v.size() - x)]), -1, get<2>(v[max(0, (signed)v.size() - z)])), Mex(get<0>(v[max(0, (signed)v.size() - x)]), get<1>(v[max(0, (signed)v.size() - y)]), -1)));
            if(i >= 5)
                v.erase(v.begin());
            // printf("%d:\n",i);
            // for(int j=0;j<(signed)v.size();j++)printf("[%d,%d,%d] ",get<0>(v[j]),get<1>(v[j]),get<2>(v[j]));puts("");
        }

        for(i = s = 0; i < n; i ++)
            s ^= SG(a[i], 0);
        for(i = o = 0; i < n; i ++)
        {
            if(!(s ^ SG(a[i], 0) ^ SG(max(0LL, a[i] - x), 0)))
                o ++;
            if(!(s ^ SG(a[i], 0) ^ SG(max(0LL, a[i] - y), 1)))
                o ++;
            if(!(s ^ SG(a[i], 0) ^ SG(max(0LL, a[i] - z), 2)))
                o ++;
        }
        printf("%d\n", o);
    }

    return 0;
}
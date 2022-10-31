#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#include <functional>
#define N 100020
using namespace std;

int a[N];
pair<int, int> c[N];
tuple<int, int, int> b[N];
vector<pair<int, int> > f[N];

int main(void)
{
    int k, n, m;
    int i, j;
    double s;
    vector<pair<double, int> > g;
    vector<int> o[3];

    scanf("%d %d %d", &k, &n, &m);
    for(i = 1; i <= k; i ++)
        scanf("%d", &a[i]);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d %d %d", &get<0>(b[i]), &get<1>(b[i]), &get<2>(b[i]));
        if(get<0>(b[i]) == 1)
            c[get<1>(b[i])] = max(c[get<1>(b[i])], make_pair(get<2>(b[i]), i));
        else if(get<0>(b[i]) == 2)
            f[get<1>(b[i])].push_back(make_pair(get<2>(b[i]), i));
        else
            g.push_back(make_pair(get<2>(b[i]), i));
    }

    for(i = 1; i <= k; i ++)
    {
        if(c[i].first > a[i])
            f[i].push_back(make_pair(c[i].first - a[i], c[i].second));

        sort(f[i].begin(), f[i].end(), greater<pair<int, int> >());
        for(j = 0, s = a[i]; j < (signed)f[i].size(); j ++)
        {
            g.push_back(make_pair((s + f[i][j].first) / s, f[i][j].second));
            s += f[i][j].first;
        }
    }

    sort(g.begin(), g.end(), greater<pair<double, int> >());
    if((int)g.size() > m)
        g.erase(g.begin() + m, g.end());

    printf("%d\n", (int)g.size());
    for(i = 0; i < (signed)g.size(); i ++)
        o[get<0>(b[g[i].second]) - 1].push_back(g[i].second);
    for(i = 0; i < (signed)o[0].size(); i ++)
        printf("%d ", o[0][i]);
    for(i = 0; i < (signed)o[1].size(); i ++)
        printf("%d ", o[1][i]);
    for(i = 0; i < (signed)o[2].size(); i ++)
        printf("%d ", o[2][i]);
    printf("\n");


    return 0;
}
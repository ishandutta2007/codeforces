#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
typedef long double ld;

struct edge {
    int a,b,p,idx;
} ed[312345];

int l[312345],r[312345];

vector<edge> g[312345];
map< pair<int,int>, int> mp;

int n,a,b,p,q,x,y,z;
ld res1;

int dfs(int cura, int curb) {
    int idx = mp[make_pair(cura, curb)];
    int cnt = 1;
    for (int i = 0; i < g[cura].size(); ++i) {
        if (g[cura][i].b == curb) continue;
        cnt += dfs(g[cura][i].b, cura);
    }
    l[idx] = cnt;
    r[idx] = n - cnt;
    return cnt;
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n-1; ++i) {
        ed[i].idx = i;
        scanf("%d%d%d",&a,&b,&p);
        ed[i].a = a;
        ed[i].b = b;
        ed[i].p = p;
        g[a].push_back(ed[i]);
        swap(ed[i].a, ed[i].b);
        g[b].push_back(ed[i]);
        swap(ed[i].a, ed[i].b);
        mp[make_pair(a,b)] = mp[make_pair(b,a)] = i;
    }

    dfs(ed[0].a, ed[0].b);
    //for (int i = 0; i < 312345; ++i)
    //    r[i] = l[i], l[i] = 0;
    dfs(ed[0].b, ed[0].a);

    for (int i = 0; i < n-1; ++i) {
        res1 += ld(l[i]) * ld(r[i]) * ld(ed[i].p);
    }

    scanf("%d",&q);
    while (q--) {
        scanf("%d%d",&x,&z);
        --x;
        int idx = x;
        res1 -= ld(l[idx]) * ld(r[idx]) * ld(ed[idx].p);
        ed[idx].p = z;
        res1 += ld(l[idx]) * ld(r[idx]) * ld(ed[idx].p);
        ld res2 = res1 / (ld(n) * ld(n-1) * ld(n-2) / ld(6));
        res2 *= ld(n - 2);
        printf("%.17lf\n",(double)res2);
    }

    return 0;
}
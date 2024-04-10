#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define INF ((ll)9e18)
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[1000105];
int n,root,a[1000105],p[1000105];
ll d[1000105][2];
ll ans;

void dfs(int v, int pr) {
    ///cerr << v << " " << pr << endl;
    ll curans = 0ll;
    int curodd = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == pr) continue;
        dfs(to, v);
        if (d[to][0] > d[to][1]) curans += d[to][0];
        else curans += d[to][1], ++curodd;
    }

    if (curodd % 2) {
        d[v][1] = max(d[v][1], curans);
        ll mindelta = 9e18;
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (to == pr) continue;
            if (d[to][0] == -INF || d[to][1] == -INF) continue;
            ll zzz = d[to][0] - d[to][1];
            if (zzz < 0) zzz = -zzz;
            mindelta = min(mindelta, zzz);
        }
        curans -= mindelta;
        d[v][0] = max(d[v][0], curans), d[v][1] = max(d[v][1], curans + (ll)a[v]);
    }
    else d[v][0] = max(d[v][0], curans), d[v][1] = max(d[v][1], curans + (ll)a[v]);
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d",&p[i],&a[i]);
        if (p[i] == -1) root = i;
        else {
            g[p[i]].push_back(i);
            g[i].push_back(p[i]);
        }
    }

    for (int i = 0; i < 1000105; ++i)
        d[i][0] = d[i][1] = -INF;

    dfs(root, -1);

    for (int i = 1; i <= n; ++i)
        ans = max(ans, max(d[i][0], d[i][1]));
    cout << ans;

    return 0;
}
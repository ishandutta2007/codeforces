#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,m,ans,a[100005],x,y;
vector<int> g[100005];

void dfs(int v, int p, int cur) {
    if (a[v]) cur += 1;
    else cur = 0;
    if (cur > m) return;
    for (int i = 0; i < g[v].size(); ++i)
        if (g[v][i] != p) dfs(g[v][i], v, cur);
    if (cur <= m && g[v].size() == 1 && g[v][0] == p) ++ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i+1];
    for (int i = 0; i<n-1; ++i) cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
    dfs(1, -1, 0); cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,q,x,y,z,u[105];
vector< pii > g[105];

void dfs(int v, int p, int color) {
    if (u[v]) return;
    u[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i].second == color && g[v][i].first != p)
            dfs(g[v][i].first, v, color);
    }
}

int main()
{
    cin >> n >> m;
    while (m--) {
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y,z));
        g[y].push_back(make_pair(x,z));
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        int ans = 0;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 0; j < 105; ++j) u[j] = 0;
            dfs(x,x,i);
            ans += u[y];
        }
        cout << ans << "\n";
    }

    return 0;
}
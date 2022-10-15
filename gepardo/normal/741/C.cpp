#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector < pair <int, int> > ps;
vector < vector <int> > g;
vector <int> ans;
int cnt = 0;

void dfs(int v) {
    ans[v] = ((cnt++) & 1) + 1;
    for (int to: g[v])
        if (ans[to] < 0)
            dfs(to);
}

int main() {
    ios_base::sync_with_stdio(false);
    int m; cin >> m;
    n = 2 * m;
    g.resize(n);
    ans.assign(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        ps.emplace_back(a, b);
        g[2*i].push_back(2*i + 1);
        g[2*i + 1].push_back(2*i);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        if (ans[i] < 0)
            dfs(i);
    for (int i = 0; i < m; i++)
        cout << ans[ps[i].first] << " " << ans[ps[i].second] << "\n";
    return 0;
}
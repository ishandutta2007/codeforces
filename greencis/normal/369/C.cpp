#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, y, z;
vector<pii> g[100105];
vector<int> ans;

bool dfs(int v, int p = -1, bool p_bad = false) {
    bool good = false;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i].first;
        if (to == p)
            continue;
        good |= dfs(to, v, g[v][i].second == 2);
    }
    if (good)
        return true;
    if (p_bad) {
        ans.push_back(v);
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }

    dfs(1);
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}
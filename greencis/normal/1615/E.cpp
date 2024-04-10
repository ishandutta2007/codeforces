#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

vector<int> g[200200];
int dep[200200];
vector<int> leaves;
vector<pii> sortedSons[200200];

int dfs(int v, int depth = 1, int pred = -1) {
    dep[v] = depth;
    int ans = dep[v];
    for (int to : g[v]) {
        if (to == pred)
            continue;
        int cur = dfs(to, depth + 1, v);
        sortedSons[v].emplace_back(cur, to);
        ans = max(ans, cur);
    }
    sort(all(sortedSons[v]), [&](const pii& a, const pii& b) {
        return a.first > b.first;
    });
    return ans;
}

void dfs2(int v, int baseDepth = 0, int pred = -1) {
    if (sortedSons[v].empty()) {
        leaves.push_back(dep[v] - baseDepth);
        return;
    }
    for (int i = 0; i < (int)sortedSons[v].size(); ++i) {
        int to = sortedSons[v][i].second;
        dfs2(to, i == 0 ? baseDepth : dep[v], v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    dfs2(1);

    sort(all(leaves), greater<>());
    ll ans = -1e18;
    int occupied = 0;
    for (int i = 0; i <= k; ++i) {
        ll cur = i * ll(n - i);
        ll blue = min(n / 2, n - occupied);
        cur -= blue * (n - blue);
        ans = max(ans, cur);
        if (i < (int)leaves.size())
            occupied += leaves[i];
    }
    cout << ans << endl;
}
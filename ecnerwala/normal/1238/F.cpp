#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
vector<int> adj[MAXN];

int ans;
int dfs(int cur, int prv) {
    int ownVal = int(adj[cur].size()) - 1;
    ans = max(ans, ownVal + 2);
    for (int nxt : adj[cur]) {
        if (nxt == prv) continue;
        int chVal = dfs(nxt, cur);
        ans = max(ans, ownVal + chVal + 2);
        ownVal = max(ownVal, chVal + int(adj[cur].size()) - 1);
    }
    return ownVal;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Q; cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0; i < N-1; i++) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = 1;
        dfs(0, -1);
        cout << ans << '\n';
        for (int i = 0; i < N; i++) adj[i] = {};
    }
    return 0;
}
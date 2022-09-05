#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, vis[maxn];
vector<int> ans, V, G[maxn];
set<int> S, T;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        T.insert(i);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int cnt = 0;
        queue<int> q; q.push(i);
        while (!q.empty()) {
            S.clear(), V.clear();
            int v = q.front(); q.pop();
            for (int j : G[v]) {
                S.insert(j);
            }
            for (int j : T) if (!S.count(j)) {
                cnt++, vis[j] = 1, V.push_back(j);
            }
            for (int j : V) {
                T.erase(j), q.push(j);
            }
        }
        ans.push_back(cnt);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    return 0;
}
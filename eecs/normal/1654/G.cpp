#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, l[maxn], d[maxn], ans[maxn], f[maxn];
vector<int> G[maxn], cand[maxn];

int main() {
    scanf("%d", &n);
    memset(d, -1, sizeof(d));
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &l[i]);
        if (l[i]) Q.push(i), d[i] = 0;
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) if (!~d[v]) {
            Q.push(v), d[v] = d[u] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = d[i];
        bool flag = 0;
        for (int j : G[i]) flag |= d[i] == d[j];
        if (flag) cand[d[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) if (!cand[i].empty()) {
        memset(f, 0x3f, sizeof(f));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
        for (int x : cand[i]) {
            Q.emplace(f[x] = 0, x);
        }
        while (!Q.empty()) {
            auto p = Q.top(); Q.pop();
            int u = p.second;
            if (p.first ^ f[u]) continue;
            f[u] = max(f[u], 0);
            for (int v : G[u]) if (d[u] <= d[v]) {
                int w = max(0, f[u] + (d[u] == d[v] ? 1 : -1));
                if (f[v] > w) Q.emplace(f[v] = w, v);
            }
        }
        for (int j = 1; j <= n; j++) {
            if (!f[j]) ans[j] = min(ans[j], i);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", 2 * d[i] - ans[i]);
    }
    return 0;
}
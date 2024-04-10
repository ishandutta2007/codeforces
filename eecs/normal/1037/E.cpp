#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, K, u[maxn], v[maxn], ans[maxn], d[maxn];
bool del[maxn];
vector<pair<int, int>> G[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]);
        d[u[i]]++, d[v[i]]++;
        G[u[i]].emplace_back(v[i], i), G[v[i]].emplace_back(u[i], i);
    }
    for (int i = 1; i <= n; i++) {
        Q.emplace(d[i], i);
    }
    int tot = n;
    for (int i = m; i; i--) {
        while (!Q.empty() && Q.top().first < K) {
            int x = Q.top().second; Q.pop();
            if (del[x]) continue;
            del[x] = 1, tot--;
            for (auto &e : G[x]) if (e.second <= i && !del[e.first]) {
                Q.emplace(--d[e.first], e.first);
            }
        }
        ans[i] = tot;
        if (!del[u[i]] && !del[v[i]]) Q.emplace(--d[u[i]], u[i]), Q.emplace(--d[v[i]], v[i]);
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
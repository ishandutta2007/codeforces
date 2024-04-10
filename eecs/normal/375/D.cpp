#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, c[maxn], ans[maxn];
map<int, int> S[maxn], cnt[maxn];
vector<int> G[maxn];
vector<pair<int, int>> Q[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1, v, k; i <= m; i++) {
        scanf("%d %d", &v, &k), Q[v].emplace_back(k, i);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        S[v][c[v]]++, cnt[v][1]++;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v);
            if (S[u].size() > S[v].size()) swap(S[u], S[v]), swap(cnt[u], cnt[v]);
            for (auto p : S[u]) {
                if (!--cnt[v][S[v][p.first]]) cnt[v].erase(S[v][p.first]);
                cnt[v][S[v][p.first] += p.second]++;
            }
        }
        for (auto p : Q[v]) {
            for (auto q : cnt[v]) {
                if (q.first >= p.first) ans[p.second] += q.second;
            }
        }
    };
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
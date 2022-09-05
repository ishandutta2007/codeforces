#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, a[maxn], all[maxn], f[maxn];
multiset<int> S[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int _ = 1, u, v; _ < n; _++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    auto chk = [&](int x) {
        function<void(int, int)> dfs1 = [&](int v, int fa) {
            f[v] = 1, all[v] = 0, S[v].clear();
            for (int u : G[v]) if (u ^ fa) {
                dfs1(u, v);
                if (a[u] >= x) {
                    if (all[u]) all[v]++, S[v].insert(f[u]);
                    else f[v] += f[u];
                } else {
                    all[v]++;
                }
            }
            if (a[v] < x) f[v] = 0, all[v] = n + 1;
            else if (!S[v].empty()) f[v] += *S[v].rbegin();
        };
        dfs1(1, 0);
        bool flag = 0;
        function<void(int, int)> dfs2 = [&](int v, int fa) {
            if (a[v] >= x && f[v] >= K) flag = 1;
            for (int u : G[v]) if (u ^ fa) {
                if (all[u]) all[v]--;
                if (a[v] >= x && !S[v].empty()) f[v] -= *S[v].rbegin();
                if (a[u] >= x) {
                    if (all[u]) S[v].erase(S[v].find(f[u]));
                    else f[v] -= f[u];
                }
                if (a[v] >= x && !S[v].empty()) f[v] += *S[v].rbegin();
                if (a[u] >= x && !S[u].empty()) f[u] -= *S[u].rbegin();
                if (all[v]) all[u]++;
                if (a[v] >= x) {
                    if (all[v]) S[u].insert(f[v]);
                    else f[u] += f[v];
                }
                if (a[u] >= x && !S[u].empty()) f[u] += *S[u].rbegin();
                dfs2(u, v);
                if (a[u] >= x && !S[u].empty()) f[u] -= *S[u].rbegin();
                if (all[v]) all[u]--;
                if (a[v] >= x) {
                    if (all[v]) S[u].erase(S[u].find(f[v]));
                    else f[u] -= f[v];
                }
                if (a[u] >= x && !S[u].empty()) f[u] += *S[u].rbegin();
                if (a[v] >= x && !S[v].empty()) f[v] -= *S[v].rbegin();
                if (all[u]) all[v]++;
                if (a[u] >= x) {
                    if (all[u]) S[v].insert(f[u]);
                    else f[v] += f[u];
                }
                if (a[v] >= x && !S[v].empty()) f[v] += *S[v].rbegin();
            }
        };
        dfs2(1, 0);
        return flag;
    };
    int l = 1, r = 1000000, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
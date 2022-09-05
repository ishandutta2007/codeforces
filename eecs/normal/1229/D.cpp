#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, tot, perm[5], mp[3200], p[120][5], q[120][120];
bool vis[120];
long long ans;
queue<int> Q;

int main() {
    scanf("%d %d", &n, &K);
    iota(perm, perm + K, 0);
    do {
        int h = 0;
        for (int i = 0; i < K; i++) h = h * K + (p[tot][i] = perm[i]);
        mp[h] = tot++;
    } while (next_permutation(perm, perm + K));
    for (int i = 0; i < tot; i++) {
        for (int j = 0; j < tot; j++) {
            static int tmp[5];
            for (int k = 0; k < K; k++) tmp[p[i][k]] = p[j][k];
            int h = 0;
            for (int k = 0; k < K; k++) h = h * K + tmp[k];
            q[i][j] = mp[h];
        }
    }
    vector<pair<int, int>> lst;
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        int h = 0;
        for (int j = 0, x; j < K; j++) {
            scanf("%d", &x), h = h * K + x - 1;
        }
        h = mp[h];
        for (int j = 0; j < lst.size(); j++) if (lst[j].second == h) {
            lst.erase(lst.begin() + j); break;
        }
        lst.emplace_back(i, h);
        memset(vis, 0, sizeof(vis)), V.clear();
        int cur = 0;
        for (int j = lst.size() - 1; ~j; j--) {
            int k = lst[j].first, h = lst[j].second;
            if (vis[h]) { ans += cur * (k - (j ? lst[j - 1].first : 0)); continue; }
            Q.push(h), V.push_back(h), vis[h] = 1;
            while (!Q.empty()) {
                int v = Q.front(); Q.pop(), cur++;
                for (int u : V) {
                    if (!vis[q[u][v]]) Q.push(q[u][v]), vis[q[u][v]] = 1;
                    if (!vis[q[v][u]]) Q.push(q[v][u]), vis[q[v][u]] = 1;
                }
            }
            ans += cur * (k - (j ? lst[j - 1].first : 0));
        }
    }
    printf("%lld\n", ans);
    return 0;
}
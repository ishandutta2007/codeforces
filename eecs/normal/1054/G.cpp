#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int T, n, m, vis[maxn], cnt[maxn];
char s[maxn];
bitset<maxn> b[maxn];
queue<pair<int, int>> Q;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            b[i].reset(), vis[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%s", s + 1), cnt[i] = 0;
            for (int j = 1; j <= n; j++) {
                if (s[j] == '1') cnt[i]++;
            }
            if (cnt[i] == 1) continue;
            for (int j = 1; j <= n; j++) {
                if (s[j] == '1') b[j].set(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) if (i ^ j) {
                if ((b[i] & b[j]) == b[i]) Q.emplace(i, j);
            }
        }
        vector<pair<int, int>> E;
        while (!Q.empty()) {
            int u = Q.front().first, v = Q.front().second; Q.pop();
            if (vis[u] || vis[v]) continue;
            vis[u] = 1, E.emplace_back(u, v);
            for (int i = 1; i <= m; i++) {
                if (b[u][i]) cnt[i]--;
            }
            for (int i = 1; i <= m; i++) if (cnt[i] == 1) {
                cnt[i] = 0;
                for (int j = 1; j <= n; j++) if (b[j][i] && !vis[j]) {
                    b[j][i] = 0;
                    for (int k = 1; k <= n; k++) if (j ^ k && !vis[k]) {
                        if ((b[j] & b[k]) == b[j]) Q.emplace(j, k);
                    }
                }
            }
        }
        if (E.size() < n - 1) { puts("NO"); continue; }
        puts("YES");
        for (auto p : E) {
            printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int t, n, m;
vector < int > e[200010];
int tag[200010], ans;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) e[i].clear(), tag[i] = 0;
        ans = 0;
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) {
            if (tag[i] == 2) ans++;
            else for (auto j : e[i]) tag[j] = max(tag[j], tag[i] + 1);
        }
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++) if (tag[i] == 2) printf("%d ", i);
        puts("");
    }
}
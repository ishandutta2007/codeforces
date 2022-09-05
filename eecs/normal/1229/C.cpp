#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, q, a[maxn], num[maxn], sz[maxn];
vector<int> G[maxn], H[maxn];
long long ans;

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        sz[u]++, sz[v]++;
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        for (int j : G[i]) {
            if (j < i) num[i]++;
            else H[i].push_back(j);
        }
        ans += 1LL * num[i] * (sz[i] - num[i]);
    }
    printf("%lld\n", ans);
    scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        for (int y : H[x]) {
            ans += 2 * num[y] - sz[y] - 1, num[y]--;
            H[y].push_back(x);
        }
        ans += 1LL * num[x] * (num[x] - sz[x]);
        a[x] = ++n, num[x] = G[x].size();
        H[x].clear();
        printf("%lld\n", ans);
    }
    return 0;
}
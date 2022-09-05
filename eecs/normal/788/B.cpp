#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, fa[maxn], mark[maxn];
vector<int> G[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    iota(fa + 1, fa + n + 1, 1);
    int num = 0, fir = 0;
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        if (u == v) { num++, mark[u] = 1; continue; }
        G[u].push_back(v), G[v].push_back(u);
        fa[find(u)] = find(v);
    }
    for (int i = 1; i <= n; i++) if (!G[i].empty() || mark[i]) {
        if (!fir) fir = i;
        else if (find(fir) ^ find(i)) puts("0"), exit(0);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) if (!G[i].empty()) {
        ans += 1LL * G[i].size() * (G[i].size() - 1) / 2;
    }
    ans += 1LL * num * (num - 1) / 2 + 1LL * num * (m - num);
    printf("%lld\n", ans);
    return 0;
}
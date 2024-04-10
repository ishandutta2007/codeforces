#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
int n, sz[maxn], cnt[maxn];
vector<int> G[maxn];
bitset<maxn> A;
long long ans;

int go(int u, int fa) {
    for (int v : G[u]) if (v ^ fa) {
        if (sz[v] > n / 2) return go(v, u);
    }
    return u;
}

void work(int x, int cnt) {
    A |= A << x;
    int y = 1, res = cnt - 1;
    while (y * 2 - 1 < res) {
        y <<= 1;
        A |= A << (x * y);
        res -= y;
    }
    if (res) A |= A << (x * res);
}

int main() {
    scanf("%d", &n);
    for (int i = 2, p; i <= n; i++) {
        scanf("%d", &p);
        G[p].push_back(i), G[i].push_back(p);
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
        sz[u] = 1;
        for (int v : G[u]) if (v ^ fa) {
            self(self, v, u), sz[u] += sz[v];
        }
    };
    dfs(dfs, 1, 0);
    int r = go(1, 0);
    dfs(dfs, r, 0);
    for (int i = 1; i <= n; i++) {
        ans += sz[i];
    }
    for (auto x : G[r]) cnt[sz[x]]++;
    A.reset();
    A[0] = 1;
    for (int i = 1; i <= n - 1; i++) {
        if (cnt[i]) work(i, cnt[i]);
    }
    int best = 0;
    for (int i = 1; i <= (n - 1) / 2; i++)
        if (A[i]) best = i;
    ans += 1ll * best * (n - 1 - best);
    printf("%lld\n", ans);
    return 0;
}
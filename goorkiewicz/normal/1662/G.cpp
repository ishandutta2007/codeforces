#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int S = 500'001;

int n;
int sz[N];
int parent[N];

int coins[N];
bitset <S> dp;
vector <int> G[N], T[N];

int dfs(int u, int p = -1)
{
    sz[u] = 1;
    for (auto v: T[u]) {
        if (v != p) {
            sz[u] += dfs(v, u);
        }
    }

    return sz[u];
}

void update(int v)
{
    dp |= dp << v;
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int p;
        scanf("%d", &p);

        parent[i] = p;
        G[p].push_back(i);

        T[i].push_back(p);
        T[p].push_back(i);
    }

    for (int i = n; i >= 1; --i) {
        sz[i] = 1;
        for (auto v: G[i]) {
            sz[i] += sz[v];
        }
    }

    int half = (n + 1) / 2;
    int best = 1;

    for (int i = 1; i <= n; ++i) {
        if (sz[i] >= half && sz[i] < sz[best]) {
            best = i;
        }
    }

    bool two_cen = sz[best] * 2 == n;
    dfs(best);

    if (two_cen) {
        long long ans = 1LL * n * n / 4;
        for (int i = 1; i <= n; ++i) {
            ans += sz[i];
        }

        ans -= n / 2;
        printf("%lld\n", ans);
        exit(0);
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += sz[i];
    }

    for (auto v: T[best]) {
        coins[sz[v]]++;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int cur = 1;
        while (coins[i] > 0) {
            if (coins[i] < cur) {
                update(coins[i] * i);
            } else {
                update(cur * i);
            }

            coins[i] -= cur;
            cur *= 2;
        }
    }

    half = n / 2;
    for (int i = half; i >= 1; --i) {
        if (dp[i]) {
            ans += 1LL * i * (n - i - 1);
            break;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
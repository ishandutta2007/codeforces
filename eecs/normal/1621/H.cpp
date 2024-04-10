#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, K, T, q, top[maxn];
char z[maxn];
ll dist[maxn], ok[maxn], pass[26], fine[26], lim[26], mn[maxn][26];
vector<array<int, 2>> G[maxn];
vector<array<int, 3>> cand[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w}), G[v].push_back({u, w});
    }
    scanf("%d %s", &K, z + 1);
    for (int i = 0; i < K; i++) {
        scanf("%lld", &pass[i]);
    }
    for (int i = 0; i < K; i++) {
        scanf("%lld", &fine[i]), lim[i] = pass[i] / fine[i] + 1;
    }
    scanf("%d %d", &T, &q);
    function<void(int, int)> dfs = [&](int u, int fa) {
        top[u] = z[u] == z[fa] ? top[fa] : fa;
        cand[u] = {{0, 0, 0}, {T, 0, 0}};
        for (int x = top[u]; x; x = top[x]) {
            ll l = dist[top[u]] - dist[x], r = dist[top[u]] - dist[top[x]];
            mn[u][z[x] - 'A'] = (r ? (r - 1) / T : -1) - (l ? (l - 1) / T : -1);
            cand[u].push_back({T - int(r ? (r - 1) % T : T - 1), z[x] - 'A', 1});
            cand[u].push_back({T - int(l ? (l - 1) % T : T - 1), z[x] - 'A', -1});
        }
        sort(cand[u].begin(), cand[u].end());
        ll cur = (dist[u] - dist[top[u]]) % T;
        for (int i = 0; i + 1 < cand[u].size(); i++) {
            if (cand[u][i][0] <= cur && cur < cand[u][i + 1][0]) ok[u] |= 1LL << i;
        }
        for (auto &e : G[u]) if (e[0] ^ fa) {
            dist[e[0]] = dist[u] + e[1], dfs(e[0], u);
            if (z[u] == z[e[0]]) ok[u] |= ok[e[0]];
        }
    };
    dfs(1, 0);
    while (q--) {
        int op, x;
        scanf("%d", &op);
        if (op <= 2) {
            char z[2];
            scanf("%s", z);
            scanf("%lld", &(op == 1 ? pass : fine)[z[0] - 'A']);
            lim[z[0] - 'A'] = pass[z[0] - 'A'] / fine[z[0] - 'A'] + 1;
        } else {
            scanf("%d", &x);
            ll ans = LLONG_MAX, sum = 0;
            vector<ll> cur(mn[x], mn[x] + K);
            for (int i = 0; i < z[x] - 'A'; i++) {
                sum += min(pass[i], fine[i] * min(lim[i], cur[i]));
            }
            for (int i = 0; i + 1 < cand[x].size(); i++) {
                int c = cand[x][i][1];
                sum -= min(pass[c], fine[c] * min(lim[c], cur[c]));
                sum += min(pass[c], fine[c] * min(lim[c], cur[c] += cand[x][i][2]));
                if (ok[x] >> i & 1) ans = min(ans, sum);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
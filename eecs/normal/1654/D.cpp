#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int T, n, rat[maxn], cur[maxn], mx[maxn];
vector<array<int, 3>> G[maxn];
vector<array<int, 2>> d[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            G[i].clear(), d[i].clear();
        }
        for (int i = 2; i <= n; i++) if (d[i].empty()) {
            for (int j = i; j <= n; j += i) {
                int x = j, c = 0;
                while (!(x % i)) x /= i, c++;
                d[j].push_back({i, c});
            }
        }
        for (int i = 1, u, v, x, y; i < n; i++) {
            scanf("%d %d %d %d", &u, &v, &x, &y);
            int g = __gcd(x, y);
            x /= g, y /= g;
            G[u].push_back({v, y, x});
            G[v].push_back({u, x, y});
            // a[j] = a[i] * y / x
        }
        fill(mx + 1, mx + n + 1, 0);
        int sum = 0;
        function<void(int, int)> dfs = [&](int u, int fa) {
            (sum += rat[u]) %= P;
            for (auto &e : G[u]) if (e[0] ^ fa) {
                for (auto &p : d[e[1]]) cur[p[0]] += p[1];
                for (auto &p : d[e[2]]) {
                    cur[p[0]] -= p[1];
                    mx[p[0]] = max(mx[p[0]], -cur[p[0]]);
                }
                rat[e[0]] = 1LL * rat[u] * e[1] % P * qp(e[2], P - 2) % P;
                dfs(e[0], u);
                for (auto &p : d[e[1]]) cur[p[0]] -= p[1];
                for (auto &p : d[e[2]]) cur[p[0]] += p[1];
            }
        };
        rat[1] = 1, dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            sum = 1LL * sum * qp(i, mx[i]) % P;
        }
        printf("%d\n", sum);
    }
    return 0;
}
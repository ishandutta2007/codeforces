#include <bits/stdc++.h>
using namespace std;

const int maxn = 210, P = 1000000007;
int n, ans, p[maxn][maxn], binom[maxn][maxn], dep[maxn];
vector<int> G[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    int inv2 = qp(2, P - 2);
    for (int i = 1; i <= n; i++) {
        p[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i + j <= n; j++) {
            p[i][j] = 1LL * inv2 * (p[i - 1][j] + p[i][j - 1]) % P;
        }
    }
    auto merge = [&](vector<pair<int, int>> &V1, vector<pair<int, int>> V2) {
        int s = 0;
        for (int i = 0; i < V1.size(); i++) {
            for (int j = 0; j < V2.size(); j++) {
                if (V1[i] > V2[j]) (s += p[V1[i].second + 1][V2[j].second + 1]) %= P;
                else (s += p[V2[j].second + 1][V1[i].second + 1]) %= P;
            }
        }
        for (auto x : V2) V1.push_back(x);
        return s;
    };
    for (int rt = 1; rt <= n; rt++) {
        function<vector<pair<int, int>>(int, int)> dfs = [&](int v, int fa) {
            vector<pair<int, int>> V;
            for (int u : G[v]) if (u ^ fa) {
                (ans += merge(V, dfs(u, v))) %= P;
            }
            for (auto &x : V) {
                if (x.first < v) ++ans %= P;
                x.second++;
            }
            V.emplace_back(v, 0);
            return V;
        };
        dfs(rt, 0);
    }
    ans = 1LL * ans * qp(n, P - 2) % P;
    printf("%d\n", ans);
    return 0;
}
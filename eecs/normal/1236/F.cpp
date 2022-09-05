#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010, P = 1000000007;
int n, m, ans1, ans2, dep[maxn], pw[2 * maxn], fa[maxn];
vector<int> G[maxn], H[maxn];
vector<vector<int>> cyc;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = pw[0] = 1; i <= 2 * n; i++) {
        pw[i] = 1LL * (P + 1) / 2 * pw[i - 1] % P;
    }
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) {
            if (!dep[v]) {
                dep[v] = dep[fa[v] = u] + 1, dfs(v);
            } else if (dep[v] < dep[u] - 1) {
                vector<int> V;
                for (int i = u; ; i = fa[i]) {
                    V.push_back(i), H[i].push_back(dep[u] - dep[v] + 1);
                    if (i == v) break;
                }
                cyc.push_back(V);
            }
        }
    };
    dfs(dep[1] = 1);
    // E[x] = a - b + c
    int sc = 0;
    for (auto &vec : cyc) (sc += pw[vec.size()]) %= P;
    ans1 = (1LL * pw[1] * n + sc - 1LL * pw[2] * m % P + P) % P;
    // E[x^2] = (a - b + c)^2 = a^2 + b^2 + c^2 + 2(ac - ab - bc)
    ans2 = (1LL * pw[1] * n + 1LL * pw[2] * n % P * (n - 1)) % P;
    ans2 = (ans2 + 1LL * pw[2] * m) % P;
    long long e4 = 1LL * m * (m - 1);
    for (int i = 1; i <= n; i++) {
        long long e3 = 1LL * G[i].size() * (G[i].size() - 1);
        ans2 = (ans2 + e3 % P * pw[3]) % P, e4 -= e3;
    }
    ans2 = (ans2 + e4 % P * pw[4] + 1LL * sc * sc) % P;
    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j : H[i]) {
            ans2 = (ans2 + 2LL * pw[j] * s) % P, (s += pw[j]) %= P;
        }
    }
    for (auto &vec : cyc) {
        ans2 = (1LL * ans2 + pw[vec.size()] - pw[2 * vec.size()] + P) % P;
        ans2 = (ans2 + 2LL * pw[vec.size() + 1] * (n - vec.size())) % P;
        int s = 0;
        for (int u : vec) s += G[u].size() - 2;
        ans2 = (ans2 - 2LL * pw[vec.size() + 1] * s % P + P) % P;
        ans2 = (ans2 - 2LL * pw[vec.size() + 2] * (m - s - vec.size()) % P + P) % P;
    }
    ans2 = (ans2 - 2LL * pw[2] * (2 * m) % P + P) % P;
    ans2 = (ans2 - 2LL * pw[3] * m % P * (n - 2) % P + P) % P;
    printf("%lld\n", (ans2 - 1LL * ans1 * ans1 % P + P) % P);
    return 0;
}
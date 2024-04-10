#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 65, P = 1000000007;
int n, a[maxn], mark[maxn], binom[maxn][maxn], fact[maxn], inv[maxn];
bool e[maxn][maxn], vis[maxn];
ll N[maxn];
unordered_map<ll, int> f[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) if (!(a[j] % a[i])) {
            mark[j] = 1;
            for (int k = j + 1; k < n; k++) if (!(a[k] % a[i])) {
                e[j][k] = e[k][j] = 1;
            }
        }
    }
    int ans = 1, cur = 0;
    for (int i = 0; i < n; i++) if (mark[i] && !vis[i]) {
        vector<int> id;
        function<void(int)> dfs = [&](int x) {
            vis[x] = 1, id.push_back(x);
            for (int i = 0; i < n; i++) {
                if (e[x][i] && !vis[i]) dfs(i);
            }
        };
        dfs(i);
        int ways = 0, sz = id.size();
        for (int j = 0; j < sz; j++) {
            N[j] = 1LL << j;
            for (int k = 0; k < sz; k++) {
                if (e[id[j]][id[k]]) N[j] |= 1LL << k;
            }
        }
        for (int i = 0; i < sz; i++) f[i].clear();
        f[0][0] = 1;
        for (int i = 0; i < sz; i++) for (auto &p : f[i]) {
            ways = (ways + 1LL * p.second * (sz - i) % P * fact[sz - 1]) % P;
            for (int j = 0; j < sz; j++) if (!(p.first >> j & 1)) {
                ll S = p.first | N[j];
                int _i = __builtin_popcountll(S);
                f[_i][S] = (f[_i][S] - 1LL * p.second * inv[_i] % P + P) % P;
            }
        }
        ans = 1LL * ans * ways % P * binom[cur += sz - 1][sz - 1] % P;
    }
    printf("%d\n", ans);
    return 0;
}
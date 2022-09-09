#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    LL ans = 1;
    vector<int> p(n + 1, -1);
    function<int(int)> fp = [&](int u) {
        return p[u] < 0 ? u : p[u] = fp(p[u]);
    };
    for (int i = 1; i < n; i += 1) {
        int u, v;
        cin >> u >> v;
        u = fp(u);
        v = fp(v);
        ans = ans * (2 * i - 1) % mod;
        ans = ans * -p[u] % mod;
        ans = ans * -p[u] % mod;
        ans = ans * -p[v] % mod;
        ans = ans * -p[v] % mod;
        p[u] += p[v];
        p[v] = u;
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1 << 19;
constexpr LL mod = 998244353;
int s[maxn + 1], v[maxn + 1], r[maxn + 1], n, m;
LL f[maxn + 1], g[maxn + 1];
void add(int x, int d) {
    for (; x <= maxn; x += x &- x) s[x] += d;
}
int sum(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += s[x];
    return res;
}
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
LL C(int n, int m) {
    if (n < m) return 0;
    return f[n] * g[m] % mod * g[n - m] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    f[0] = 1;
    for (int i = 1; i <= maxn; i += 1) f[i] = f[i - 1] * i % mod;
    g[maxn] = power(f[maxn], mod - 2);
    for (int i = maxn; i >= 1; i -= 1) g[i - 1] = g[i] * i % mod;
    int t;
    for (cin >> t; t; t -= 1) {
        cin >> n >> m;
        vector<int> x(m), y(m);
        for (int i = 0; i < m; i += 1) cin >> x[i] >> y[i];
        vector<int> w;
        set<int> st;
        int k = n - 1;
        for (int i = m - 1; i >= 0; i -= 1) {
            int p = y[i];
            int L = 0, R = maxn;
            for (; L + 1 < R;) {
                int M = (L + R) >> 1;
                if (M - L - s[M] < p) {
                    p -= M - L - s[M];
                    L = M;
                }
                else R = M;
            }
            L += 1;
            add(L, 1);
            w.push_back(L);
            if (L < n and not st.count(L + 1)) k -= 1;
            st.insert(L);
        }
        for (int L : w) add(L, -1);
        cout << C(n + k, n) << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
void add(LL& x, LL y) {
    if ((x += y) >= mod)
        x -= mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, l, r, z;
    cin >> n >> l >> r >> z;
    vector C(n + 1, vector<LL>(n + 1));
    for (int i = 0; i <= n; i += 1)
        for (int j = 0; j <= i; j += 1)
            C[i][j] = j ? (C[i - 1][j - 1] + C[i - 1][j]) % mod : 1;
    auto tov = [&](LL x) {
        vector<LL> v;
        for (int i = 0; i < 64; i += 1) {
            v.push_back(x & 1);
            x /= 2;
        }
        return v;
    };
    auto L = tov(l), R = tov(r), Z = tov(z);
    vector f(3, vector(3, vector<LL>(2 * n)));
    f[1][1][0] = 1;
    for (int i = 0; i < 64; i += 1) {
        vector g(3, vector(3, vector<LL>(2 * n)));
        for (int j = 0; j < 3; j += 1)
            for (int k = 0; k < 3; k += 1)
                for (int x = 0; x < 2 * n; x += 1)
                    if (f[j][k][x])
                        for (int y = 0; y <= n; y += 1)
                            if (y % 2 == Z[i]) {
                                int nx = (x + y) / 2;
                                int c = (x + y) % 2;
                                int nj = 0;
                                if (j == 0) {
                                    if (c > L[i]) nj = 2;
                                    else nj = 0;
                                }
                                else if (j == 1) {
                                    if (c > L[i]) nj = 2;
                                    else if (c == L[i]) nj = 1;
                                    else nj = 0;
                                }
                                else {
                                    if (c >= L[i]) nj = 2;
                                    else nj = 0;
                                }
                                int nk = 0;
                                if (k == 0) {
                                    if (c < R[i]) nk = 2;
                                    else nk = 0;
                                }
                                else if (k == 1) {
                                    if (c < R[i]) nk = 2;
                                    else if (c == R[i]) nk = 1;
                                    else nk = 0;
                                }
                                else {
                                    if (c <= R[i]) nk = 2;
                                    else nk = 0;
                                }
                                add(g[nj][nk][nx], f[j][k][x] * C[n][y] % mod);
                            }
        f.swap(g);
    }
    LL ans = 0;
    for (int i = 1; i < 3; i += 1)
        for (int j = 1; j < 3; j += 1)
            add(ans, f[i][j][0]);
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    constexpr int maxc = 1'000'000;
    vector<LL> s(maxc * 2 + 2);
    for (int i = 0; i < m; i += 1) {
        int c;
        cin >> c;
        s[-c + 1 + maxc] += 1;
        s[c + 1 + maxc] -= 1;
    }
    for (int i = 2; i < (int)s.size(); i += 1)
        s[i] += s[i - 2];
    vector<LL> f(m + 1);
    for (int i = 0; i <= m; i += 1) f[i] = i ? f[i - 1] * i % mod : 1;
    LL n = 0, ans = 0, way = 1;
    for (int i = -maxc; i <= maxc; i += 1) {
        way = way * f[s[i + maxc]] % mod;
        ans = (ans + (n + 1 + n + s[i + maxc]) % mod * s[i + maxc] % mod * (mod + 1) / 2 % mod * (mod + i)) % mod;
        n += s[i + maxc];
    }
    cout << ans << " " << way;
    return 0;
}
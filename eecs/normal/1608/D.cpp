#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int n, c[2][2], cl[2], cr[2], cf, fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    cin >> n;
    for (int i = fact[0] = finv[0] = 1; i <= 2 * n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int x, int y) {
        if (x < y || y < 0) return 0LL;
        return 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s[0] != '?' && s[1] != '?') {
            c[s[0] == 'W'][s[1] == 'W']++;
        } else if (s[0] != '?') {
            cl[s[0] == 'W']++;
        } else if (s[1] != '?') {
            cr[s[1] == 'W']++;
        } else {
            cf++;
        }
    }
    int ans = 0;
    for (int i = -cf; i <= cf; i++) {
        int ways = binom(2 * cf, cf - abs(i));
        ans = (ans + binom(cl[0] + cl[1] + cr[0] + cr[1], cl[1] + cr[1] + c[1][1] - c[0][0] + i) * ways) % P;
    }
    if (!c[0][0] && !c[1][1]) {
        int m1 = min(1, cl[0] + cr[1]), m2 = min(1, cl[1] + cr[0]);
        for (int i = 0; i <= cf; i++) {
            if (m1 + i == 0 || m2 + cf - i == 0) continue;
            ans = (ans - binom(cf, i) + P) % P;
        }
    }
    cout << ans << '\n';
    return 0;
}
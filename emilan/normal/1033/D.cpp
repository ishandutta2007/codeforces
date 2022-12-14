#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
constexpr i64 kMod = 998244353;

i64 int_pow(i64 b, int e) {
    i64 r = 1;
    while (e --> 0) r *= b;
    return r;
}

i64 f(i64 x, int e) {
    i64 l = 1, r = i64(powl(2 * x, 1.0 / e)) + 1;
    while (l + 1 < r) {
        i64 m = (l + r) / 2;
        if (int_pow(m, e) < x) l = m;
        else r = m;
    }
    return int_pow(r, e) == x ? r : -1;
}

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto &x : a) cin >> x;

    map<i64, int> x_pow;
    map<i64, int> xy_pow;
    for (i64 x : a) {
        bool ok1 = false;
        for (int e = 4; e >= 2; e--) {
            i64 b = f(x, e);
            if (b != -1) {
                x_pow[b] += e;
                ok1 = true;
                break;
            }
        }
        if (!ok1) {
            bool ok2 = false;
            for (i64 y : a) {
                if (i64 g = gcd(x, y); g != 1 && g != x) {
                    x_pow[g]++;
                    x_pow[x / g]++;
                    ok2 = true;
                    break;
                }
            }
            if (!ok2) xy_pow[x]++;
        }
    }

    i64 ans = 1;
    for (auto [_, e] : x_pow) ans = ans * (e + 1) % kMod;
    for (auto [_, e] : xy_pow) ans = ans * (e + 1) % kMod * (e + 1) % kMod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
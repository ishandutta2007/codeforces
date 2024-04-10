#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

constexpr i64 kInf = 1LL << 30;

void solve() {
    i64 l_a, r_a, t_a;
    cin >> l_a >> r_a >> t_a;
    i64 l_b, r_b, t_b;
    cin >> l_b >> r_b >> t_b;

    if (t_a > t_b) {
        swap(l_a, l_b);
        swap(r_a, r_b);
        swap(t_a, t_b);
    }

    i64 g = gcd(t_a, t_b);
    i64 d = (l_a - l_b + g * kInf) / g - kInf;
    auto f = [&](i64 l, i64 r) {
        return max<i64>(min(r, r_a) - max(l, l_a) + 1, 0);
    };
    i64 ans = max(f(l_b + g * d, r_b + g * d),
            f(l_b + g * (d + 1), r_b + g * (d + 1)));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
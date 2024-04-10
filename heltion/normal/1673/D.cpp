#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 1'000'000'007;
void add(int& x, int y) {
    if ((x += y) >= mod) x -= mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL b, q, y, c, r, z;
        //a, p, x
        cin >> b >> q >> y >> c >> r >> z;
        if (r % q or (c - b) % q) {
            cout << "0\n";
            continue;
        }
        LL L = (c - b) / q + 1, R = (c + r * (z - 1) - b) / q + 1;
        if (L < 1 or R > y) {
            cout << "0\n";
            continue;
        }
        if (c - r < b or c + r * z > b + q * (y - 1)) {
            cout << "-1\n";
            continue;
        }
        //lcm(p, q) = r;
        LL ans = 0;
        auto check = [&](LL p) {
            if (p * q / gcd(p, q) == r)
                ans = (ans + (r / p) * (r / p)) % mod;
        };
        for (LL i = 1; i * i <= r; i += 1)
            if (r % i == 0) {
                check(i);
                if (i * i != r)
                    check(r / i);
            }
        cout << ans << "\n";
    }
}
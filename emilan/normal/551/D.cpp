#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using mat = array<array<ull, 2>, 2>;

ull m;

mat operator*(mat x, mat y) {
    mat z{{{}, {}}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                z[i][j] += x[i][k] * y[k][j];
            }
            z[i][j] %= m;
        }
    }
    return z;
}

ull get_fib(ull n) {
    mat b{{{0, 1}, {1, 1}}}, r{{{1, 0}, {0, 1}}};
    for (n--; n; n >>= 1, b = b * b) {
        if (n & 1) r = r * b;
    }
    return r[1][1];
}

ull pow2(ull e) {
    ull r = 1;
    for (ull b = 2; e; e >>= 1, b = b * b % m) {
        if (e & 1) r = r * b % m;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    ull n, k, l;
    cin >> n >> k >> l >> m;
    if (m == 1 || (l < 64 && (1ull << l) - 1 < k)) return cout << 0, 0;

    ull fib = get_fib(n + 2);
    ull fib_c = (pow2(n) - fib + m) % m;

    ull ans = 1;
    for (ull i = 0; i < l; i++) {
        if (k >> i & 1) ans = ans * fib_c;
        else ans = ans * fib;
        ans %= m;
    }
    cout << ans;
}
#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

bool is_prime(i64 x) {
    for (int i = 2; i64(i) * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    i64 a, b;
    cin >> a >> b;
    if (is_prime(a + b) && a - b == 1) cout << "yEs";
    else cout << "nO";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}
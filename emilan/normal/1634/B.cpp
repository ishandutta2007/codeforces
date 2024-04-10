#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

void solve() {
    i64 n, x, y;
    cin >> n >> x >> y;
    vector<i64> a(n);
    for (auto &z : a) cin >> z;

    i64 xum = accumulate(a.begin(), a.end(), 0LL, bit_xor());
    if (((x ^ xum) & 1) == (y & 1)) {
        cout << "Alice";
    } else {
        cout << "Bob";
    }
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
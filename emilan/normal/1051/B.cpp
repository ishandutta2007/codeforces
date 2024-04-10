#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

void solve() {
    i64 l, r;
    cin >> l >> r;

    cout << "YES\n";
    for (i64 i = l; i < r; i += 2) {
        cout << i << ' ' << i + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
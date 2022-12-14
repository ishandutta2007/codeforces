#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> c(m);
    for (auto &[t, l, r] : c) cin >> t >> l >> r, l--, r--;

    vector<int> a(n, n);
    for (int i = 1; i < n; i++) {
        bool s = false;
        for (auto [t, l, r] : c) {
            if (t == 1 && l <= i - 1 && r >= i) {
                s = true;
                break;
            }
        }

        a[i] = a[i - 1] - !s;
    }

    for (auto [t, l, r] : c) {
        if (t == 0 && is_sorted(a.begin() + l, a.begin() + r + 1)) {
            return cout << "NO", 0;
        }
    }

    cout << "YES\n";
    for (int x : a) cout << x << ' ';
}
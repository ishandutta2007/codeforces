#include <bits/stdc++.h>

using namespace std;

const int kMax = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    auto f = [&](int lo) {
        vector<int> b(a);
        for (int i = n - 1; i >= 0; i--) {
            if (b[i] < lo) return false;
            if (i >= 2) {
                int d = min(b[i] - lo, a[i]) / 3;
                b[i - 2] += 2 * d;
                b[i - 1] += d;
            }
        }
        return true;
    };

    int l = 0, r = kMax + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (f(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
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
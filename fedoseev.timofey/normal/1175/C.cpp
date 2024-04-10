#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n, k;
    cin >> n >> k;
    ++k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        vector <pair <int, int>> s;
        for (int i = 0; i < n; ++i) {
            s.emplace_back(a[i] - m, -1);
            s.emplace_back(a[i] + m, 1);
        }
        sort(s.begin(), s.end());
        bool fl = false;
        int bal = 0;
        for (auto p : s) {
            bal -= p.second;
            fl |= (bal >= k);
        }
        if (fl) r = m;
        else l = m;
    }
    vector <pair <int, int>> s;
    for (int i = 0; i < n; ++i) {
        s.emplace_back(a[i] - r, -1);
        s.emplace_back(a[i] + r, 1);
    }
    sort(s.begin(), s.end());
    int bal = 0;
    for (auto p : s) {
        bal -= p.second;
        if (bal >= k) {
            cout << p.first << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}
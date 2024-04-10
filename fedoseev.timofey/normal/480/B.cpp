#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> a;

bool hv(int x) {
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it == a.end()) return false;
    if ((*it) == x) return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool fl1 = false, fl2 = false;
    for (int i = 0; i < n; ++i) {
        if (hv(a[i] + x)) fl1 = true;
        if (hv(a[i] + y)) fl2 = true;
    }
    if (fl1 && fl2) {
        cout << "0\n";
        return 0;
    }
    if (fl1) {
        cout << "1\n" << y << '\n';
        return 0;
    }
    if (fl2) {
        cout << "1\n" << x << '\n';
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int nd = a[i] + x;
        if (nd > l) continue;
        if (hv(nd - y) || hv(nd + y)) {
            cout << "1\n";
            cout << nd << '\n';
            return 0;
        } 
    }

    for (int i = 0; i < n; ++i) {
        int nd = a[i] - x;
        if (nd < 0) continue;
        if (hv(nd - y) || hv(nd + y)) {
            cout << "1\n";
            cout << nd << '\n';
            return 0;
        } 
    }

    cout << "2\n";
    cout << x << ' ' << y << '\n';
    return 0;
}
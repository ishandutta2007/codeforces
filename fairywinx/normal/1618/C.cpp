#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long d = 0;
    for (int i = 0; i < n; i += 2) {
        d = gcd(d, a[i]);
    }
    bool find = false;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] % d == 0 && a[i + 1] % d == 0) {
            find = true;
        }
    }
    if (!find) {
        cout << d << '\n';
        return;
    }
    d = 0, find = 0;
    for (int i = 1; i < n; i += 2) {
        d = gcd(d, a[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] % d == 0 && a[i + 1] % d == 0) {
            find = true;
        }
    }
    if (!find) {
        cout << d << '\n';
    } else {
        cout << 0 << '\n';
    }
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}
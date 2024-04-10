#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n = 7;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                vector<int> b = {a[i], a[j], a[k], a[i] + a[j], a[i] + a[k], a[j] + a[k], a[i] + a[j] + a[k]};
                sort(all(b));
                if (b == a) {
                    cout << a[i] << ' ' << a[j] << ' ' << a[k] << '\n';
                    return;
                }
            }
        }
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
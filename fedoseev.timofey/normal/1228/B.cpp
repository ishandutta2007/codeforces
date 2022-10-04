#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector <vector <int>> st(n, vector <int> (m, 2));
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            if (st[i][j] == 0) {
                ans = 0;
            }
            st[i][j] = 1;
        }
        if (a[i] != m) {
            if (st[i][a[i]] == 1) {
                ans = 0;
            }
            st[i][a[i]] = 0;
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < b[j]; ++i) {
            if (st[i][j] == 0) {
                ans = 0;
            }
            st[i][j] = 1;
        }
        if (b[j] != n) {
            if (st[b[j]][j] == 1) {
                ans = 0;
            }
            st[b[j]][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (st[i][j] == 2) {
                ans *= 2;
                ans %= md;
            }
        }
    }
    cout << ans << '\n';
}
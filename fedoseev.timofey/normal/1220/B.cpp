#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int my_sqrt(ll x) {
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if ((ll)m * m <= x) l = m;
        else r = m;
    }
    return l;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector <int> ans(n);
    ans[0] = my_sqrt((ll)a[0][1] * a[0][2] / a[1][2]);
    for (int i = 1; i < n; ++i) {
        ans[i] = a[0][i] / ans[0];
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}
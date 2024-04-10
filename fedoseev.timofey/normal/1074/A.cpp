#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector <int> w;
    for (int i = 0; i < m; ++i) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 == 1) {
            w.push_back(x2);
        }
    }
    sort(w.begin(), w.end());
    m = w.size();
    int ans = 1e9;
    int uk = 0;
    for (int i = 0; i <= n; ++i) {
        int mx = (i == n ? 1e9 : x[i]);
        while (uk < m && w[uk] < mx) ++uk;
        ans = min(ans, i + m - uk);
    }
    cout << ans << '\n';
}
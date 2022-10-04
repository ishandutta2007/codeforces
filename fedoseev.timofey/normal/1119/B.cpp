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
    int n, h;
    cin >> n >> h;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        vector <int> b;
        for (int i = 0; i < m; ++i) {
            b.push_back(a[i]);
        }
        if (b.size() % 2 == 1) b.push_back(0);
        sort(b.begin(), b.end());
        int cnt = 0;
        for (int i = 1; i < (int)b.size(); i += 2) cnt += b[i];
        if (cnt <= h) l = m;
        else r = m;
    }
    cout << l << '\n';
}
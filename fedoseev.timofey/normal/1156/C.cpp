#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, c;
    cin >> n >> c;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = n / 2 + 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        bool fl = true;
        for (int i = 0; i < m; ++i) {
            fl &= (a[n - (m - i)] - a[i] >= c);
        }
        if (fl) l = m;
        else r = m;
    }
    cout << l << '\n';
}
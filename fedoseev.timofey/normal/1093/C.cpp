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
    int n;
    cin >> n;
    int m = n / 2;
    vector <ll> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    ll cb = -2e18;
    ll ce = 2e18;
    vector <ll> a(n);
    for (int i = 0; i < m; ++i) {
        ll cx = max((ll)0, cb);
        ll cy = min(ce, b[i]);
        ll ny = b[i] - cx;
        ll nx = b[i] - cy;
        cx = max(cx, nx);
        cy = min(cy, ny);
        a[i] = cx;
        a[n - i - 1] = cy;
        cb = cx;
        ce = cy;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}
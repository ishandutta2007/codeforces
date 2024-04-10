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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = (ll)a[0] * (n - a[0] + 1);
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            int x = n - a[i] + 1;
            int y = a[i] - a[i - 1];
            ans += (ll)x * y;
        }
        if (a[i] < a[i - 1]) {
            int x = a[i];
            int y = a[i - 1] - a[i];
            ans += (ll)x * y;
        }
    }
    cout << ans << '\n';
}
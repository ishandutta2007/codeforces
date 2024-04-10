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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    vector <int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        return a[i] - b[i] > a[j] - b[j];
    });
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (ll)i * a[idx[i]] + (ll)(n - i - 1) * b[idx[i]];
    }
    cout << ans << '\n';
}
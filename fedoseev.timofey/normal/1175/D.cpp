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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <ll> suf(n);
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n) suf[i] = suf[i + 1] + a[i];
        else suf[i] = a[i];
    }
    ll ans = suf[0];
    suf.erase(suf.begin());
    sort(suf.rbegin(), suf.rend());
    for (int i = 0; i + 1 < k; ++i) {
        ans += suf[i];
    }
    cout << ans << '\n';
}
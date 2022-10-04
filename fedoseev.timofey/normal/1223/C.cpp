#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    sort(p.rbegin(), p.rend());
    vector <ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + p[i];
    }
    auto Sum = [&] (int l, int r) {
        return pref[r] - pref[l];
    };
    int x, a, y, b;
    cin >> x >> a >> y >> b;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    ll k;
    cin >> k;
    int ans = 1e9;
    int cA = 0, cB = 0, cAll = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % a == 0 && i % b == 0) ++cAll;
        else if (i % a == 0) ++cA;
        else if (i % b == 0) ++cB;
        if (Sum(0, cAll) * (x + y) / 100 + Sum(cAll, cAll + cA) * x / 100 + Sum(cAll + cA, cAll + cA + cB) * y / 100 >= k) {
            ans = min(ans, i);
        }
    }
    if (ans > 5e8) cout << "-1\n";
    else cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    while (q--) solve();
}
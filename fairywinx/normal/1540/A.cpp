#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    sort(all(d));
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + d[i];
    sort(rall(d));
    long long ans = d[0];
    for (int i = 0; i < n; ++i) {
        ans += pref[n - i] - 1ll * d[i] * (n - i);
        // cout << pref[n - i] - 1ll * d[i] * (n - i) << ' ' << d[i] << ' ' << pref[n - i] << ' ' << (n - i) << '\n';
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}
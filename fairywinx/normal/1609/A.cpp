#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        while (a[i] % 2 == 0) {
            ++cnt;
            a[i] /= 2;
        }
    }
    sort(rall(a));
    for (int i = 0; i < cnt; ++i)
        a[0] *= 2;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i];
    cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;

int n, k;
int a[MAXN];
int pref[MAXN], post[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (k == 1) {
        int mn = INF;
        for (int i = 0; i < n; ++i) mn = min(mn, a[i]);
        cout << mn << '\n';
    }
    else if (k == 2) {
        pref[0] = INF;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = min(pref[i], a[i]);
        }   
        post[n] = INF;
        for (int i = n - 1; i >= 0; --i) {
            post[i] = min(post[i + 1], a[i]);
        }
        int ans = -INF;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, max(pref[i + 1], post[i + 1]));
        }   
        cout << ans << '\n';
    }
    else {
        int mx = -INF;
        for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
        cout << mx << '\n';
    }

    return 0;
}
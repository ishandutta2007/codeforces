#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> a1;
    map<int, int> a2;
    map<pair<int, int>, int> a3;
    int mn = 2e9 + 228;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        if (a1[l] == 0)
            a1[l] = 2e9 + 228;
        if (a2[r] == 0)
            a2[r] = 2e9 + 228;
        if (a3[{l, r}] == 0)
            a3[{l, r}] = 2e9 + 228;
        a1[l] = min(a1[l], c);
        a2[r] = min(a2[r], c);
        a3[{l, r}] = min(a3[{l, r}], c);
        mn = min(mn, l);
        mx = max(mx, r);
        if (a3[{mn, mx}] == 0)
            a3[{mn, mx}] = 2e9 + 228;
        cout << min(a1[mn] + a2[mx], a3[{mn, mx}]) << '\n';
    }
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
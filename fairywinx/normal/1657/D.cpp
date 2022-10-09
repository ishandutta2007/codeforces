#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n, C;
    cin >> n >> C;
    vector<long long> mx(C + 1);
    for (int i = 0; i < n; ++i) {
        int c, d, h;
        cin >> c >> d >> h;
        mx[c] = max(mx[c], 1ll * d * h);
    }
    for (int i = C; i >= 1; --i) {
        for (int j = i; j <= C; j += i) {
            mx[j] = max(mx[j], mx[i] * (j - i + i) / i);
        }
    }
    for (int i = 1; i <= C; ++i)
        mx[i] = max(mx[i - 1], mx[i]);
    int q;
    cin >> q;
    while (q--) {
        long long d, h;
        cin >> d >> h;
        int l = 0, r = C + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (mx[mid] > d * h)
                r = mid;
            else
                l = mid;
        }
        if (r == C + 1) {
            cout << -1 << ' ';
        } else {
            cout << r << ' ';
        }
    }
    cout << '\n';
}

signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    // SOLVE
    solve();
}
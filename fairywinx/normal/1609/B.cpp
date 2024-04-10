#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string a;
    cin >> a;
    int cnt = 0;
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'c')
            ++cnt;
    }
    for (int j = 0; j < q; ++j) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;
        for (int i = max(pos - 3, 0); i < min(n - 2, pos + 3); ++i) {
            if (a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'c')
                --cnt;
        }
        a[pos] = c;
        for (int i = max(pos - 3, 0); i < min(n - 2, pos + 3); ++i) {
            if (a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'c')
                ++cnt;
        }
        cout << cnt << '\n';
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

    // SOLVE
    solve();
}
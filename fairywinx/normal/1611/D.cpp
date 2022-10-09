#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> sum(n, -1);
    vector<int> par(n);
    for (int i = 0; i < n; ++i) {
        cin >> par[i];
        --par[i];
        if (par[i] == i) {
            par[i] = -1;
        }
    }
    vector<int> ans(n, 0);
    bool res = true;
    int lst = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        if (par[a] != -1) {
            if (sum[par[a]] == -1) {
                res = false;
            } else {
                ans[a] = lst - sum[par[a]] + 1;
                sum[a] = ans[a] + sum[par[a]];
                lst = sum[a];
            }
        } else {
            sum[a] = 0;
        }
    }
    if (!res) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
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
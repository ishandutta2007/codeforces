#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k * 2 - 1 > n) {
        cout << "-1\n";
        return;
    }
    vector<vector<char>> ans(n, vector<char> (n, '.'));
    int cnt = 0;
    for (int i = 0; i < n; i += 2) {
        ++cnt;
        if (cnt > k)
            break;
        ans[i][i] = 'R';
    }
    for (auto i : ans) {
        for (auto j : i)
            cout << j;
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
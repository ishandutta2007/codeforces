#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> who(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        who[i].resize(c);
        for (int j = 0; j < c; ++j) {
            cin >> who[i][j];
        }
    }
    vector<int> used(n);
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        bool find = false;
        for (int j : who[i]) {
            if (!used[j - 1]) {
                used[j - 1] = 1;
                find = true;
                break;
            }
        }
        if (!find) {
            ind = i;
        }
    }
    if (ind == -1) {
        cout << "OPTIMAL\n";
    } else {
        cout << "IMPROVE\n";
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                cout << ind + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
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

    SOLVE;
}
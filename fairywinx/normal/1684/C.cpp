#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int mn = m + 1, mx = -1;
    for (int i = 0; i < n; ++i) {
        int ind = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] < a[i][ind]) {
                mn = min(mn, ind);
                mx = max(mx, j);
            } else if (a[i][j] > a[i][ind]) {
                ind = j; 
            }
        }
    }
    if (mx == -1) {
        cout << 1 << ' ' << 1 << '\n';
    } else {
        for (int i = 0; i < n; ++i) {
            swap(a[i][mn], a[i][mx]);
        }
        bool find = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + 1 < m; ++j) {
                if (a[i][j] > a[i][j + 1]) {
                    find = true;
                }
            }
        }
        if (!find) {
            cout << mn + 1 << ' ' << mx + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}

int main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

   SOLVE
}
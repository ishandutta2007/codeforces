#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a), [] (const pair<int, int> a, const pair<int, int> b) {
        return a.second - a.first < b.second - b.first;
    });
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].first == a[j].first) {
                ans[j] = a[i].second + 1;
                break;
            } else if (a[i].second == a[j].second) {
                ans[j] = a[i].first - 1;
                break;
            }
        }
        if (a[i].second - a[i].first == 0) {
            ans[i] = a[i].second;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << ' ' << a[i].second << ' ' << ans[i] << '\n';
    }
    cout << '\n';
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
#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans[i].first = a[i] / 100;
        a[i] = a[i] % 100;
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    long long ans_val = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        if (m >= a[i]) {
            m -= a[i];
            if (a[i] != 0) {
                s.emplace(1ll * c[i] * (100 - a[i]), i);
                ans[i].second = a[i];
            }
        } else {
            if (s.size() && s.begin()->first < 1ll * c[i] * (100 - a[i])) {
                ans_val += s.begin()->first;
                ans[s.begin()->second].first += 1;
                ans[s.begin()->second].second = 0;
                ans[i].second = a[i];
                s.erase(s.begin());
                s.emplace(1ll * c[i] * (100 - a[i]), i);
                m += 100 - a[i];
            } else {
                ans_val += 1ll * c[i] * (100 - a[i]);
                ans[i].first++;
                ans[i].second = 0;
                m += 100 - a[i];
            }
        }
    }
    cout << ans_val << '\n';
    for (auto i : ans) {
        cout << i.first << ' ' << i.second << '\n';
    }
}
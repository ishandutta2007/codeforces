#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> cnt[i];
    }
    vector<int> c(n);
    vector<pair<int, int>> a(m);
    vector<set<int>> who(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
        ++c[a[i].first];
        who[a[i].first].insert(i);
        who[a[i].second].insert(i);
        ++c[a[i].second];
    }
    vector<int> now;
    vector<int> used(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (c[i] <= cnt[i]) {
            now.push_back(i);
        }
    }
    while (now.size()) {
        int ind = now.back();
        now.pop_back();
        for (auto i : who[ind]) {
            if (ind == a[i].first) {
                --c[a[i].second];
                if (c[a[i].second] == cnt[a[i].second]) {
                    now.push_back(a[i].second);
                }
                who[a[i].second].erase(i);
                ans.push_back(i);
            } else {
                --c[a[i].first];
                if (c[a[i].first] == cnt[a[i].first]) {
                    now.push_back(a[i].first);
                }
                who[a[i].first].erase(i);
                ans.push_back(i);
            }
        }
    }
    if ((int) ans.size() == m) {
        cout << "ALIVE\n";
        reverse(all(ans));
        for (int i : ans)
            cout << i + 1 << ' ';
        cout << '\n';
    } else {
        cout << "DEAD\n";
    }
}
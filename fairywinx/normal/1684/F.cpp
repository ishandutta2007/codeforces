#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, vector<int>> who;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        who[a[i]].push_back(i);
    }
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
        --q[i].first;
    }
    vector<int> nxt(n, -1);
    {
        int mx = -1;
        vector<vector<int>> tmp(n);
        for (auto i : q) {
            tmp[i.first].emplace_back(i.second);
        }
        for (int i = 0; i < n; ++i) {
            for (int j : tmp[i]) {
                mx = max(mx, j);
            }
            nxt[i] = mx;
        }
    }
    vector<int> to(n, -1);
    int mn = n + 1;
    int mxx = -1;
    for (int i = 0; i < n; ++i) {
        if (nxt[i] <= i) {
            continue;
        }
        if (*prev(lower_bound(all(who[a[i]]), nxt[i])) != i) {
            int ind = *prev(lower_bound(all(who[a[i]]), nxt[i]));
            to[i] = ind;
        }
        if (upper_bound(all(who[a[i]]), i) != who[a[i]].end()) {
            int ind1 = *upper_bound(all(who[a[i]]), i);
            if (ind1 < nxt[i]) {
                mn = min(mn, ind1);
                mxx = max(mxx, i);
            }
        }
    }
    int mx = -1;
    int ans = n;
    // cout << mxx << ':';
    for (int i = 0; i < n; ++i) {
        if (i <= mn) {
            ans = min(ans, max(mxx, mx) - i + 1);
        }
        mx = max(mx, to[i]);
    }
    cout << max(0, ans) << '\n';
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
#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    int ans = 0;
    bool find = false;
    for (int i : a) {
        auto it = s.lower_bound((i + 1) / 2);
        if (s.count(i)) {
            s.erase(i);
            continue;
        }
        if (it == s.begin()) {
            find = true;
        } else {
            if (*prev(it) != i) {
                ++ans;
            }
            s.erase(*prev(it));
        }
    }
    if (find) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
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
#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> now;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > 1)
            now.push_back(i);
    }
    set<int> c;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] % 2 == 1)
            c.insert(i);
    }
    long long ans = 0;
    while (now.size()) {
        int v = now.back();
        // cout << v << ' ' << a[v] << '\n';
        now.pop_back();
        while (a[v] && c.size() && (*c.begin() < v || *c.rbegin() > v)) {
            if (*c.begin() < v) {
                int ind = *c.begin();
                c.erase(ind);
                ++a[ind];
                if (a[ind] == 2)
                    now.push_back(ind);
            }
            if (c.size() && *c.rbegin() > v) {
                int ind = *c.rbegin();
                c.erase(ind);
                ++a[ind];
                if (a[ind] == 2)
                    now.push_back(ind);
            }
            a[v] -= 2;
            ++ans;
        }
        ans += a[v] / 2;
        a[v] = a[v] % 2;
    }
    if (c.size()) {
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

    SOLVE
}
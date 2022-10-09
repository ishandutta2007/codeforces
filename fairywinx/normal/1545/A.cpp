#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, pair<int, int>> c;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            c[a[i]].first++;
        } else {
            c[a[i]].second++;
        }
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            c[a[i]].first--;
        } else {
            c[a[i]].second--;
        }
    }
    for (auto i : c) {
        if (i.second.first || i.second.second) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}
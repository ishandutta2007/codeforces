#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    const int inf = 1e9;
    long long now = 1;
    for (int i = 0; i < n; ++i) {
        if (now <= inf) {
            a.push_back(now);
        } else {
            cout << "NO\n";
            return;
        }
        now *= 3;
    }
    cout << "YES\n";
    for (auto i : a)
        cout << i << ' ';
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
#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<string> s;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        s.emplace(a[i]);
        auto tmp = a[i];
        reverse(all(tmp));
        if (s.count(tmp)) {
            cout << "YES\n";
            return;
        }
        if (a[i].size() == 3) {
            string s1 = "";
            s1 += a[i][2];
            s1 += a[i][1];
            if (s.count(s1)) {
                cout << "YES\n";
                return;
            }
        }
    }
    s.clear();
    reverse(all(a));
    for (int i = 0; i < n; ++i) {
        s.emplace(a[i]);
        auto tmp = a[i];
        reverse(all(tmp));
        if (s.count(tmp)) {
            cout << "YES\n";
            return;
        }
        if (a[i].size() == 3) {
            string s1 = "";
            s1 += a[i][1];
            s1 +=  a[i][0];
            if (s.count(s1)) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    vector<int> c;
    string s;
    cin >> s;
    for (auto i : s) {
        c.push_back((i - '0') % 2);
    }
    if (c.back() == 0) {
        cout << 0 << '\n';
    } else if (c[0] == 0) {
        cout << 1 << '\n';
    } else {
        int cnt = 0;
        for (int i : c)
            cnt += (1 - i);
        cout << (cnt ? 2 : -1) << '\n';
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
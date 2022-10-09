#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << s << s << '\n';
        return;
    }
    if (s[0] == s[1]) {
        cout << s[0] << s[0] << '\n';
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] < s[i + 1]) {
            for (auto j = 0; j <= i; ++j)
                cout << s[j];
            for (auto j = i; j >= 0; --j)
                cout << s[j];
            cout << '\n';
            return;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << s[i];
    for (int i = n - 1; i >= 0; --i)
        cout << s[i];
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
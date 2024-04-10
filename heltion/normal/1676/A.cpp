#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5])
            cout << "YES\n";
        else cout << "NO\n";
    }
}
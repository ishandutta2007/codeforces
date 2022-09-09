#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        int m = (int)s.size() - 1, ans = 0;
        while (m >= 0 and s[m] != '1') m -= 1;
        for (int i = 0; i < s.size(); i += 1) {
            if (m <= i) ans += 1;
            if (s[i] == '0') break;
        }
        cout << ans << "\n";
    }
}
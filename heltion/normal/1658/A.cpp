#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 0;
        string s;
        cin >> n >> s;
        for (int i = 1; i < n; i += 1)
            ans += 2 * (s[i - 1] == '0' and s[i] == '0');
        for (int i = 1; i + 1 < n; i += 1)
            ans += (s[i - 1] == '0' and s[i + 1] == '0' and s[i] == '1');
        cout << ans << "\n";
    }
    return 0;
}
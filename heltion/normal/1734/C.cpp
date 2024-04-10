#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        s = "0" + s;
        LL ans = 0;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i += 1) {
            for (int j = i; j <= n; j += i) {
                if (s[j] == '0') {
                    if (not v[j]) ans += i;
                    v[j] = 1;
                }
                else break;
            }
        }
        cout << ans << "\n";
    }
}
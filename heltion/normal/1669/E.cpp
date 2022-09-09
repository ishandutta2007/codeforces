#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n;
        cin >> n;
        vector c(11, vector<LL>(11));
        for (int i = 0; i < n; i += 1) {
            string s;
            cin >> s;
            c[s[0] - 'a'][s[1] - 'a'] += 1;
        }
        LL ans = 0;
        for (int i = 0; i <= 10; i += 1) {
            LL s1 = 0, s2 = 0;;
            for (int j = 0; j <= 10; j += 1) {
                s1 += c[i][j];
                s2 += c[j][i];
                ans -= c[i][j] * c[i][j] + c[j][i] * c[j][i];
            }
            ans += s1 * s1 + s2 * s2;
        }
        cout << ans / 2 << "\n";
    }
}
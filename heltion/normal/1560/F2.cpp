#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n;
        int k;
        cin >> n >> k;
        string s = to_string(n);
        int m = s.size();
        string ans = string(m, '9');
        for (int mask = 0; mask < (1 << 10); mask += 1)
            if (__builtin_popcount(mask) <= k) {
                int mx = 0;
                for (int j = 0; j < 10; j += 1) if ((mask >> j) & 1) mx = j;
                string t(m, '0');
                int ok = 0, done = 0;
                for (int i = 0; i < m and done == i; i += 1)
                    for (int j = ok ? 0 : s[i] - '0'; j < 10; j += 1) if ((mask >> j) & 1) {
                        if (ok == 0 and j == s[i] - '0') {
                            int pok = 1;
                            for (int k = i + 1; k < m; k += 1) {
                                if (s[k] - '0' != mx) {
                                    if (mx < s[k] - '0')
                                        pok = 0;
                                    break;
                                }
                            }
                            if (not pok) continue;
                        }
                        t[i] += j;
                        ok |= j > s[i] - '0';
                        done += 1;
                        break;
                    }
                if (done == m) ans = min(ans, t);
            }
        cout << ans << "\n";
    }
    return 0;
}
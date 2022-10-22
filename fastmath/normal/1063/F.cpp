#include <bits/stdc++.h>
using namespace std;
const int LEN = 1000;
const int N = 5e5 + LEN + 7;
int n;
string s;
const int M1 = 1000 * 1000 + 7;
const int M2 = 1000 * 1000 + 9;
const int BASE = 129;
bool pr[N], dp[N], ms1[M1], ms2[M2];
int h1[N], h2[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        pr[i] = 1;
        h1[i] = h2[i] = s[i];
    }
    int ans = 1;
    for (int len = 2; len < LEN; ++len) {
        memset(dp, 0, sizeof dp);
        memset(ms1, 0, sizeof ms1);
        memset(ms2, 0, sizeof ms2);
        int l = n - len;
        for (int r = n - 1; r >= len - 1; --r, --l) {
            if (pr[r + 1]) {
                ms1[h1[r + 1]] = 1;
                ms2[h2[r + 1]] = 1;
            }   
            dp[l] = (ms1[h1[l]] && ms2[h2[l]]) || (ms1[h1[l + 1]] && ms2[h2[l + 1]]);
            if (dp[l]) ans = len;
        }
        memset(pr, 0, sizeof pr);
        l = n - len;
        for (int r = n - 1; r >= len - 1; --r, --l) {
            pr[l] = dp[l];
        }
        for (int i = n - len; i >= 0; --i) {
            h1[i] = (h1[i] * BASE + s[i + len - 1]) % M1;
            h2[i] = (h2[i] * BASE + s[i + len - 1]) % M2;
        }
    }
    cout << ans << '\n';
}
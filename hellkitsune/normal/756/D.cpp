#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n, cnt;
string s;
int sum[5005][5005], c[5005][5005];
int lst[256];

int main() {
    forn(i, 5005) c[0][i] = 0;
    c[0][0] = 1;
    for (int i = 1; i < 5005; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 5005; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) {
                c[i][j] -= MOD;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin >> cnt >> s;
    int n = 1;
    for (int i = 1; i < cnt; ++i) {
        if (s[i] != s[n - 1]) {
            s[n++] = s[i];
        }
    }
    s.resize(n);
    s = '\0' + s;
    sum[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int c = int(s[i]);
        forn(len, i) {
            sum[i][len + 1] = sum[i - 1][len] + sum[i - 1][len + 1];
            if (sum[i][len + 1] >= MOD) {
                sum[i][len + 1] -= MOD;
            }
            if (lst[c] != 0) {
                sum[i][len + 1] -= sum[lst[c]][len];
                if (sum[i][len + 1] < 0) {
                    sum[i][len + 1] += MOD;
                }
            }
        }
        sum[i][0] = 1;
        lst[c] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + (LL)c[cnt - 1][i - 1] * sum[n][i]) % MOD;
        //cerr << i << ": " << sum[n][i] << endl;
    }
    cout << ans << endl;
    return 0;
}
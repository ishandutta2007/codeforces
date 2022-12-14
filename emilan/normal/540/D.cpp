#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxn = 101;
long double dp[maxn][maxn][maxn];

void solve() {
    int r, s, p;
    cin >> r >> s >> p;

    dp[r][s][p] = 1;
    for (int i = r; ~i; i--) {
        for (int j = s; ~j; j--) {
            for (int k = p; ~k; k--) {
                if ((!i && !j) || (!j && !k) || (!i && !k)) continue;

                int fr = i * j, fs = j * k, fp = k * i;
                long double ft = fr + fs + fp;
                long double cr = fr / ft, cs = fs / ft, cp = fp / ft;
                if (i) dp[i - 1][j][k] += cp * dp[i][j][k];
                if (j) dp[i][j - 1][k] += cr * dp[i][j][k];
                if (k) dp[i][j][k - 1] += cs * dp[i][j][k];
            }
        }
    }

    long double ar = 0, as = 0, ap = 0;
    for (int i = 1; i <= r; i++) ar += dp[i][0][0];
    for (int i = 1; i <= s; i++) as += dp[0][i][0];
    for (int i = 1; i <= p; i++) ap += dp[0][0][i];

    cout << setprecision(10) << ar << ' ' << as << ' ' << ap;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}
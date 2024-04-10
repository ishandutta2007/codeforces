#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1000000007;

inline void add(int& x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int dp[205][205], dp2[205][205][205]; /// CNT/BALANCE/(symbols from S)
int go[2][205];
int n;
string s;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    int balance = 0;
    for (int i = 0; s[i]; ++i)
        balance += s[i] == '(' ? 1 : -1;

    for (int i = 0; i < (int)s.size(); ++i) {
        string cur = s.substr(0, i) + "(";
        for (int j = 0; j <= (int)cur.size(); ++j) {
            if (cur.substr(j, cur.size() - j) == s.substr(0, cur.size() - j)) {
                go[0][i] = cur.size() - j;
                break;
            }
        }

        cur = s.substr(0, i) + ")";
        for (int j = 0; j <= (int)cur.size(); ++j) {
            if (cur.substr(j, cur.size() - j) == s.substr(0, cur.size() - j)) {
                go[1][i] = cur.size() - j;
                break;
            }
        }
    }

    dp[0][0] = dp2[0][0][0] = 1;
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j <= i; ++j) {
            add(dp[i + 1][j + 1], dp[i][j]);
            if (j >= 1)
                add(dp[i + 1][j - 1], dp[i][j]);

            for (int k = 0; k < (int)s.size() && k <= i; ++k) {
                add(dp2[i + 1][j + 1][go[0][k]], dp2[i][j][k]);
                if (j >= 1)
                    add(dp2[i + 1][j - 1][go[1][k]], dp2[i][j][k]);
            }
        }
    }

    int ans = 0;
    for (int i = s.size(); i <= n + n; ++i) {
        for (int j = 0; j <= i; ++j) {
            add(ans, (ll)dp2[i][j][s.size()] * dp[n + n - i][j] % MOD);
        }
    }

    cout << ans;
}
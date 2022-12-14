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

const int maxn = 1e5 + 5, maxm = 251;
int char_idx[128][maxn];
int dp[maxm][maxm][maxm];

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    fill_n(*char_idx, 128 * maxn, n);
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = n - 1; ~i; i--) {
            if (s[i] == c) char_idx[int(c)][i] = i;
            else char_idx[int(c)][i] = char_idx[int(c)][i + 1];
        }
    }

    dp[0][0][0] = -1;
    int p[3] = {0};
    string t[3];
    while (q--) {
        char ct;
        int r;
        cin >> ct >> r;
        r--;

        if (ct == '+') {
            char c;
            cin >> c;
            p[r]++;
            t[r] += c;

            for (int i = r == 0 ? p[0] : 0; i <= p[0]; i++) {
                for (int j = r == 1 ? p[1] : 0; j <= p[1]; j++) {
                    for (int k = r == 2 ? p[2] : 0; k <= p[2]; k++) {
                        dp[i][j][k] = min({
                            n,
                            i ? char_idx[int(t[0][i - 1])]
                                [dp[i - 1][j][k] + 1] : n,
                            j ? char_idx[int(t[1][j - 1])]
                                [dp[i][j - 1][k] + 1] : n,
                            k ? char_idx[int(t[2][k - 1])]
                                [dp[i][j][k - 1] + 1] : n
                        });
                    }
                }
            }
        } else {
            p[r]--;
            t[r].pop_back();
        }

        cout << (dp[p[0]][p[1]][p[2]] != n ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
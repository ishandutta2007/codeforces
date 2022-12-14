#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

int dp[2001][2001];

vector<string> di{
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (auto& i : s) cin >> i;

    vector<vi> costs(n, vi(10));
    rep(i, n) {
        rep(j, 10) {
            int cost = 0;
            rep(r, 7) {
                if (s[i][r] == '1' && di[j][r] == '0') {
                    cost = -1;
                    break;
                }

                if (s[i][r] == '0' && di[j][r] == '1') {
                    cost++;
                }
            }
            costs[i][j] = cost;
        }
    }

    dp[n][0] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j]) {
                rep(r, 10) {
                    int cur = costs[i - 1][r];
                    if (cur != -1 && j + cur <= k) {
                        dp[i - 1][j + cur] |= 1 << cur;
                    }
                }
            }
        }
    }

    if (!dp[0][k]) return cout << -1, 0;

    int cur = k;
    rep(i, n) {
        for (int j = 9; j >= 0; j--) {
            if (costs[i][j] == -1) continue;
            if (dp[i][cur] >> costs[i][j] & 1) {
                cur -= costs[i][j];
                cout << j;
                break;
            }
        }
    }
}
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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll dp[maxn][2];

void solve() {
    string s;
    cin >> s;
    int n = sz(s);

    if (count(all(s), 'm') || count(all(s), 'w')) {
        return void(cout << 0);
    }

    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]
                && (s[i] == 'u' || s[i] == 'n')) {
            dp[i][1] = dp[i - 1][0];
        }
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }

    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
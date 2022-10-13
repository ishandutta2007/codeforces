#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 2005;
ll c[26], f[maxn][26][2], dp[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll q; cin >> q;
    while (q--) {
        ll n; cin >> n;
        fill(c, c+26, 0);
        string s, t; cin >> s >> t;
        for (auto& x : s) c[x-'a']++;
        for (auto& x : t) c[x-'a']--;
        for (ll i = 0; i < 26; i++)
            if (c[i] != 0) {
                cout << "-1\n"; goto next;
            }
        for (int i = n; i > 0; i--)
            for (int k = 0; k < 26; k++) {
                f[i][k][0] = f[i+1][k][0] + (s[i-1]-'a' == k);
                f[i][k][1] = f[i+1][k][1] + (t[i-1]-'a' == k);
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j]+1;
                if (s[i-1] == t[j-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                if (f[i+1][t[j-1]-'a'][0] > f[j+1][t[j-1]-'a'][1])
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        cout << dp[n][n] << "\n";
        next:;
    }
}
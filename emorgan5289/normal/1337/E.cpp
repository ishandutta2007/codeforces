#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s, t; fin >> s >> t;
    int n = s.size(), m = t.size();
    while (t.size() < n) t += '#';

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int len = 1; len <= n; len++)
        for (int a = 0; a <= n-len; a++) {
            int b = a+len-1, i = b-a;
            if (a == b)
                dp[a][b] = (t[a] == '#' || t[a] == s[i]) ? 2 : 0;
            else {
                if (t[a] == '#' || t[a] == s[i])
                    dp[a][b] += dp[a+1][b];
                if (t[b] == '#' || t[b] == s[i])
                    dp[a][b] += dp[a][b-1];
            }
            dp[a][b] %= 998244353;
        }

    ll out = 0;
    for (int i = m-1; i < n; i++)
        out = (out+dp[0][i]) % 998244353;
    cout << out << "\n";
}
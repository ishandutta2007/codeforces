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

const int maxn = 205;
const ll mod = 1000000007;
ll f[maxn][maxn], dp[maxn][maxn][maxn];
vector<int> pre;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    dp[0][0][0] = f[0][0] = 1;
    for (int i = 1; i <= 2*n; i++)
        for (int j = 0; j <= 2*n; j++)
            f[i][j] = ((j == n ? 0 : f[i-1][j+1])+(j == 0 ? 0 : f[i-1][j-1]))%mod;
    ll out = 0;
    for (int i = 0; i < s.size(); i++) {
        bool v = 1;
            for (int j = 0; j < i; j++)
                v &= s[j] == s[s.size()-i+j];
        if (v) pre.pb(i);
    }
    for (int i = 1; i <= 2*n; i++)
        for (int k = 0; k <= n; k++) {
            dp[i][0][k] = (dp[i-1][0][k+1]+(k == 0 ? 0 : dp[i-1][0][k-1]))%mod;
            for (int j = 1; j <= s.size(); j++) {
                int d = s[j-1] == '(' ? -1 : 1;
                dp[i][j][k] = k+d >= 0 ? dp[i-1][j-1][k+d] : 0;
            }
            for (auto& j : pre)
                dp[i][j][k] = (dp[i][j][k]-dp[i][s.size()][k]+mod)%mod;
            out = (out+f[2*n-i][k]*dp[i][s.size()][k])%mod;
        }
    cout << out << "\n";
}
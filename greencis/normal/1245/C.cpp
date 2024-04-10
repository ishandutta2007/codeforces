#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s;
int dp[100105], n;
const int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> s;
    n = s.size();
    dp[0] = 1;
    bool bad = false;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'm' || s[i - 1] == 'w')
            bad = true;
        dp[i] = dp[i - 1];
        if (i >= 2 && s[i - 2] == s[i - 1] && (s[i - 1] == 'u' || s[i - 1] == 'n')) {
            dp[i] += dp[i - 2];
            dp[i] %= mod;
        }
    }
    cout << (bad ? 0 : dp[n]) << endl;
}
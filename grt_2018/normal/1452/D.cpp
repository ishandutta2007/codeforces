#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

const int mod = 998244353, nax = 200 * 1000 + 10;
int n;
int dp[nax];

int inv(int a, int b) {
    int w = 1;
    while(b>0) {
        if(b&1) w = (1LL * w * a)% mod;
        b /= 2;
        a = (1LL * a * a) % mod;
    }
    return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int s0 = 1, s1 = 0, pot = 1;
    for(int i = 1; i <= n; ++i) {
        if(i & 1) {
            dp[i] = s0;
            s1 = (s1 + dp[i]) % mod;
        } else {
            dp[i] = s1;
            s0 = (dp[i] + s0) % mod;
        }
        //cout << dp[i] << " ";
        pot = (pot * 2) % mod;
    }
    int ans = (1LL * dp[n] * inv(pot,mod-2))%mod;
    cout << ans;

}
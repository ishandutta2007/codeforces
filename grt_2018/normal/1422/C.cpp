#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

string s;
const int mod = 1e9 + 7, nax = 1e5 + 10;
int n;
int pw[nax], sum[nax];
ll ans;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = (int)s.size();
    pw[0] = 1;
    sum[0] = 1;
    for(int i = 1; i <= n; ++i) {
        pw[i] = ((ll)pw[i-1] * 10) % mod;
        sum[i] = ((ll)sum[i - 1] + pw[i]) % mod;
    }
    ll cur = 0;
    for(int i = n - 1; i > 0; --i) {
        cur = (cur + (ll)(s[i] - '0') * pw[n-1-i]) % mod;
        ans = (ans + ((ll)i * cur)) % mod;
    }
    cur = 0;
    for(int i = 0; i < n - 1; ++i) {
        cur = (cur * 10 + (s[i] - '0')) % mod;
        //cout << cur << " " << sum[n - 2 - i] << "\n";
        ans = (ans + cur * sum[n - 2 - i]) % mod;
    }
    //cur = (cur * 10 + (s[n-1]-'0')) % mod;
    //ans = (ans + cur) % mod;
    cout << ans;


}
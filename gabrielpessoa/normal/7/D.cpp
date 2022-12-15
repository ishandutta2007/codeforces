#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 5e6+5;
const int shift = 0xdefaced, mod1 = 1e9+7, mod2 = 1073676287;

int dp[ms];

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int h1 = 0, rh1 = 0, h2 = 0, rh2 = 0;
  int t1 = 1, t2 = 1;
  int ans = 0;
  for(int i = 0; i < (int) s.size(); i++) {
    int n = i+1;
    h1 = (h1 * shift + s[i]) % mod1; h2 = (h2 * shift + s[i]) % mod2;
    rh1 = (rh1 + s[i] * t1) % mod1; rh2 = (rh2 + s[i] * t2) % mod2;
    t1 = t1 * shift % mod1; t2 = t2 * shift % mod2;
    if(h1 == rh1 && h2 == rh2) dp[n] = 1 + dp[n/2];
    ans += dp[n];
  }
  cout << ans << endl;
}
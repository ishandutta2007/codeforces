#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n;
    cin >> n;
    map<LL, LL> dp;
    LL add = 0, sum = 1;
    dp[0] = 1;
    for(int i = 1, b; i <= n; i += 1){
      cin >> b;
      LL ch = (mod + sum - dp[0 + add]) % mod;
      add -= b;
      sum = (sum + ch) % mod;
      dp[b + add] = (dp[b + add] + ch) % mod;
      //for(auto [x, y] : dp) cout << (x - add) << " " << y << "\n"; cout << "\n";
    }
    cout << sum << "\n";
  }
  return 0;
}
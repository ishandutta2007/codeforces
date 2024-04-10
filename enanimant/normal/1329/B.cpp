// April 3, 2020
// https://codeforces.com/contest/768/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    long long d, MOD;
    cin >> d >> MOD;
    int h = 0;
    while ((1LL << h) <= d) {
      h++;
    }
    vector<long long> dp(h);
    dp[0] = 1 % MOD;
    long long s = 1 % MOD;
    for (int i = 1; i < h; i++) {
      long long x = (i < h - 1 ? (1 << i) : d + 1 - (1LL << i));
      assert(x >= 0);
      dp[i] = x * (1 + s) % MOD;
      s += dp[i];
      s %= MOD;
    }
    cout << s << '\n';
  }


  return 0;
}
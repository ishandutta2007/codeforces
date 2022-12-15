#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

main() {
  int h, w;
  cin >> h >> w;
  int ans = 4;
  for(int i = 2; i <= h; i++) {
    ans = (ans + ans) % mod;
  }
  for(int i = 2; i <= w; i++) {
    ans = (ans + ans) % mod;
  }
  cout << ans << '\n';
}
#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int dp[N][N][2][2];

int rec(int even, int odd, int ans, int pick) {
  if (even == 0 && odd == 0) {
    return !ans;
  }
  int &ret = dp[even][odd][ans][pick];
  if (ret >= 0) return ret;
  if (pick) {
    ret = 0;
    if (even > 0)
      ret |= rec(even-1, odd, ans, !pick);
    if (odd > 0)
      ret |= rec(even, odd-1, !ans, !pick);
  } else {
    ret = 1;
    if (even > 0)
      ret &= rec(even-1, odd, ans, !pick);
    if (odd > 0)
      ret &= rec(even, odd-1, ans, !pick);
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  int odd = 0, even = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a & 1) {
      ++odd;
    } else {
      ++even;
    }
  }
  cout << (rec(even, odd, 0, 1) ? "Alice" : "Bob") << "\n";
}

int main() {
  memset(dp, -1, sizeof dp);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e6 + 7;
const int K = 3;
int dp[N][1 << K];
vector <int> go[1 << K];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  if (n >= 4) {
    cout << "-1\n";
    exit(0);
  }
  vector <vector <int>> f(n, vector <int> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      f[i][j] = c - '0';
    }
  }
  for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
    for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
      bool ok = true;
      for (int i = 0; i + 1 < n; ++i) {
        int cnt = ((mask1 >> i) & 1) + ((mask2 >> i) & 1) + ((mask1 >> (i + 1)) & 1) + ((mask2 >> (i + 1)) & 1);
        ok &= (cnt % 2 == 1);
      }
      if (ok) go[mask1].push_back(mask2);
    }
  }
  vector <int> fl(m);
  for (int j = 0; j < m; ++j) {
    int mask = 0;
    for (int i = 0; i < n; ++i) {
      if (f[i][j]) {
        mask |= (1 << i);
      }
    }
    fl[j] = mask;
  } 
  for (int mask = 0; mask < (1 << n); ++mask) {
    dp[0][mask] = __builtin_popcount(fl[0] ^ mask);
  }
  for (int i = 1; i < m; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      dp[i][mask] = 1e9;
    }
  }
  for (int i = 0; i + 1 < m; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      for (int nm : go[mask]) {
        dp[i + 1][nm] = min(dp[i + 1][nm], dp[i][mask] + __builtin_popcount(fl[i + 1] ^ nm));
      }
    }
  }
  int ans = 1e9;
  for (int mask = 0; mask < (1 << n); ++mask) {
    ans = min(ans, dp[m - 1][mask]);
  }
  cout << ans << '\n';
}
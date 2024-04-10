#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1 << 30;

int solve(const vector<vector<int>>& a) {
  int n = a[0].size();
  vector<int> dp(1 << n, 0);
  for (const auto& row : a) {
    vector<bool> vis(1 << n);
    for (int s = 0; s < (1 << n); ++s) {
      if (vis[s]) continue;
      int mx = 0;
      for (int i = 0; i < n; ++i) {
        int cyc = (s >> i) | ((s & ((1 << i) - 1)) << (n - i));
        mx = max(dp[cyc], mx);
      }
      for (int i = 0; i < n; ++i) {
        int cyc = (s >> i) | ((s & ((1 << i) - 1)) << (n - i));
        dp[cyc] = mx;
      }
    }
    for (int s = 1; s < (1 << n); ++s)
      for (int i = 0; i < n; ++i)
        if ((s >> i) & 1)
          dp[s] = max(dp[s], dp[s ^ (1 << i)] + row[i]);
  }
  return dp[(1 << n) - 1];
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        scanf("%d", &a[j][i]);
    if (m <= n)
      printf("%d\n", solve(a));
    else {
      vector<pair<int, int>> select(m);
      for (int i = 0; i < m; ++i)
        select[i] = make_pair(*max_element(a[i].begin(), a[i].end()), i);
      nth_element(select.begin(), select.begin() + n, select.end(), greater<pair<int, int>>());
      vector<vector<int>> simplify(n);
      for (int i = 0; i < n; ++i)
        simplify[i] = a[select[i].second];
      printf("%d\n", solve(simplify));
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
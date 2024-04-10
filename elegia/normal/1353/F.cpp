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

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    cin >> a;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        a[i][j] -= i + j;
    ll ans = numeric_limits<ll>::max();
    for (int x = 0; x < n; ++x)
      for (int y = 0; y < m; ++y) {
        vector<vector<ll>> dp(n, vector<ll>(m));
        dp[0][0] = abs(a[0][0] - a[x][y]);
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j) {
            if (a[i][j] < a[x][y]) {
              dp[i][j] = 1LL << 60;
              continue;
            }
            if (i == 0 && j == 0) continue;
            dp[i][j] = 1LL << 60;
            if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            dp[i][j] += a[i][j] - a[x][y];
          }
        ans = min(ans, dp[n - 1][m - 1]);
      }
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
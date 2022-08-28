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
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s, e;
  cin >> n >> s >> e;
  vector<int> x(n), a(n), b(n), c(n), d(n);
  cin >> x >> a >> b >> c >> d;
  const ll INF = 1LL << 60;
  vector<vector<ll>> dp(3, vector<ll>(n, INF));
  dp[1][0] = 0;
  for (int i = 0; i < n; ++i) {
    c[i] += x[i]; d[i] -= x[i];
    b[i] -= x[i]; a[i] += x[i];
    vector<vector<ll>> newDp(3, vector<ll>(n, INF));
    if (i == s - 1) {
      for (int j = 0; j <= 1; ++j)
        for (int k = 0; k < n; ++k)
          newDp[j][k] = min(newDp[j][k], dp[j + 1][k] + c[i]);
      for (int j = 0; j <= 1; ++j)
        for (int k = 0; k < n - 1; ++k)
          newDp[j][k + 1] = min(newDp[j][k + 1], dp[j + 1][k] + d[i]);
    } else if (i == e - 1) {
      for (int j = -1; j <= 0; ++j)
        for (int k = 0; k < n; ++k)
          newDp[j + 2][k] = min(newDp[j + 2][k], dp[j + 1][k] + b[i]);
      for (int j = -1; j <= 0; ++j)
        for (int k = 1; k < n; ++k)
          newDp[j + 2][k - 1] = min(newDp[j + 2][k - 1], dp[j + 1][k] + a[i]);
    } else {
      for (int j = -1; j <= 1; ++j)
        for (int k = 0; k < n; ++k) {
          if (k)
            newDp[j + 1][k] = min(newDp[j + 1][k], dp[j + 1][k] + a[i] + d[i]);
          if (k + j > 0)
            newDp[j + 1][k] = min(newDp[j + 1][k], dp[j + 1][k] + b[i] + c[i]);
          if (k < n - 1)
            newDp[j + 1][k + 1] = min(newDp[j + 1][k + 1], dp[j + 1][k] + b[i] + d[i]);
          if (k)
            newDp[j + 1][k - 1] = min(newDp[j + 1][k - 1], dp[j + 1][k] + a[i] + c[i]);
        }
    }
    newDp[0][0] = INF;
    if (i != n - 1)
      newDp[1][0] = INF;
    dp = newDp;
  }
  cout << dp[1][0];

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
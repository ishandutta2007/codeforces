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

  int t;
  cin >> t;
  while (t--) {
    int d, Mod;
    cin >> d >> Mod;
    vector<int> dp(31);
    auto add = [&](int& x, int y) {
      if ((x += y) >= Mod)
        x -= Mod;
    };
    int ans = 0;
    for (int i = 0; i <= 30; ++i) {
      if ((1U << (i + 1)) <= d) {
        dp[i] = (1U << i) % Mod;
      } else {
        dp[i] = (d - (1 << i) + 1) % Mod;
      }
      int v = 1;
      for (int j = 0; j < i; ++j) add(v, dp[j]);
      dp[i] = dp[i] * (ll)v % Mod;
      add(ans, dp[i]);
      if ((1U << (i + 1)) > d) break;
    }
    cout << ans << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
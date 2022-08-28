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

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

template<class T>
bool chkMax(T &x, const T &y) {
  return (x < y) ? (x = y, true) : false;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto minBit = [&](int x, int i) {
    return __builtin_ctz(x & ~((1 << (i + 1)) - 1));
  };

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> dp(1 << n, vector<int>(n, -1)), cur(1 << n, vector<int>(n));
    vector<vector<vector<pair<int, int>>>> trace(1 << n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n)));
    vector<int> msum(1 << n);
    for (int s = 0; s < (1 << n); ++s)
      for (int i = 0; i < n; ++i)if ((s >> i) & 1)msum[s] += a[i];
    vector<int> sts(1 << n);
    iota(sts.begin(), sts.end(), 0);
    sort(sts.begin(), sts.end(), [&](int x, int y) { return msum[x] < msum[y]; });
    sts.erase(sts.begin());
    for (int s : sts) {
      int u = ((1 << n) - 1) ^s, t = u;
      while (true) {
        int w = __builtin_ctz(s);
        if (chkMax(dp[s][w], 1)) {
          cur[s][w] = msum[s];
          trace[s][w][0] = make_pair(s, -1);
        }
        for (int i = 0; i < n; ++i)
          if (cur[t][i] < msum[s] && dp[t][i] != -1 && (w = minBit(s, i)) < n && w >= 0 &&
              chkMax(dp[s | t][w], dp[t][i] + 1)) {
            cur[s | t][w] = msum[s];
            trace[s | t][w][dp[t][i]] = make_pair(s, i);
          }
        if (!t) break;
        t = (t - 1) & u;
      }
    }
    vector<int> index(n);
    iota(index.begin(), index.end(), 1);
    auto ers = [&](int k) {
      while (k < n)--index[k++];
    };
    int s = (1 << n) - 1, i = max_element(dp[s].begin(), dp[s].end()) - dp[s].begin();
    int ans = dp[s][i];
    cout << (n - ans) << '\n';
    while (s) {
      int t, prv;
      tie(t, prv) = trace[s][i][ans - 1];
      for (int j = 0; j < n; ++j)
        if (((t >> j) & 1) && j != i) {
          cout << index[j] << ' ' << index[i] << '\n';
          ers(j);
        }
      s ^= t;
      i = prv;
      --ans;
    }
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
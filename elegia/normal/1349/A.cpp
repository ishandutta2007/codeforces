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

  int n;
  cin >> n;
  vector<int> a(n); cin >> a;
  int m = *max_element(begin(a), end(a));
  vector<vector<pair<int, int>>> pf(m + 1);
  vector<vector<int>> res(m + 1);
  for (int x = 2; x <= m; ++x) {
    if (pf[x].empty()) {
      for (int y = x; y <= m; y += x) {
        int c = 0, t = y;
        while (t % x == 0) {
          t /= x;
          ++c;
        }
        pf[y].emplace_back(x, c);
      }
    }
  }
  for (int x : a)
    for (auto [p, c] : pf[x])
      res[p].push_back(c);
  ll ans = 1;
  for (int x = 2; x <= m; ++x)
    if (pf[x].size() == 1 && pf[x][0].second == 1) {
      if (res[x].size() >= n - 1) {
        if (res[x].size() == n - 1) res[x].push_back(0);
        nth_element(res[x].begin(), res[x].begin() + 1, res[x].end());
        ans *= pow(x, res[x][1]);
      }
    }
  cout << ans;

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
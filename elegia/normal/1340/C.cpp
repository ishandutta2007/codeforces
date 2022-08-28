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

  int n, m; cin >> n >> m;
  vector<int> d(m); cin >> d;
  sort(begin(d), end(d));
  int g, red; cin >> g >> red;
  --m;
  vector<vector<int>> dis(m, vector<int>(g, numeric_limits<int>::max()));
  int ans = numeric_limits<int>::max();
  deque<pair<int, int>> dq;
  dq.emplace_back(0, 0);
  dis[0][0] = 0;
  while (!dq.empty()) {
    int i, r; tie(i, r) = dq.front(); dq.pop_front();
    if (r + d[m] - d[i] <= g)
      ans = min(ans, dis[i][r] * (g + red) + r + d[m] - d[i]);
    if (i) {
      int x = r + d[i] - d[i - 1];
      if (x == g) {
        if (dis[i - 1][0] > dis[i][r] + 1) {
          dis[i - 1][0] = dis[i][r] + 1;
          dq.emplace_back(i - 1, 0);
        }
      } else if (x < g) {
        if (dis[i - 1][x] > dis[i][r]) {
          dis[i - 1][x] = dis[i][r];
          dq.emplace_front(i - 1, x);
        }
      }
    }
    if (i + 1 < m) {
      int x = r + d[i + 1] - d[i];
      if (x == g) {
        if (dis[i + 1][0] > dis[i][r] + 1) {
          dis[i + 1][0] = dis[i][r] + 1;
          dq.emplace_back(i + 1, 0);
        }
      } else if (x < g) {
        if (dis[i + 1][x] > dis[i][r]) {
          dis[i + 1][x] = dis[i][r];
          dq.emplace_front(i + 1, x);
        }
      }
    }
  }
  cout << (ans == numeric_limits<int>::max() ? -1 : ans);

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
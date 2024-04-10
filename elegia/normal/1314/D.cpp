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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  cin >> a;

  int REP = 10000;
  int ans = numeric_limits<int>::max();
  while (REP--) {
    vector<bool> c(n);
    for (int i = 1; i < n; ++i) c[i] = rng() & 1;
    auto tmp = a;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (c[i] == c[j])
          tmp[i][j] = -1;
    vector<int> dis(n, -1);
    dis[0] = 0;
    for (int rep = 0; rep < k; ++rep) {
      vector<int> newDis(n, -1);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (tmp[i][j] != -1 && dis[i] != -1 && (newDis[j] == -1 || newDis[j] > dis[i] + tmp[i][j]))
            newDis[j] = dis[i] + tmp[i][j];
      dis = newDis;
    }
    if (dis[0] != -1)
      ans = min(ans, dis[0]);
  }
  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
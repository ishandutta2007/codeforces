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
  set<pair<int, int>> st;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i)
    cin >> x[i] >> y[i];
  vector<int> vx(n), vy(n);
  for (int i = 1; i < n; ++i) {
    vx[i] = x[i] - x[i - 1];
    vy[i] = y[i] - y[i - 1];
  }
  vx[0] = x[0] - x[n - 1];
  vy[0] = y[0] - y[n - 1];
  bool fl = true;
  if (n & 1)
    fl = false;
  else {
    for (int i = 0; i < n / 2; ++i)
      if (vx[i] != -vx[i + n / 2] || vy[i] != -vy[i + n / 2])
        fl = false;
  }
  cout << (fl ? "YES" : "nO");

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
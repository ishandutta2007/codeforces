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

struct Frac {
  ll a, b;

  Frac(ll a, ll b = 1) : a(a), b(b) {}

  Frac operator+(const Frac &rhs) const { return Frac(a * rhs.b + b * rhs.a, b * rhs.b); }

  bool operator<(const Frac &rhs) const { return a * rhs.b < b * rhs.a; }
};

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto gval = [&](int h, int c, int t, int m) {
    int res = m;
    Frac ret = 0;
    if (m % 2 == 0)
      ret = Frac(h + c, 2);
    else {
      m /= 2;
      ret = Frac((m + 1LL) * h + m * (ll)c, m * 2 + 1);
    }
    ret = (ret + Frac(-t));
    if (ret.a < 0) ret.a = -ret.a;
    return make_pair(ret, res);
  };

  auto solve = [&](int h, int c, int t) {
    if (t * 2 <= h + c)
      return 2;
    // ((n+1)h + nc)/(2n+1) > t
    int u = (h - t) / (2 * t - h - c);
    return min({gval(h, c, t, 2), gval(h, c, t, u * 2 + 1), gval(h, c, t, u * 2 + 3)}).second;
  };

  int t;
  cin >> t;
  while (t--) {
    int h, c, t;
    cin >> h >> c >> t;
    // (nh+nc)/2n=(h+c)/2
    cout << solve(h, c, t) << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
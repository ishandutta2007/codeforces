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

typedef vector<int> vi;

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
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> wr(r), wg(g), wb(b);
    cin >> wr >> wg >> wb;
    sort((wr).begin(), (wr).end());
    sort((wg).begin(), (wg).end());
    sort((wb).begin(), (wb).end());
    auto sqr = [&](ll x) { return x * x; };
    auto calc = [&](const vi& x, const vi& y, const vi& z) {
      ll ret = numeric_limits<ll>::max();
      int yi = 0, zi = 0;
      for (int i = 0; i < x.size(); ++i) {
        while (yi + 1 < y.size() && y[yi + 1] <= x[i]) ++yi;
        while (zi + 1 < z.size() && z[zi] < x[i]) ++zi;
        ret = min(ret, sqr(x[i] - y[yi]) + sqr(x[i] - z[zi]) + sqr(y[yi] - z[zi]));
      }
      return ret;
    };
    cout << min({calc(wr, wg, wb), calc(wg, wr, wb), calc(wb, wg, wr),
                 calc(wr, wb, wg), calc(wg, wb, wr), calc(wb, wr, wg)}) << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
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

struct Vec {
  ll x, y;

  Vec(ll x, ll y) : x(x), y(y) {}

  Vec operator+(const Vec& rhs) const { return Vec(x + rhs.x, y + rhs.y); }
  Vec operator-(const Vec& rhs) const { return Vec(x - rhs.x, y - rhs.y); }

  ll operator*(const Vec& rhs) const { return x * rhs.y - y * rhs.x; }
};

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<ll> s(n + 1);
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
  vector<Vec> stk;
  stk.emplace_back(0, 0);
  for (int i = 1; i <= n; ++i) {
    Vec ins(i, s[i]);
    while (stk.size() >= 2 && (stk.back() - stk[stk.size() - 2]) * (ins - stk.back()) <= 0) stk.pop_back();
    stk.push_back(ins);
  }
  vector<double> ans(n + 1);
  for (int i = 1; i < stk.size(); ++i)
    for (int j = stk[i - 1].x + 1; j <= stk[i].x; ++j)
      ans[j] = (stk[i].y - stk[i - 1].y) * (j - stk[i - 1].x) / double(stk[i].x - stk[i - 1].x) + stk[i - 1].y;
  for (int i = 0; i < n; ++i)
    printf("%.9f\n", ans[i + 1] - ans[i]);

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
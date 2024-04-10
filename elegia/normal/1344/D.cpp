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
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n);
  cin >> a;

  auto cube = [&](int v) { return v * (ll)v * v; };

  auto calc = [&](int l, int r, int v, ll bd) {
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (v - cube(mid) + cube(mid - 1) >= bd)
        l = mid;
      else
        r = mid - 1;
    }
    //cerr << "fafa " << l << ' ' << v << ' ' << bd << '\n';
    return l;
  };

  auto pred = [&](ll d) {
    for (int i = 0; i < n; ++i)
      b[i] = calc(0, a[i], a[i], d);
    return accumulate(b.begin(), b.end(), 0LL) >= k;
  };

  ll l = -4e18, r = 1e9;

  while (l < r) {
    ll mid = ((r - l + 1) >> 1) + l;
    if (pred(mid))
      l = mid;
    else
      r = mid - 1;
  }
  pred(l);
  vector<int> tmp = b;
  pred(l + 1);
  //cerr << l << ' ' << tmp << '\n';
  k -= accumulate(b.begin(), b.end(), 0LL);
  for (int i = 0; i < n; ++i) {
    //cerr << tmp[i] << ' ' << b[i] << '\n';
    int take = min((ll)tmp[i] - b[i], k);
    k -= take;
    b[i] += take;
  }
  cout << b << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
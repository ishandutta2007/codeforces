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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ll> fa = {0, 2, 3, 1};
  vector<ll> fa2 = {0, 3, 1, 2};


  auto swpbit = [&](ll x, int b) {
    ll ret = 0;
    for (int i = 0; i < b; i += 2) {
      int b0 = (x >> i) & 3;
      ret |= fa[b0] << i;
    }
    return ret;
  };
  auto swpbit2 = [&](ll x, int b) {
    ll ret = 0;
    for (int i = 0; i < b; i += 2) {
      int b0 = (x >> i) & 3;
      ret |= fa2[b0] << i;
    }
    return ret;
  };

  auto cal = [&](ll x) {
    ll l = 1, r = 4;
    int b = 2;
    while (x >= r) {
      l <<= 2;
      b += 2;
      r <<= 2;
    }
    x -= l;
    if (x % 3 == 0)
      return x / 3 + l;
    if (x % 3 == 1) {
      l += l;
      x /= 3;
      return swpbit(x, b) + l;
    }
    l += l * 2;
    x /= 3;
    return swpbit2(x, b) + l;
  };

  int t;
  cin >> t;
  while (t--) {
    ll x;
    cin >> x;
    cout << cal(x) << '\n';
  }

  return 0;
}
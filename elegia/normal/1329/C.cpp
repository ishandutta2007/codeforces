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
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int h, g;
    cin >> h >> g;
    vector<int> a(1 << (h + 1));
    for (int i = 1; i < (1 << h); ++i) cin >> a[i];
    ll ans = accumulate(a.begin(), a.end(), 0LL);
    vector<int> ansvec;
    ansvec.reserve((1 << h) - (1 << g));
    auto pop = [&](int k) {
      ans -= a[k];
      ansvec.push_back(k);
      while (a[k]) {
        if (a[(k << 1) | 1] > a[k << 1]) {
          a[k] = a[(k << 1) | 1];
          k = (k << 1) | 1;
        } else {
          a[k] = a[k << 1];
          k <<= 1;
        }
      }
    };
    auto locate = [&](int k) {
      while (a[k])
        k = (a[(k << 1) | 1] > a[k << 1]) ? ((k << 1) | 1) : (k << 1);
      return k >> 1;
    };
    for (int i = 1; i < (1 << g); ++i) {
      for (int pos = locate(i); pos >= (1 << g); pos = locate(i)) pop(i);
    }
    cout << ans << '\n' << ansvec << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
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
  ll x;
  cin >> n >> x;
  vector<int> d(n);
  cin >> d;
  for (int i = 0; i < n; ++i) d.push_back(d[i]);
  ll ans = 0;
  reverse(d.begin(), d.end());
  ll tot = 0, val = 0;
  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    while (tot < x) {
      tot += d[ptr];
      val += d[ptr] * (d[ptr] + 1LL) / 2;
      ++ptr;
    }
    int dif = tot - x;
    ans = max(ans, val - dif * (dif + 1LL) / 2);

    tot -= d[i];
    val -= d[i] * (d[i] + 1LL) / 2;
  }
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
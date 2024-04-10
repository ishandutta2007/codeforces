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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

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
    int n, m, a, b;
    cin >> n >> m >> b >> a;
    if (n * b != m * a) {
      cout << "NO\n";
    } else {
      // n/a = m/b
      int g = gcd(a, b);
      int x = a / g, y = b / g;
      vector<string> ans(n);
      int v = 0;
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        if (i % x == 0) v = i;
        ans[i].assign(m, '0');
        for (int j = 0; j < b; ++j)
          ans[i][(j + v / x * y) % m] = '1';
        cout << ans[i] << '\n';
      }
    }
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
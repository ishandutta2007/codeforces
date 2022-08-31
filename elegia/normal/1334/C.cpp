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
    int n;
    cin >> n;
    vector<ll> a(n * 2), b(n * 2);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    if (n == 1) {
      cout << a[0] << '\n';
      continue;
    }
    for (int i = 0; i < n; ++i) {
      a[i + n] = a[i];
      b[i + n] = b[i];
    }
    ll sum = a[0];
    for (int i = 1; i < n; ++i) {
      sum += max(a[i] - b[i - 1], 0LL);
    }
    ll ans = sum;
    for (int i = 1; i < n; ++i) {
      sum -= a[i - 1] + max(a[i] - b[i - 1], 0LL);
      sum += a[i] + max(a[i + n - 1] - b[i + n - 2], 0LL);
      ans = min(ans, sum);
    }
    cout << ans << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
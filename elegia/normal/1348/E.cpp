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

const int N = 200010;

int a[N], b[N];
pair<int, int> ins[N];
int ans[N];

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  vector<int> can(k);
  can[0] = 1;
  for (int i = 0; i < n; ++i) {
    vector<int> ndp(k);
    for (int j = 0; j < k; ++j)
      ndp[(j + a[i]) % k] = can[j];
    for (int j = max(k - b[i], 0); j <= min(a[i], k); ++j) {
      for (int t = 0; t < k; ++t)
        ndp[(t + a[i] - j) % k] |= can[t];
    }
    can = ndp;
  }
  ll ans = numeric_limits<ll>::min();
  int r = 0;
  for (int i = 0; i < n; ++i)
    r = (r + a[i] % k + b[i] % k) % k;
  //cerr << can << '\n';
  for (int i = 0; i < k; ++i)
    if (can[i])
      ans = max(ans, -(ll)(i + (r + k - i) % k));
  for (int i = 0; i < n; ++i)
    ans += a[i] + (ll)b[i];
  cout << (ans / k);

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
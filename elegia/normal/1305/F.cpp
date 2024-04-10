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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int N = 200010;

int n, ans;
ll a[N];

vector<ll> fact(ll x) {
  vector<ll> pf;
  int y;
  for (y = 2; y * (ll) y <= x; ++y) {
    if (x % y == 0) {
      while (x % y == 0) x/= y;
      pf.push_back(y);
    }
  }
  if (x != 1) pf.push_back(x);
  return pf;
}

void upd(ll x) {
  ll cur = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < x) {
      cur += x - a[i];
      continue;
    }
    ll r = a[i] % x;
    cur += min(r, x - r);
  }
  if (cur < ans)
    ans = cur;
}

void test(ll x) {
  vector<ll> pf = fact(x);
  for (ll p : pf)
    upd(p);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  shuffle(a, a + n, rng);
  ans = n;
  for (int i = 0; i < min(n, 40); ++i) {
    test(a[i]);
    if (a[i] > 1) test(a[i] - 1);
    test(a[i] + 1);
  }
  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
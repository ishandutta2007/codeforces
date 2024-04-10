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

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n + 1) / 2; ++i) cin >> a[i];
  int x;
  cin >> x;
  for (int i = (n + 1) / 2; i < n; ++i) a[i] = x;

  auto chk = [&](int k) {
    ll s = 0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
      if (i >= k) s -= a[i - k];
      if (i >= k - 1 && s <= 0)
        return false;
    }
    return true;
  };
  if (x >= 0) {
    if (chk(n)) cout << n << '\n';
    else cout << "-1\n";
  } else {
    vector<int> cnt(n + 1);
    ll sum = 0;
    for (int i = (n + 1) / 2 - 1; i >= 0; --i) {
      sum += a[i];
      if (sum > 0) {
        ll req = min((sum - 1) / -x, n / 2LL);
        ++cnt[req + (n + 1) / 2 - i];
      }
    }
    for (int i = n - 1; i; --i) cnt[i] += cnt[i + 1];


    bool fl = false;
    for (int i = (n + 1) / 2; i <= n; ++i)
      if (cnt[i] == n - i + 1) {
        fl = true;
        cout << i << '\n';
        break;
      }
    if (!fl)
      cout << "-1\n";
  }


#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
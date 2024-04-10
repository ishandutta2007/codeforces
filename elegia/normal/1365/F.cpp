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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    bool ans = true;
    if (n & 1) {
      if (a[n / 2] != b[n / 2])
        ans = false;
    }
    vector<pair<int, int>> x, y;
    for (int i = 0; i * 2 + 2 <= n; ++i) {
      if (a[i] > a[n - 1 - i]) swap(a[i], a[n - 1 - i]);
      x.emplace_back(a[i], a[n - 1 - i]);
      if (b[i] > b[n - 1 - i]) swap(b[i], b[n - 1 - i]);
      y.emplace_back(b[i], b[n - 1 - i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (x != y)ans = false;
    cout << (ans ? "Yes\n" : "No\n");
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
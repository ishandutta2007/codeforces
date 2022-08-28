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

template <class T>
void chkMax(T& x, const T& y) {
  if (x < y) x = y;
}

template <class T>
void chkMin(T& x, const T& y) {
  if (x > y) x = y;
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
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    pair<int, ll> dp0(-1, -1), dp1(-1, -1);
    for (int x : a) {
      if (x > 0) {
        chkMax(dp1, make_pair(1, (ll)x));
        chkMax(dp1, make_pair(dp0.first + 1, dp0.second + x));
      } else {
        chkMax(dp0, make_pair(1, (ll)x));
        chkMax(dp0, make_pair(dp1.first + 1, dp1.second + x));
      }
    }
    cout << max(dp0, dp1).second << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
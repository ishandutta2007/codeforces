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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    cin >> a;
    string ans = a[0];
    bool fl = false;
    auto check = [&]() {
      for (const auto &str : a) {
        int dist = 0;

        for (int i = 0; i < m; ++i)
          if (str[i] != ans[i])
            ++dist;
        if (dist > 1) return false;
      }
      return true;
    };
    for (int i = 0; i < m; ++i) {
      for (char c = 'a'; c < 'z' + 1; ++c) {
        ans[i] = c;
        if (check()) {
          fl = true;
          break;
        }
      }
      if (fl) break;
      ans[i] = a[0][i];
    }
    if (fl) cout << ans << '\n';
    else cout << "-1\n";
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
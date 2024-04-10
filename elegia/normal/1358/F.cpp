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

  auto imp = [&]() {
    cout << "IMPOSSIBLE\n";
    exit(0);
  };

  const int LIM = 2e5;

  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  cin >> a >> b;
  ll tot = 0;
  string ans = "";
  if (n == 1) {
    if (a != b) {
      imp();
    } else {

    }
  } else if (n == 2) {
    while (true) {
      if (a == b) break;
      {
        reverse(b.begin(), b.end());
        if (a == b) {
          ans.push_back('R');
          break;
        }
        reverse(b.begin(), b.end());
      }
      if (!is_sorted(b.begin(), b.end())) {
        ans.push_back('R');
        reverse(b.begin(), b.end());
      }
      if (!is_sorted(b.begin(), b.end()) || b[0] == 0)
        imp();
      ll modi = min((b[0] + b[1] - a[0] - a[1]) / b[0], b[1] / b[0]);
      if (modi <= 0)
        imp();
      tot += modi;
      if (tot <= LIM) {
        for (int rep = 0; rep < modi; ++rep)
          ans.push_back('P');
      }
      b[1] -= b[0] * modi;
    }
  } else {
    while (true) {
      if (a == b) break;
      {
        reverse(b.begin(), b.end());
        if (a == b) {
          ans.push_back('R');
          break;
        }
        reverse(b.begin(), b.end());
      }
      if (!is_sorted(b.begin(), b.end())) {
        ans.push_back('R');
        reverse(b.begin(), b.end());
      }
      if (!is_sorted(b.begin(), b.end()) || b[0] == 0)
        imp();
      if (++tot <= LIM)
        ans.push_back('P');
      for (int i = n - 1; i; --i)
        b[i] -= b[i - 1];
    }
  }

  reverse(ans.begin(), ans.end());

  if (tot <= LIM) {
    cout << "SMALL\n" << ans.size() << '\n' << ans << '\n';
  } else {
    cout << "BIG\n" << tot << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
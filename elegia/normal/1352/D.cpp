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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int l = 0, r = n - 1, cur = 0;
    int sum = accumulate(a.begin(), a.end(), 0);
    int ans = 0, x = 0, y = 0;
    bool fl = false;
    while (sum) {
      ++ans;
      if (sum <= cur) {
        (fl ? y : x) += sum;
        break;
      }
      int val = 0;
      if (!fl) {
        while (val <= cur) val += a[l++];
        sum -= val;
        x += val;
      } else {
        while (val <= cur) val += a[r--];
        sum -= val;
        y += val;
      }
      cur = val;
      fl = !fl;
    }
    cout << ans << ' ' << x << ' ' << y << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
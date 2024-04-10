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
    int n; ll l, r;
    cin >> n >> l >> r;
    --l;
    vector<int> ans;
    if (l == 0) ans.push_back(1);
    ll cnt = 1;
    for (int i = 2; i < n; ++i) {
      if (cnt >= l && cnt < r) ans.push_back(i); ++cnt;
      if (cnt >= l && cnt < r) ans.push_back(1); ++cnt;
    }
    if (cnt >= l && cnt < r) ans.push_back(n); ++cnt;
    for (int i = 2; i < n; ++i) {
      if (cnt >= l && cnt < r) ans.push_back(i); ++cnt;
      int len = (n - i - 1) * 2;
      ll vl = max(cnt, l), vr = min(cnt + len, r);
      for (ll j = vl; j < vr; ++j) {
        if ((j - cnt) % 2 == 0) ans.push_back((j - cnt) / 2 + i + 1);
        else ans.push_back(i);
      }
      cnt += len;
      if (cnt >= l && cnt < r) ans.push_back(n); ++cnt;
    }
    if (cnt >= l && cnt < r) ans.push_back(1); ++cnt;
    cout << ans << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
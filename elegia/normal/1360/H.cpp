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
    vector<ll> a;
    set<ll> st;
    for (int rep = 0; rep < n; ++rep) {
      string s;
      cin >> s;
      ll x = 0;
      for (int i = 0; i < m; ++i)
        x = (x << 1) + (s[i] - '0');
      a.push_back(x);
      st.insert(x);
    }
    ll tot = ((1LL << m) - n - 1) / 2;
    ll l = 0, r = (1LL << m) - 1;
    while (l < r) {
      ll mid = (l + r + 1) >> 1;
      ll cnt = mid;
      for (ll x : a) if (x < mid) --cnt;
      if (cnt > tot) r = mid - 1;
      else
        l = mid;
    }
    while (st.count(l)) ++l;
    string ans;
    for (int i = 0; i < m; ++i) {
      ans.push_back('0' + (l & 1));
      l >>= 1;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
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

  map<char, pair<int, int>> mp;
  mp['N'] = {0, 1};
  mp['S'] = {0, -1};
  mp['W'] = {1, 0};
  mp['E'] = {-1, 0};

  int t;
  cin >> t;
  while (t--) {
    set<pair<pair<int, int>, pair<int, int>>> st;
    int x = 0, y = 0;
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s) {
      int dx, dy;
      tie(dx, dy) = mp[c];
      int nx = x + dx, ny = y + dy;
      pair<int, int> pr(x, y), qr(nx, ny);
      if (st.insert(make_pair(min(pr, qr), max(pr, qr))).second)
        ans += 5;
      else
        ans += 1;
      x = nx;
      y = ny;
    }
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
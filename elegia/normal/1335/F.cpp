#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <stack>
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
  mp['U'] = {-1, 0};
  mp['D'] = {+1, 0};
  mp['L'] = {0, -1};
  mp['R'] = {0, +1};

  int t;
  cin >> t;
  stack<int> stk;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> color(n), dir(n);
    cin >> color >> dir;
    auto gind = [&](int x, int y) { return x * m + y; };
    vector<int> f(n * m), col(n * m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        col[gind(i, j)] = color[i][j] == '0';
        f[gind(i, j)] = gind(i + mp[dir[i][j]].first, j + mp[dir[i][j]].second);
      }
    vector<int> oncirc(n * m, -1), p(n * m, -1), o(n * m, -1);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n * m; ++i) {
      if (oncirc[i] != -1) continue;
      int x = i;
      while (oncirc[x] == -1) {
        oncirc[x] = 2;
        x = f[x];
      }
      while (oncirc[x] == 2) {
        oncirc[x] = 1;
        p[f[x]] = x;
        o[x] = x;
        x = f[x];
      }
      x = i;
      while (oncirc[x] == 2) {
        stk.push(x);
        oncirc[x] = 0;
        x = f[x];
      }
      while (!stk.empty()) {
        o[stk.top()] = p[o[x]];
        x = stk.top();
        stk.pop();
      }
    }
    ans1 = count((oncirc).begin(), (oncirc).end(), 1);
    for (int i = 0; i < n * m; ++i)
      if (!oncirc[i]) col[o[i]] |= col[i];
    for (int i = 0; i < n * m; ++i)
      if (oncirc[i]) ans2 += col[i];
    cout << ans1 << ' ' << ans2 << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
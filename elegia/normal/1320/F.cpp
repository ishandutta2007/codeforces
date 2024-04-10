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
    for (int x = 1; x < v.size(); ++x)
      os << ' ' << v[x];
  }
  return os;
}

void gg() {
  cout << "-1\n";
  exit(0);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<vector<int>>> ans(n, vector<vector<int>>(m, vector<int>(k, -1)));
  vector<vector<int>> xp(m, vector<int>(k)), xn(m, vector<int>(k)),
                      yp(n, vector<int>(k)), yn(n, vector<int>(k)),
                      zp(n, vector<int>(m)), zn(n, vector<int>(m)),
                      pxp(m, vector<int>(k)), pxn(m, vector<int>(k, n - 1)),
                      pyp(n, vector<int>(k)), pyn(n, vector<int>(k, m - 1)),
                      pzp(n, vector<int>(m)), pzn(n, vector<int>(m, k - 1));
  cin >> xp >> xn >> yp >> yn >> zp >> zn;
  queue<tuple<int, int, int>> q;
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < m; ++y)
      for (int z = 0; z < k; ++z)
        if (!(xp[y][z] && xn[y][z] && yp[x][z] && yn[x][z] && zp[x][y] && zn[x][y]))
          ans[x][y][z] = 0;
  function<void(int, int)> exx = [&](int y, int z) {
    while (pxp[y][z] < n && !ans[pxp[y][z]][y][z]) ++pxp[y][z];
    while (pxn[y][z] >= 0 && !ans[pxn[y][z]][y][z]) --pxn[y][z];
    if (pxp[y][z] >= n || pxn[y][z] < 0) gg();
    q.emplace(pxp[y][z], y, z);
    q.emplace(pxn[y][z], y, z);
  };
  function<void(int, int)> exy = [&](int x, int z) {
    while (pyp[x][z] < m && !ans[x][pyp[x][z]][z]) ++pyp[x][z];
    while (pyn[x][z] >= 0 && !ans[x][pyn[x][z]][z]) --pyn[x][z];
    if (pyp[x][z] >= m || pyn[x][z] < 0) gg();
    q.emplace(x, pyp[x][z], z);
    q.emplace(x, pyn[x][z], z);
  };
  function<void(int, int)> exz = [&](int x, int y) {
    while (pzp[x][y] < k && !ans[x][y][pzp[x][y]]) ++pzp[x][y];
    while (pzn[x][y] >= 0 && !ans[x][y][pzn[x][y]]) --pzn[x][y];
    if (pzp[x][y] >= k || pzn[x][y] < 0) gg();
    q.emplace(x, y, pzp[x][y]);
    q.emplace(x, y, pzn[x][y]);
  };
  for (int y = 0; y < m; ++y)
    for (int z = 0; z < k; ++z) {
      if (bool(xp[y][z]) != bool(xn[y][z])) gg();
      if (!xp[y][z]) continue;
      exx(y, z);
    }
  for (int x = 0; x < n; ++x)
    for (int z = 0; z < k; ++z) {
      if (bool(yp[x][z]) != bool(yn[x][z])) gg();
      if (!yp[x][z]) continue;
      exy(x, z);
    }
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < m; ++y) {
      if (bool(zp[x][y]) != bool(zn[x][y])) gg();
      if (!zp[x][y]) continue;
      exz(x, y);
    }
  while (!q.empty()) {
    int x, y, z;
    tie(x, y, z) = q.front();
    q.pop();
    if (ans[x][y][z] == 0) continue;
    vector<int> col;
    if (pxp[y][z] == x) col.push_back(xp[y][z]);
    if (pxn[y][z] == x) col.push_back(xn[y][z]);
    if (pyp[x][z] == y) col.push_back(yp[x][z]);
    if (pyn[x][z] == y) col.push_back(yn[x][z]);
    if (pzp[x][y] == z) col.push_back(zp[x][y]);
    if (pzn[x][y] == z) col.push_back(zn[x][y]);
    if (col.size() == 0) continue;
    col.erase(unique(col.begin(), col.end()), col.end());
    if (col.size() == 1) {
      ans[x][y][z] = col.back();
      continue;
    }
    ans[x][y][z] = 0;
    exx(y, z);
    exy(x, z);
    exz(x, y);
  }
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      for (int z = 0; z < k; ++z)
        if (ans[x][y][z] == -1)
          ans[x][y][z] = 0;
      cout << ans[x][y] << '\n';
    }
    cout << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
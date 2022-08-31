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

  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  cin >> grid;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = m, r = -1;
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        l = min(l, j);
        r = j;
      }
    }
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == '.' && l < j && j < r)
        ans = -1;
  }
  for (int i = 0; i < m; ++i) {
    int l = n, r = -1;
    for (int j = 0; j < n; ++j) {
      if (grid[j][i] == '#') {
        l = min(l, j);
        r = j;
      }
    }
    for (int j = 0; j < n; ++j)
      if (grid[j][i] == '.' && l < j && j < r)
        ans = -1;
  }
  if (ans == -1) {
    cout << "-1\n";
    return 0;
  }
  vector<int> row(n), col(m);
  function<void(int, int)> dfs = [&](int i, int j) {
    row[i] = true;
    col[j] = true;
    grid[i][j] = '.';
    if (i > 0 && grid[i - 1][j] == '#') dfs(i - 1, j);
    if (j > 0 && grid[i][j - 1] == '#') dfs(i, j - 1);
    if (i + 1 < n && grid[i + 1][j] == '#') dfs(i + 1, j);
    if (j + 1 < m && grid[i][j + 1] == '#') dfs(i, j + 1);
  };
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == '#') {
        dfs(i, j);
        ++ans;
      }
  int u = count(row.begin(), row.end(), false), v = count(col.begin(), col.end(), false);
  if ((u == 0 && v) || (v == 0 && u))
    ans = -1;
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
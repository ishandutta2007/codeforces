#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

vector <int> dx = {0, 0, -1, 1};
vector <int> dy = {-1, 1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <int>> a(n, vector <int> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      a[i][j] = (c == '#');
    }
  }
  int emp_r = 0, emp_c = 0;
  bool bad = false;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    int mn = m, mx = -1;
    for (int j = 0; j < m; ++j) {
      if (a[i][j]) {
        ++sum;
        mn = min(mn, j);
        mx = max(mx, j);
      }
    }
    if (sum != 0 && mx - mn + 1 != sum) {
      bad = true;
    }
    if (sum == 0) ++emp_r;
  }

  for (int j = 0; j < m; ++j) {
    int sum = 0;
    int mn = n, mx = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i][j]) {
        ++sum;
        mn = min(mn, i);
        mx = max(mx, i);
      }
    }
    if (sum != 0 && mx - mn + 1 != sum) {
      bad = true;
    }
    if (sum == 0) ++emp_c;
  }
  if (bad) {
    cout << "-1\n";
    return 0;
  }
  if (emp_r > 0 && emp_c == 0) {
    cout << "-1\n";
    return 0;
  }
  if (emp_c > 0 && emp_r == 0) {
    cout << "-1\n";
    return 0;
  }
  vector <int> p(n * m); 
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j]) {
        p[i * m + j] = i * m + j;
        ++ans;
      }
    }
  }
  function <int(int)> get = [&] (int a) {
    return (a == p[a] ? a : p[a] = get(p[a]));
  };
  auto join = [&] (int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
      --ans;
      p[a] = b;
    }
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (0 <= x && x < n && 0 <= y && y < m) {
          if (a[i][j] && a[x][y]) {
            join(i * m + j, x * m + y);
          }
        }
      }
    }
  }
  cout << ans << '\n';
}
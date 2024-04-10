#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, m, q;

struct Solver {
  void set(int i, int j, int val) {
    upd(fen[i], j, val);
    what[i][j] += val;
  }
  void upd(int f[], int pos, int val) {
    for (; pos <= 1002; pos |= (pos + 1))
      f[pos] += val;
  }
  int fnd(int f[], int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
      ret += f[pos];
    return ret;
  }
  int findFrom(int i, int j) {
    if (what[i][j] == 0) return 0;
    int st = fnd(fen[i], j - 1), sum = 0, pos = -1;
    for (int t = 10; t >= 0; --t) {
      int nval = 0;
      if (pos >= j) nval = sum + (1<<t);
      else if (pos + (1<<t) < j) nval = sum + fen[i][pos + (1<<t)];
      else {
        nval = st + (pos + (1<<t) - j + 1);
      }
      // cout << t << "  " << pos << " " << nval << "  " << sum << " " << fen[i][pos + (1<<t)] << endl; 
      if (pos + (1<<t) <= 1002 && (pos + (1<<t) < j || sum + fen[i][pos + (1<<t)] == nval)) {
        // sum += (1<<t);
        sum = nval;
        pos += (1<<t);
      }
    }
    return pos - j + 1;
  }
  int solve(int x, int y) {
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i) {
      v.push_back(make_pair(findFrom(i, y), i));
    }
    sort(v.begin(), v.end());
    int ans = 0, up = 1, bottom = n, it = 0;
    for (int w = 1; w <= m; ++w) {
      while (it < v.size() && v[it].first < w) {
        if (v[it].second <= x) up = max(up, v[it].second + 1);
        if (v[it].second >= x) bottom = min(bottom, v[it].second - 1);
        ++it;
      }
      ans = max(ans, w * (bottom - up + 1));
    }
    return ans;
  }
  int fen[1005][1005];
  int what[1005][1005];
};

Solver f[4];

void rot(int& x, int& y) {
  int nx = y, ny = n - x + 1;
  swap(n, m);
  x = nx; y = ny;
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int a;
      scanf("%d", &a);
      if (a == 1) {
        int x = i, y = j;
        for (int it = 0; it < 4; ++it) {
          f[it].set(x, y, 1);
          rot(x, y);
        }
      }
    }
  }
  for (int t = 0; t < q; ++t) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      for (int it = 0; it < 4; ++it) {
        int add = f[it].what[x][y] == 0 ? 1 : -1;
        f[it].set(x, y, add);
        rot(x, y);
      }
    } else {
      int ans = 0;
      for (int it = 0; it < 4; ++it) {
        ans = max(ans, f[it].solve(x, y));
        rot(x, y);
      }
      printf("%d\n", ans);
    }
  }
  // f[0].set(3, 1, 1);
  // cout << f[0].what[1][3] << endl;
  // cout << f[0].findFrom(3, 1) << endl;
  return 0;
}
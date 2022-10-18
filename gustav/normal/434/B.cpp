#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MAX = 1005;

int N, M, Q;
int b[MAX][MAX];

struct Board {
  bool transposed;
  bool flippedX;
  bool flippedY;

  int n, m;

  int h[MAX][MAX];
  int l[MAX];
  int r[MAX];

  void fix(int &x, int &y) {
    if (transposed) swap(x, y);
    if (flippedX) x = n - x - 1;
  }

  void unfix(int &x, int &y) {
    if (flippedX) x = n - x - 1;
    if (transposed) swap(x, y);
  }

  Board(bool t, bool fx) {
    n = N; m = M;
    transposed = t;
    flippedX = fx;

    memset(h, 0, sizeof h);

    if (t) swap(n, m);

    REP(j, m) REP(i, n) {
      unfix(i, j);
      int v = b[i][j];
      fix(i, j);
      if (v) {
	++h[i][j];
	h[i + 1][j] += h[i][j];
      } else {
	h[i][j] = 0;
      }
    }
  }

  void update(int x, int y) {
    int v = b[x][y];
    fix(x, y);

    if (v) {
      h[x][y] = 1;
      if (x) h[x][y] += h[x - 1][y];
    } else {
      h[x][y] = 0;
    }

    for (int i = x + 1; i < n; ++i) {
      if (h[i][y])
	h[i][y] = 1 + h[i - 1][y];
      else
	break;
    }
  }

  int query(int x, int y) {
    fix(x, y);

    stack< int > stk;
    int ret = 0;

    for (int i = 0; i < m; ++i) {
      while (!stk.empty() && h[x][stk.top()] >= h[x][i]) stk.pop();
      l[i] = stk.empty() ? 0 : stk.top() + 1;
      stk.push(i);
    }

    while (!stk.empty()) stk.pop();
    for (int i = m - 1; i >= 0; --i) {
      while (!stk.empty() && h[x][stk.top()] >= h[x][i]) stk.pop();
      r[i] = stk.empty() ? m - 1 : stk.top() - 1;
      stk.push(i);
    }

    REP(i, m)
      if (y >= l[i] && y <= r[i])
	ret = max(ret, (r[i] - l[i] + 1) * h[x][i]);

    return ret;
  }
};

vector< Board > boards;

int main(void)
{
  scanf("%d%d%d", &N, &M, &Q);
  REP(i, N) REP(j, M) scanf("%d", &b[i][j]);

  REP(i, 2) REP(j, 2) boards.push_back(Board(i, j));

  REP(i, Q) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y); --x; --y;
    if (op == 1) {
      b[x][y] ^= 1;
      for (auto &B : boards)
	B.update(x, y);
    } else {
      int ret = 0;
      for (auto &B : boards)
	ret = max(ret, B.query(x, y));
      printf("%d\n", ret);
    }
  }

  return 0;
}
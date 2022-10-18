#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int inf = 1e8;
const int off = 1 << 18; ////////////////

namespace Tournament {
  struct Node {
    int dp[5][5];
  };

  Node tree[off << 1];

  Node inf_node() {
    Node ret;
    REP(i, 5) REP(j, 5) ret.dp[i][j] = inf;
    return ret;
  }

  Node neutral_node() {
    Node ret = inf_node();
    REP(i, 5) ret.dp[i][i] = 0;
    return ret;
  }

  Node leaf(char c) {
    Node ret = neutral_node();

    if (c == '2') ret.dp[0][0] = 1, ret.dp[0][1] = 0;
    if (c == '0') ret.dp[1][1] = 1, ret.dp[1][2] = 0;
    if (c == '1') ret.dp[2][2] = 1, ret.dp[2][3] = 0;
    if (c == '7') ret.dp[3][3] = 1, ret.dp[3][4] = 0;
    if (c == '6') ret.dp[3][3] = 1, ret.dp[4][4] = 1;

    return ret;
  }

  Node merge(const Node &a, const Node &b) {
    Node ret = inf_node();
    REP(i, 5) FOR(j, i, 5) {
      ret.dp[i][j] = inf;
      FOR(k, i, j + 1)
	ret.dp[i][j] = min(ret.dp[i][j], a.dp[i][k] + b.dp[k][j]);
    }
    return ret;
  }

  Node query(int a, int b, int lo = 0, int hi = off, int i = 1) {
    if (lo >= b || hi <= a) return neutral_node();
    if (lo >= a && hi <= b) return tree[i];

    return merge(query(a, b, lo, (lo + hi) / 2, 2 * i),
		 query(a, b, (lo + hi) / 2, hi, 2 * i + 1));
  }

  void build(int i, char *c) {
    if (i >= off) {
      tree[i] = leaf(c[i - off]);
      return;
    }

    build(2 * i, c);
    build(2 * i + 1, c);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  }
};

const int MAXN = off;

int n, q;
char c[MAXN + 1];

int main(void) 
{
  scanf("%d%d", &n, &q);
  scanf("%s", c);

  FOR(i, n, off) c[i] = '0';
  Tournament :: build(1, c);

  REP(i, q) {
    int a, b;
    scanf("%d%d", &a, &b); --a, --b;

    int ret = Tournament :: query(a, b + 1).dp[0][4];
    if (ret == inf)
      puts("-1");
    else
      printf("%d\n", ret);
  }

  return 0;
}
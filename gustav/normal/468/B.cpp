#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

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

namespace sat {
  const int MAXN = 300005;
  vector< int > G[2 * MAXN];

  int stk[2 * MAXN], top;
  int got[2 * MAXN];
  int com[2 * MAXN], ccom;
  int val[MAXN];

  int dis[2 * MAXN], tick;
  int low[2 * MAXN];

  void init() {
    REP(i, 2 * MAXN) G[i].clear();
    memset(stk, 0, sizeof stk);
    memset(com, 0, sizeof com);
    memset(val, -1, sizeof val);
    top = ccom = tick = 0;
  }

  void imply(int a, int b) {
    G[a].push_back(b);
    G[b ^ 1].push_back(a ^ 1);
  }

  void disable(int x) { imply(x, x ^ 1); }
  void force(int x) { imply(x ^ 1, x); }

  bool tarjan(int n) {
    dis[n] = low[n] = ++tick;
    stk[top++] = n;
    got[n] = true;

    for (int m : G[n]) {
      if (dis[m] && got[m]) {
        low[n] = min(low[n], dis[m]);
      } else {
        if (!tarjan(m)) return false;
        low[n] = min(low[n], low[m]);
      }
    }

    if (low[n] != dis[n]) return true;
    
    ++ccom;
    
    int m = -1;
    do {
      m = stk[--top];
      got[m] = false;
      com[m] = ccom;

      if (com[m ^ 1] == com[m]) return false;
      if (val[m / 2] == -1) val[m / 2] = m % 2;
    } while (m != n);

    return true;
  }

  bool solve() {
    REP(i, 2 * MAXN) {
      if (dis[i]) continue;
      if (!tarjan(i)) return false;
    }
    return true;
  }

  int get(int x) {
    return val[x];
  }
};

#define MAXN 100005

int n, a, b;
int p[MAXN];
map< int, int > m;

int main(void)
{
  scanf("%d%d%d", &n, &a, &b);
  REP(i, n) scanf("%d", p + i);
  REP(i, n) m[p[i]] = i;

  int t = n;
  REP(i, n) {
    if (!m.count(a - p[i])) m[a - p[i]] = t++;
    if (!m.count(b - p[i])) m[b - p[i]] = t++;
  }

  sat :: init();
  REP(i, n) {
    int x = p[i];
    sat :: imply(2 * m[x] + 1, 2 * m[b - x] + 1);
    sat :: imply(2 * m[x], 2 * m[a - x]);

    if (m[b - x] >= n) sat :: force(2 * i);
    if (m[a - x] >= n) sat :: force(2 * i + 1);
  }

  if (!sat :: solve())
    puts("NO");
  else {
    puts("YES");
    REP(i, n) printf("%d ", sat :: get(i));
    puts("");
  }

  return 0;
}
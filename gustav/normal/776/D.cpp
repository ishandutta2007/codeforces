#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

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

const int MAXN = 100005;

namespace sat {
  const int MAX = MAXN * 2;
  int CMAX;
  vector< int > G[2 * MAX];

  int stk[2 * MAX], top;
  int got[2 * MAX];
  int com[2 * MAX], ccom;
  int val[MAX];

  int dis[2 * MAX], tick;
  int low[2 * MAX];

  void init(int cmax) {
    CMAX = cmax;
    REP(i, 2 * CMAX) {
      G[i].clear();
      stk[i] = 0;
      com[i] = 0;
      val[i] = -1;
      dis[i] = 0;
      low[i] = 0;
    }
    top = ccom = tick = 0;
  }

  void add_implies(int a, int b) {
    G[a].push_back(b);
    G[b ^ 1].push_back(a ^ 1);
  }

  void add_or(int a, int b) {
    add_implies(a ^ 1, b);
    add_implies(b ^ 1, a);
  }

  void disable(int x) { add_implies(x, x ^ 1); }
  void force(int x) { add_implies(x ^ 1, x); }

  bool tarjan(int n) {
    dis[n] = low[n] = ++tick;
    stk[top++] = n;
    got[n] = true;

    for (int m : G[n]) {
      if (dis[m] && got[m]) {
        low[n] = min(low[n], dis[m]);
      } else if (!dis[m]) {
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
    REP(i, 2 * MAX) {
      if (dis[i]) continue;
      if (!tarjan(i)) return false;
    }
    return true;
  }

  int get(int x) {
    return val[x];
  }
};

int n, m;
int r[MAXN];
vector<int> v[MAXN];

int main(void)
{
  scanf("%d%d", &n, &m);
  sat::init(m);

  REP(i, n) { scanf("%d", r + i); r[i] ^= 1; }

  REP(i, m) {
    int k; 
    scanf("%d", &k);
    REP(j, k) {
      int x;
      scanf("%d", &x); --x;
      v[x].push_back(i);
    }
  }

  REP(i, n) {
    assert(v[i].size() == 2);
    int a = v[i][0];
    int b = v[i][1];
    if (r[i] == 0) {
      sat::add_implies(2 * a, 2 * b);
      sat::add_implies(2 * b, 2 * a);
    } else {
      sat::add_or(2 * a + 1, 2 * b + 1);
      sat::add_or(2 * a, 2 * b);
    }
  }

  puts(sat::solve() ? "YES" : "NO");

  return 0;
}
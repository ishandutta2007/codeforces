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

#define MAXN 200005

int di[MAXN];
int cpos[2];
int pos[2][MAXN];
int to[2][MAXN];

vector< int > T[MAXN];

void dfs(int n, int dep = 0, int dad = -1) {
  di[n] = dep % 2;
  pos[di[n]][n] = cpos[di[n]];
  pos[di[n]^1][n] = cpos[di[n]^1];
  ++cpos[di[n]];
  
  for (auto m : T[n]) {
    if (m == dad) continue;
    dfs(m, dep + 1, n);
  }

  to[di[n]][n] = cpos[di[n]] - 1;
  to[di[n]^1][n] = cpos[di[n]^1] - 1;
}

int n, m;
int a[MAXN];
int type, u, v;

struct fenwick {
  int f[MAXN];

  fenwick() { memset(f, 0, sizeof f); }

  void add(int pos, int v) {
    for (int i = pos + 1; i < MAXN; i += i & -i)
      f[i] += v;
  }

  void update(int l, int r, int v) {
    if (l > r) return;
    add(l, v); add(r + 1, -v);
  }

  int get(int pos) {
    int ret = 0;
    for (int i = pos + 1; i; i -= i & -i)
      ret += f[i];
    return ret;
  }

  void output() {
    REP(i, n)
      printf("%d ", get(i));
    puts("");
  }
};

fenwick f[2];


int main(void)
{
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", &a[i]);

  REP(i, n - 1) {
    scanf("%d%d", &u, &v); --u; --v;
    T[u].push_back(v);
    T[v].push_back(u);
  }

  dfs(0);

  REP(i, m) {
    scanf("%d%d", &type, &u); --u;
    int d = di[u];
    if (type == 1) {
      scanf("%d", &v);
      f[d].update(pos[d][u], to[d][u], v);
      f[d ^ 1].update(pos[d ^ 1][u], to[d ^ 1][u], -v);
    } else {
      printf("%d\n", a[u] + f[d].get(pos[d][u]));
    }
  }

  return 0;
}
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

#define MAXN 100005
#define MAXV 2000005

int n, q;
int x, y;
int type, v, w;
int a[MAXN];

int dep[MAXN];
vector< int > T[MAXN];
vector< int > pfs[MAXV];

int f[MAXV];
int sol[MAXN];

void dfs(int n, int dad = -1, int d = 0) {
  dep[n] = d;
  for (auto m : T[n])
    if (m != dad)
      dfs(m, n, d + 1);
}

void rebuild(int n, int dad = -1) {
  int best = -2;
  for (int v = a[n]; v != 1; v /= f[v]) {
    if (!pfs[f[v]].empty()) {
      int cur = pfs[f[v]].back();
      if (cur != n && (best == -2 || dep[cur] > dep[best])) {
        best = cur;
      }
    }
    pfs[f[v]].push_back(n);
  }

  sol[n] = best;

  for (auto m : T[n])
    if (m != dad)
      rebuild(m, n);
  
  for (int v = a[n]; v != 1; v /= f[v]) 
    pfs[f[v]].pop_back();
}

int main(void)
{
  for (int i = 1; i < MAXV; ++i) {
    if (f[i] > 1) continue;
    for (int j = i; j < MAXV; j += i)
      f[j] = i;
  }

  scanf("%d%d", &n, &q);

  REP(i, n) scanf("%d", a + i);

  REP(i, n - 1) {
    scanf("%d%d", &x, &y); --x; --y;
    T[x].push_back(y);
    T[y].push_back(x);
  }


  dfs(0);
  rebuild(0);

  REP(i, q) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &v); --v;
      printf("%d\n", sol[v] + 1);
    } else {
      scanf("%d%d", &v, &w); --v;
      a[v] = w;
      rebuild(0);
    }
  }

  return 0;
}
#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 200005;
const int inf = 1000000000;

int last[26];
int a[26];
int f[MAXN];
char T[MAXN]; int n, t[MAXN];
char P[MAXN]; int m, p[MAXN];

void transform(char *s, int *x, int n) {
  memset(last, -1, sizeof last);
  REP(i, n) {
    int y = s[i] -'a';
    x[i] = last[y] >= 0 ? i - last[y] : inf;
    last[y] = i;
  }
}

bool bad(int i, int *t, int j, int *p) {
  /*
  TRACE(i _ j);
  TRACE(t[i] _ p[j]);
  TRACE(min(j + 1, t[i]) _ min(j + 1, p[j]));*/
  return min(j + 1, t[i]) != min(j + 1, p[j]);
}

int main(void) 
{
  scanf("%d%d", &n, &m);
  scanf("%s", T); transform(T, t, n);
  scanf("%s", P); transform(P, p, m);

  f[0] = -1;
  FOR(i, 1, m) {
    f[i] = f[i - 1];
    while (f[i] >= 0 && bad(i, p, f[i] + 1, p)) f[i] = f[f[i]];
    if (!bad(i, p, f[i] + 1, p)) ++f[i];
  }

  vector< int > sol;
  int j = -1;
  REP(i, n) {
    while (j >= 0 && bad(i, t, j + 1, p)) j = f[j];
    if (!bad(i, t, j + 1, p)) ++j;

    if (j == m - 1) {
      bool ok = true;
      REP(k, 26) a[k] = k;
      REP(k, 26) {
	if (last[k] >= 0) {
	  int y = T[i - j + last[k]] - 'a';
	  if (a[k] == y && a[y] == k) continue;
	  if (a[k] != k || a[y] != y) { ok = false; continue; }
	  a[k] = y;
	  a[y] = k;
	}
      }
      REP(k, 26) if (a[a[k]] != k) ok = false;
      if (ok) sol.push_back(i - j + 1);
      j = f[j];
    }
  }

  printf("%d\n", (int)sol.size());
  REP(i, (int)sol.size())
    printf("%d%c", sol[i], " \n"[i + 1 == (int)sol.size()]);

  return 0;
}
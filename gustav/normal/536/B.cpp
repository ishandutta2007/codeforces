#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 1000005;

int n, m;
char p[MAXN];
char s[MAXN];
int y[MAXN];
int f[MAXN];

int main(void) 
{
  scanf("%d%d", &n, &m);
  scanf("%s", p);
  REP(i, m) { scanf("%d", y + i); --y[i]; }

  f[0] = -1;
  int len = strlen(p);
  FOR(i, 1, len) {
    f[i] = f[i - 1];
    while (f[i] >= 0 && p[i] != p[f[i] + 1]) f[i] = f[f[i]];
    if (p[i] == p[f[i] + 1]) ++f[i];
  }

  set< int > prefs;
  for (int i = len - 1; i != -1; i = f[i])
    prefs.insert(i + 1);

  REP(i, m - 1) {
    int d = y[i] + len - y[i + 1];
    if (d > 0 && d < len && prefs.find(d) == prefs.end()) {
      puts("0");
      exit(0);
    }
  }

  memset(s, '?', sizeof s);
  for (int i = m - 1; i >= 0; --i) 
    for (int j = 0; j < len && s[y[i] + j] == '?'; ++j)
      s[y[i] + j] = p[j];

  int sol = 1;
  REP(i, n) if (s[i] == '?') sol = sol * 26LL % 1000000007;

  printf("%d\n", sol);

  return 0;
}
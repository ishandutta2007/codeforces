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

const int MAXN = 1000005;

int n, k;
char s[MAXN];
int f[MAXN];
int lnk[MAXN][20];
int good[MAXN];

int main(void) 
{
  scanf("%d%d", &n, &k);
  scanf("%s", s);

  if (k == 1) {
    REP(i, n) putchar('1');
    puts("");
    exit(0);
  }

  f[0] = -1;
  memset(lnk[0], -1, sizeof lnk[0]);

  FOR(i, 1, n) {
    f[i] = f[i - 1];
    while (f[i] != -1 && s[f[i] + 1] != s[i])
      f[i] = f[f[i]];
    if (s[f[i] + 1] == s[i]) ++f[i];
    lnk[i][0] = f[i];
    FOR(j, 1, 20) {
      int last = lnk[i][j - 1];
      if (last == -1) lnk[i][j] = -1;
      else lnk[i][j] = lnk[lnk[i][j - 1]][j - 1];
    }
  }

  int pos = 0;
  REP(i, n) {
    int len = f[i] + 1;
    if (2 * len < i + 1) continue;

    int it = f[i];
    if ((i + 1) < (llint)k * (i + 1 - len)) continue;

    for (int j = 19; j >= 0; --j) {
      int c = lnk[it][j];
      int clen = c + 1;
      if (2 * clen < i + 1) continue;
      if ((i + 1) < (llint)k * (i + 1 - clen)) continue;
      it = c;
    }

    len = it + 1;
    if ((i + 1) > (llint)k * (i + 1 - len)) continue;
    assert((i + 1) == (llint)k * (i + 1 - len));

    int slen = i + 1 - len;
    if (pos > i + slen) continue;
    if (pos > i && f[pos] + 1 < (pos - i)) continue;
    else if (pos <= i) {
      good[i] = 1;
      pos = i + 1;
    }

    while (pos < n && pos <= i + slen && s[pos] == s[pos - i - 1]) {
      good[pos] = 1;
      ++pos;
    }
  }

  REP(i, n) if (good[i]) putchar('1'); else putchar('0');
  puts("");

  return 0;
}
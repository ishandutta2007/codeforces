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
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 5005;
const int mod = 1e9 + 7;

int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return add(a, mod - b); }
int mul(int a, int b) { return (llint)a * b % mod; }

int n;
int ch[MAXN][MAXN];
int f[26][MAXN];
int g[MAXN];
char s[MAXN];

void calc_ch() {
  REP(i, MAXN) REP(j, MAXN) {
    if (i < j) ch[i][j] = 0;
    else if (i == j || j == 0) ch[i][j] = 1;
    else ch[i][j] = add(ch[i-1][j-1], ch[i-1][j]);
  }
}

int main(void) 
{
  calc_ch();

  scanf("%d", &n);
  scanf("%s", s);

  REP(i, n) {
    int c = s[i] - 'a';

    for (int k = i + 1; k >= 2; --k) {
      int nfck = sub(g[k - 1], f[c][k - 1]);
      g[k] = sub(g[k], f[c][k]);
      f[c][k] = nfck;
      g[k] = add(g[k], f[c][k]);
    }

    g[1] = sub(g[1], f[c][1]);
    f[c][1] = 1;
    g[1] = add(g[1], f[c][1]);
  }

  int sol = 0;
  FOR(k, 1, n + 1) 
    sol = add(sol, mul(g[k], ch[n - 1][k - 1]));

  printf("%d\n", sol);

  return 0;
}
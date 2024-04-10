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
const int mod = 1e9 + 7;

int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (llint)a * b % mod; }

int power(int a, int b) {
  int ret = 1;
  for (int i = 0; (1 << i) <= b; ++i) {
    if (((b >> i) & 1) == 1) 
      ret = mul(ret, a);
    a = mul(a, a);
  }
  return ret;
}

int inverse(int n) { return power(n, mod - 2); }

int down[MAXN];
int up[MAXN];
int p[MAXN];

vector< int > T[MAXN];
vector< int > suff[MAXN];

void dfs(int i) {
  for (auto j : T[i]) dfs(j);
  down[i] = 1;
  for (auto j : T[i]) down[i] = mul(down[i], add(down[j], 1));
  int m = T[i].size();
  if (m) {
    suff[i][m - 1] = add(down[T[i][m - 1]], 1);
    for (int j = m - 2; j >= 0; --j)
      suff[i][j] = mul(suff[i][j + 1], add(down[T[i][j]], 1));
  }
}

void dfs2(int i) {
  // up[i] imam vec

  int pref = 1;
  int m = T[i].size();
  REP(j, m) {
    int now = pref;
    if (j + 1 < m) now = mul(now, suff[i][j + 1]);
    up[T[i][j]] = mul(add(up[i], 1), now);
    pref = mul(pref, add(down[T[i][j]], 1));
    dfs2(T[i][j]);
  }
}

int main(void) 
{
  int n;
  scanf("%d", &n);
  FOR(i, 2, n + 1) {
    scanf("%d", p + i);
    T[p[i]].push_back(i);
  }

  FOR(i, 1, n + 1) 
    suff[i].resize(T[i].size(), 0);

  dfs(1);
  dfs2(1);

  /*
  FOR(i, 1, n + 1) down[i] = 1;
  for (int i = n; i >= 1; --i) 
    down[p[i]] = mul(down[p[i]], add(1, down[i]));

  up[1] = 0;
  FOR(i, 2, n + 1) 
    up[i] = mul(mul(down[p[i]], add(up[p[i]], 1)), inverse(add(down[i], 1)));
  */

  FOR(i, 1, n + 1)
    printf("%d%c", mul(add(up[i], 1), down[i]), " \n"[i == n]);

  return 0;
}
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

const llint inf = 1000000000000000001;

#define MAXN 100005

int suf[2 * MAXN];
int d[2 * MAXN];
int A[2 * MAXN][4];
int sink, alloc;

void init() {
  memset(suf, -1, sizeof suf);
  memset(A, -1, sizeof A);
}

void extend(char c) {
  int a = c - 'A';
  int newsink = ++alloc;

  A[sink][a] = newsink;
  d[newsink] = d[sink] + 1;

  int w = suf[sink];
  while (w != -1 && A[w][a] == -1) {
    A[w][a] = newsink;
    w = suf[w];
  }

  if (w == -1) suf[newsink] = 0;
  else if (d[A[w][a]] == d[w] + 1) suf[newsink] = A[w][a];
  else {
    int newnode = ++alloc;
    int v = A[w][a];

    memcpy(A[newnode], A[v], sizeof A[v]);
    A[w][a] = newnode;
    d[newnode] = d[w] + 1;
    suf[newsink] = newnode;
    suf[newnode] = suf[v];
    suf[v] = newnode;

    w = suf[w];
    while (w != -1 && A[w][a] == v && d[w] + 1 != d[v]) {
      A[w][a] = newnode;
      w = suf[w];
    }
  }

  sink = newsink;
}

void build(const char *s) {
  int n = strlen(s);
  REP(i, n) extend(s[i]);
}

int dp[2 * MAXN][4];

int f(int n, int a) { // najkraci put do cvora koji nema a izlazni
  int &ret = dp[n][a];
  if (ret >= 0) return ret;
  if (A[n][a] == -1) return ret = 0;

  ret = 1000000;
  REP(i, 4) ret = min(ret, 1 + f(A[n][i], a));

  return ret;
}

struct matrix { matrix() { memset(m, 0, sizeof m); } llint m[4][4]; };

llint add(llint a, llint b) {
  if (a >= inf || b >= inf || a + b >= inf)
    return inf;
  return a + b;
}

llint mul(llint a, llint b) {
  if (b == 0) return 0;
  llint h = mul(a, b / 2);
  h = add(h, h);
  if (b % 2) h = add(h, a);
  return h;
}

void mul(matrix &a, matrix &b) {
  matrix r;
  REP(i, 4) REP(j, 4) r.m[i][j] = inf;
  REP(i, 4) REP(j, 4) REP(k, 4) r.m[i][j] = min(r.m[i][j], add(a.m[i][k], b.m[k][j]));
  memcpy(a.m, r.m, sizeof r.m);
}

matrix power(matrix a, llint p) {
  matrix r;
  REP(i, 4) r.m[i][i] = 1;

  for (int i = 0; (1LL << i) <= p; ++i) {
    if (((p >> i) & 1) == 1) mul(r, a);
    mul(a, a);
  }
  
  return r;
}

llint n;
string s;

int main(void)
{
  cin >> n;
  cin >> s;

  if (n == 1) {
    puts("1");
    return 0;
  }

  init();
  build(s.c_str());

  memset(dp, -1, sizeof dp);
  matrix m;

  REP(i, 4) REP(j, 4) m.m[i][j] = f(A[0][i], j) + 1;

  llint lo = 1, hi = n, mid;

  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    matrix p = power(m, mid);

    bool some_less = false;

    REP(i, 4) REP(j, 4) if (p.m[i][j] < n) some_less = true;

    if (some_less)
      lo = mid;
    else 
      hi = mid - 1;
  }

  m = power(m, lo);
  
  cout << lo + 1 << endl;

  return 0;
}
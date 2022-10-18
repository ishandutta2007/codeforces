#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>

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

const int MAXK = 505;
const int MAXN = 205;
const int MAXM = 21;
const int MAXLEN = 205;
const int MAXS = 205;

int n, m, k;
int len;
int ll, l[MAXLEN];
int rl, r[MAXLEN];
int buf[MAXLEN];

int f[MAXS];
int e[MAXS]; // sto vodi do tu?
int matches[MAXS];
int trie[MAXS][MAXM];
int alloc = 1;

void trie_insert(int n, int *x, int len, int val) {
  if (len == 0) {
    matches[n] += val;
    return;
  }

  if (!trie[n][*x]) {
    trie[n][*x] = ++alloc;
    e[alloc] = *x;
  }

  trie_insert(trie[n][*x], x + 1, len - 1, val);
}

void build() {
  queue< int > q;

  f[1] = 1;
  REP(i, m) {
    int c = trie[1][i];
    if (c) {
      f[trie[1][i]] = 1;
      q.push(trie[1][i]);
    }
  }

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    matches[cur] += matches[f[cur]];

    REP(i, m) {
      int child = trie[cur][i];
      if (!child) continue;

      int &fc = f[child];
      int ec = e[child];
      fc = f[cur];

      while (fc != 1 && !trie[fc][ec])
	fc = f[fc];

      if (trie[fc][ec])
	fc = trie[fc][ec];

      q.push(child);
    }
  }

  REP(i, m) if (!trie[1][i]) trie[1][i] = 1; else q.push(trie[1][i]);

  while (!q.empty()) {
    int cur = q.front(); q.pop();

    REP(i, m) {
      if (trie[cur][i])
	q.push(trie[cur][i]);
      else 
	trie[cur][i] = trie[f[cur]][i];
    }
  }
}

const int mod = 1000000007;

int add(int a, int b) { return (a + b) % mod; }

int memo[MAXN][MAXS][MAXK];

int solve(int pos, int state, int value, int start, int tl, int tr) {
  if (value > k) return 0;
  if (pos == len) return start;
  
  bool memoize = !tl && !tr;

  if (memoize && memo[pos][state][value] >= 0)
    return memo[pos][state][value];

  int ret = 0;
  int lo = tl ? l[pos] : 0;
  int hi = tr ? r[pos] : m - 1;

  for (int i = lo; i <= hi; ++i) {
    int nstart = start || i != 0;
    int nstate = nstart ? trie[state][i] : 1;
    int nvalue = value + (nstart ? matches[nstate] : 0);
    ret = add(ret, solve(pos + 1, nstate, nvalue, nstart, tl && i == lo, tr && i == hi));
  }

  if (memoize)
    memo[pos][state][value] = ret;

  return ret;
}

int main(void)
{
  scanf("%d%d%d", &n, &m, &k);

  scanf("%d", &ll); REP(i, ll) scanf("%d", l + i);
  scanf("%d", &rl); REP(i, rl) scanf("%d", r + i);

  len = max(ll, rl) + 1;
  reverse(l, l + ll); reverse(l, l + len);
  reverse(r, r + rl); reverse(r, r + len);

  REP(i, n) {
    int r, v;
    scanf("%d", &r);
    REP(j, r) scanf("%d", buf + j);
    scanf("%d", &v);
    trie_insert(1, buf, r, v);
  }

  build();
  memset(memo, -1, sizeof memo);
  printf("%d\n", solve(0, 1, 0, 0, 1, 1));

  return 0;
}
#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int off = 1 << 20;
const int MAXN = 1000005;

int t[off << 1];

void update(int i, int v) {
  i += off; t[i] = v;
  for (i /= 2; i; i /= 2)
    t[i] = max(t[2 * i], t[2 * i + 1]);
}

int query(int l, int r, int lo, int hi, int n) {
  if (hi <= l || lo >= r) return 0;
  if (lo >= l && hi <= r) return t[n];
  return max(query(l, r, lo, (lo + hi) / 2, 2 * n),
	     query(l, r, (lo + hi) / 2, hi, 2 * n + 1));
}

int reach[MAXN];
vector< int > L[MAXN];
vector< int > R[MAXN];

int ll[MAXN], ln[MAXN];
int rr[MAXN], rn[MAXN];

vector< int > sol;
void solve(int l, int r) {
  if (l > r) return;
  //printf("solve %d %d\n", l, r);

  int n = l;
  ll[n] = l;
  rr[n] = r;
  if (L[n].empty()) {
    rn[n] = l + 1;
    sol.push_back(n);
    solve(l + 1, r);
  } else if (R[n].empty()) {
    ln[n] = l + 1;
    solve(l + 1, r);
    sol.push_back(n);
  } else {
    int to = reach[l + 1];
    for (int j : L[n]) {
      //printf("kverijam %d %d\n", n, reach[j]);
      to = max(to, query(n + 1, reach[j] + 1, 0, off, 1));
    }
    //printf("to za %d %d = %d\n", l, r, to);
    for (int j : R[n]) {
      if (j <= to) {
	puts("IMPOSSIBLE");
	exit(0);
      }
    }
    if (to > r) {
      puts("IMPOSSIBLE");
      exit(0);
    } else {
      ln[n] = l + 1;
      rn[n] = to + 1;
      solve(l + 1, to);
      sol.push_back(n);
      solve(to + 1, r);
    }
  }
}

char buf[10];

int main(void) 
{
  int n, c;
  scanf("%d%d", &n, &c);

  REP(i, c) {
    int a, b;
    scanf("%d%d%s", &a, &b, buf);

    if (buf[0] == 'L')
      L[a].push_back(b);
    else
      R[a].push_back(b);

    if (a >= b) {
      puts("IMPOSSIBLE");
      exit(0);
    }
  }

  for (int i = n; i >= 1; --i) {
    reach[i] = i;
    for (int j : L[i])
      reach[i] = max(reach[i], query(i, reach[j] + 1, 0, off, 1));
    for (int j : R[i])
      reach[i] = max(reach[i], query(i, reach[j] + 1, 0, off, 1));
    update(i, reach[i]);

    //TRACE(i _ reach[i]);
  }

  solve(1, n);
  /*
  for (int i : sol)
    printf("%d ", i);
  puts("");
  */

  bool ok = true;
  for (int i = 1; i <= n; ++i) {
    for (int j : L[i]) ok = ok && j >= ll[ln[i]] && j <= rr[ln[i]];
    for (int j : R[i]) ok = ok && j >= ll[rn[i]] && j <= rr[rn[i]];
  }
  /*
  for (int i = 1; i <= n; ++i) {
    for (int j : L[i]) {
      if (!(j >= ll[ln[i]] && j <= rr[ln[i]]))
	TRACE(i _ ln[i] _ ll[ln[i]] _ rr[ln[i]] _ j);
    }
    for (int j : R[i]) {
      if (!(j >= ll[rn[i]] && j <= rr[rn[i]]))
	TRACE(i _ rn[i] _ ll[rn[i]] _ rr[rn[i]] _ j);
    }
  }
  */

  if (!ok) {
    //    puts("IMPOSSIBLE");
    assert(false);
  }

  for (int i : sol)
    printf("%d ", i);
  puts("");

  return 0;
}
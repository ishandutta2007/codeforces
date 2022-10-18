#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int off = 1 << 18;

int n, q;
int a[off];

int lazy[off << 1];
vector< int > T[off << 1];

void gauss(vector< int > &M) {
  int n = M.size();
  int r = 0;

  if (M.empty()) return;

  for (int c = 31; c >= 0; --c) {
    FOR(i, r, n) 
      if (((M[i] >> c) & 1) == 1)
	swap(M[r], M[i]);

    if (((M[r] >> c) & 1) == 0)
      continue;

    REP(i, n) {
      if (i == r) continue;
      if (((M[i] >> c) & 1) == 0)
	continue;
      M[i] ^= M[r];
    }

    ++r;
    if (r == n) break;
  }

  while (!M.empty() && M.back() == 0) M.pop_back();
}

void merge(vector< int > &L, vector< int > &R, vector< int > &I) {
  I.clear();
  for (int x : L) I.push_back(x);
  for (int x : R) I.push_back(x);
  gauss(I);
}

void build(int i) {
  if (i >= off) return;

  build(2 * i);
  build(2 * i + 1);

  merge(T[2 * i], T[2 * i + 1], T[i]);
}

void propagate(int i) {
  for (int &x : T[2 * i])
    if (x % 2 == 1) x ^= lazy[i];

  gauss(T[2 * i]);

  for (int &x : T[2 * i + 1])
    if (x % 2 == 1) x ^= lazy[i];

  gauss(T[2 * i + 1]);

  lazy[2 * i] ^= lazy[i];
  lazy[2 * i + 1] ^= lazy[i];

  lazy[i] = 0;
}

void query(int l, int r, vector< int > &v, int lo, int hi, int i) {
  if (lo >= r || hi <= l) return;
  if (lo >= l && hi <= r) {
    for (int x : T[i])
      v.push_back(x);
    return;
  }

  propagate(i);

  query(l, r, v, lo, (lo + hi) / 2, 2 * i);
  query(l, r, v, (lo + hi) / 2, hi, 2 * i + 1);
}

void update(int l, int r, int x, int lo, int hi, int i) {
  if (lo >= r || hi <= l) return;
  if (lo >= l && hi <= r) {
    lazy[i] ^= x;

    for (int &y : T[i])
      if (y % 2 == 1)
	y ^= x;

    gauss(T[i]);

    return;
  }

  propagate(i);

  update(l, r, x, lo, (lo + hi) / 2, 2 * i);
  update(l, r, x, (lo + hi) / 2, hi, 2 * i + 1);

  merge(T[2 * i], T[2 * i + 1], T[i]);
}

int main(void) 
{
  scanf("%d%d", &n, &q);
  REP(i, n) scanf("%d", a + i);

  REP(i, n) 
    T[off + i].push_back(2 * a[i] + 1);

  build(1);

  vector< int > v;

  REP(i, q) {
    int t;
    scanf("%d", &t);

    if (t == 1) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k); --l;
      update(l, r, 2 * k, 0, off, 1);
    } else {
      int l, r;
      scanf("%d%d", &l, &r); --l;

      v.clear();
      query(l, r, v, 0, off, 1);

      gauss(v);
      for (int &x : v) x /= 2;
      gauss(v);


      if (v.empty())
	puts("1");
      else
	printf("%lld\n", 1LL << ((int)v.size()));
    }
  }

  return 0;
}
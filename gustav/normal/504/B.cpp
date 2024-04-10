#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 200005;

struct Fenwick {
  int f[MAXN];

  void inc(int x, int v) {
    for (int i = x + 1; i < MAXN; i += i & -i)
      f[i] += v;
  }
  
  void add(int x) { inc(x, +1); }
  void rem(int x) { inc(x, -1); }

  int lt(int x) {
    int ret = 0;
    for (int i = x; i; i -= i & -i)
      ret += f[i];
    return ret;
  }

  int kth(int k) {
    int lo = 0, hi = MAXN - 1, mid;
    while (lo < hi) {
      mid = (lo + hi + 1) / 2;
      if (lt(mid) > k)
	hi = mid - 1;
      else
	lo = mid;
    }
    return lo;
  }
};

Fenwick f;

vector< int > ord(vector< int > &p) {
  int n = (int)p.size();
  vector< int > o(n, 0);

  REP(i, n) f.add(i);
  REP(i, n) {
    o[i] = f.lt(p[i]);
    f.rem(p[i]);
  }

  return o;
}

vector< int > perm(vector< int > &o) {
  int n = (int)o.size();
  vector< int > p(n, 0);

  REP(i, n) f.add(i);
  REP(i, n) {
    p[i] = f.kth(o[i]);
    f.rem(p[i]);
  }

  return p;
}

vector< int > add(vector< int > &a, vector< int > &b) {
  int n = (int)a.size();
  vector< int > ret(n, 0);

  REP(i, n) ret[i] = a[i] + b[i];
  
  for (int i = n - 1; i >= 0; --i) {
    if (ret[i] >= n - i) {
      if (i) ret[i - 1] += ret[i] / (n - i);
      ret[i] %= (n - i);
    }
  }

  return ret;
}

vector< int > a, oa;
vector< int > b, ob;

int main(void) 
{
  int n;
  scanf("%d", &n);

  a.resize(n, 0); REP(i, n) scanf("%d", &a[i]); oa = ord(a);
  b.resize(n, 0); REP(i, n) scanf("%d", &b[i]); ob = ord(b);

  vector< int > osol = add(oa, ob);

  vector< int > sol = perm(osol);

  REP(i, n) printf("%d ", sol[i]);
  puts("");

  return 0;
}
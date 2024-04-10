#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;
const int off = 1 << 18;
typedef long long llint;

#define L(n) (2 * (n))
#define R(n) (L(n) + 1)

struct Node {
  llint len;
  llint bl;
  llint br;
  llint sol;

  void output() {
    TRACE(len _ bl _ br _ sol);
  }
};

Node merge(Node l, Node r) {
  Node ret;
  if (l.len == -1) return r;
  if (r.len == -1) return l;
  ret.len = l.len + r.len;
  ret.bl = max(l.bl, r.bl + l.len);
  ret.br = max(r.br, l.br + r.len);
  ret.sol = max(max(l.sol, r.sol), l.br + r.bl);
  return ret;
}

Node T[off << 1];

void build(int n) {
  if (n >= off) return;
  build(L(n));
  build(R(n));
  T[n] = merge(T[L(n)], T[R(n)]);
}

Node query(int l, int r, int lo, int hi, int n) {
  if (lo >= r || hi <= l) return {-1, 0, 0, 0};
  if (lo >= l && hi <= r) return T[n];
  return merge(
	       query(l, r, lo, (lo + hi) / 2, L(n)),
	       query(l, r, (lo + hi) / 2, hi, R(n)));
}

int n, m;
int d[MAXN];
int h[MAXN];

int main(void) 
{
  scanf("%d%d", &n, &m);

  REP(i, n) scanf("%d", d + i);
  REP(i, n) scanf("%d", h + i);

  REP(i, 2 * n) {
    int it = i + off;
    int D = d[i % n];
    int H = h[i % n];
    T[it].bl = 2LL * H;
    T[it].br = 2LL * H + D;
    T[it].len = D;
    T[it].sol = 0;
  }

  build(1);

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;

    if (a > b) {
      cout << query(b + 1, a, 0, off, 1).sol << endl;
    } else {
      cout << query(b + 1, a + n, 0, off, 1).sol << endl;
    }
  }

  return 0;
}
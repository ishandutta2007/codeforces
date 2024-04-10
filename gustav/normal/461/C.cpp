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
const int inf = 1000000000;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int off = (1 << 17);

int t[off << 1];

void update(int x, int v) {
  t[x += off] += v;
  for (x /= 2; x; x /= 2)
    t[x] = t[2 * x] + t[2 * x + 1];
}

int query(int lo, int hi, int l, int r, int n) {
  if (l >= hi || r <= lo) return 0;
  if (l >= lo && r <= hi) return t[n];

  int m = (l + r) / 2;
  return query(lo, hi, l, m, 2 * n) +
         query(lo, hi, m, r, 2 * n + 1);
}

bool flipped;
int L, R; // paper position

void fold(int p) {
  int q = R - L + 1 - p;

  if (p <= q && !flipped) {
    REP(i, p) update(L + p + i, t[off + L + p - 1 - i]);
    L += p;
  } else if (p > q && !flipped) {
    flipped = !flipped;
    REP(i, q) update(L + p - 1 - i, t[off + L + p + i]);
    R -= q;
  } else if (p <= q && flipped) {
    swap(p, q);
    REP(i, q) update(L + p - 1 - i, t[off + L + p + i]);
    R -= q;
  } else if (p > q && flipped) {
    flipped = !flipped;
    swap(p, q);
    REP(i, p) update(L + p + i, t[off + L + p - 1 - i]);
    L += p;
  }
}

int ask(int l, int r) {
  --r;

  if (!flipped) {
    return query(L + l, L + r + 1, 0, off, 1);
  }
  else {
    return query(R - r, R - l + 1, 0, off, 1);
  }
}

int N, Q;
int type, p, l, r;

int main(void)
{
  cin >> N >> Q;
  REP(i, N) update(i, 1);
  L = 0, R = N - 1;

  REP(i, Q) {
    cin >> type;
    if (type == 1) {
      cin >> p;
      fold(p);
    } else {
      cin >> l >> r;
      cout << ask(l, r) << endl;
    }
  }


  return 0;
}
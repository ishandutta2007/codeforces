#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

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
#define log(...) //fprintf(stderr, ##__VA_ARGS__)

const int inf = 1000000000;

#define L(n) ((n) << 1)
#define R(n) (L(n) | 1)

int n, q;
int r1, c1;
int r2, c2;

const int off = 1 << 19;

int a[off];
int hibit[off];

typedef pair< int, int > pii;

struct rmqq {
  pii rmq[19][off];

  rmqq() {
    memset(rmq, 0x3f, sizeof rmq);
  }

  void build() {
    FOR(i, 1, 19) REP(j, n) 
      rmq[i][j] = min(rmq[i - 1][j], (j + (1 << (i - 1)) < off) ? rmq[i - 1][j + (1 << (i - 1))] : pii(inf, inf));
  }

  pii get(int l, int r) {
    ++r;
    int b = hibit[r - l];
    return min(rmq[b][l], rmq[b][r - (1 << b)]);
  }
};

rmqq min_val;
rmqq min_l;
rmqq min_r;

int main(void)
{
  FOR(i, 2, off) {
    if (i == (i & -i)) 
      hibit[i] = hibit[i - 1] + 1;
    else 
      hibit[i] = hibit[i - 1];
  }

  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);

  REP(i, n) {
    min_val.rmq[0][i] = { a[i], a[i] };
    min_l.rmq[0][i] = { a[i] - 2 * i, a[i] };
    min_r.rmq[0][i] = { a[i] + 2 * i, a[i] };
  }

  min_val.build();
  min_l.build();
  min_r.build();

  scanf("%d", &q);

  REP(i, q) {
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2); --r1; --r2;
    int rdiff = abs(r1 - r2);
    int imin = min_val.get(min(r1, r2), max(r1, r2)).first;
    int mmin = min(imin, c1);

    int cdiff = abs(mmin - c2);

    cdiff = min(cdiff, 1 + c2);
    cdiff = min(cdiff, 1 + abs(c2 - a[r2]));
    
    int sol = cdiff + rdiff;

    int lo, hi, mid;
    int c;

    lo = 0, hi = r2;
    while (lo < hi) {
      mid = (lo + hi + 1) / 2;
      if (min_val.get(mid, r2).first > c2) 
        hi = mid - 1;
      else
        lo = mid;
    }
    
    c = a[lo];
    sol = min(sol, rdiff + abs(r1 - lo) * 2 + abs(c - c2) + (mmin < c));
    sol = min(sol, rdiff + abs(r2 - lo) * 2 + abs(c - c2) + (mmin < c));
    if ((r1 <= lo && lo <= r2) || (r2 <= lo && lo <= r1))
      sol = min(sol, rdiff + abs(c - c2) + (mmin < c));

    if (lo < r2) {
      ++lo;
      int d = min_l.get(lo, r2).first + 2 * r2;
      sol = min(sol, rdiff + d - c2 + 1);

      if (r1 <= lo) {
        int d = min_val.get(lo, r2).first;
        sol = min(sol, rdiff + d - c2 + 1);
      }

      if (lo <= r2 && r2 <= r1) {
        pii D = min_l.get(lo, r2);
        int d = D.first + 2 * r2;
        sol = min(sol, rdiff + d - c2 + (D.second > mmin));
      }

      if (lo <= r1 && r1 <= r2) {
        pii D = min_l.get(lo, r1);
        int d = D.first + 2 * r1;
        sol = min(sol, rdiff + d - c2 + (D.second > mmin));
      }

      if (r1 <= r2) {
        int r = max(lo, r1);
        int c = min_val.get(r, r2).first;
        assert(c > c2);
        sol = min(sol, rdiff + c - c2 + (c > mmin));
      }
    }
    
    lo = r2, hi = n - 1;
    while (lo < hi) {
      mid = (lo + hi) / 2;
      if (min_val.get(r2, mid).first > c2)
        lo = mid + 1;
      else
        hi = mid;
    }

    c = a[lo];
    sol = min(sol, rdiff + abs(r1 - lo) * 2 + abs(c - c2) + (mmin < c));
    sol = min(sol, rdiff + abs(r2 - lo) * 2 + abs(c - c2) + (mmin < c));
    if ((r1 <= lo && lo <= r2) || (r2 <= lo && lo <= r1))
      sol = min(sol, rdiff + abs(c - c2) + (mmin < c));

    if (lo > r2) {
      --lo;
      int d = min_r.get(r2, lo).first - 2 * r2;
      sol = min(sol, rdiff + d - c2 + 1);

      if (r1 >= lo) {
        int d = min_val.get(r2, lo).first;
        sol = min(sol, rdiff + d - c2 + 1);
      }
      
      if (r2 <= lo && r1 <= r2) {
        pii D = min_r.get(r2, lo);
        int d = D.first - 2 * r2;
        sol = min(sol, rdiff + d - c2 + (D.second > mmin));
      }

      if (lo >= r1 && r1 >= r2) {
        pii D = min_r.get(r1, lo);
        int d = D.first - 2 * r1;
        sol = min(sol, rdiff + d - c2 + (D.second > mmin));
      }

      if (r2 <= r1) {
        int r = min(r1, lo);
        int c = min_val.get(r2, r).first;
        sol = min(sol, rdiff + c - c2 + (c > mmin));
      }
    }

    printf("%d\n", sol);
  }

  return 0;
}
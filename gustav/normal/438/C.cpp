#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
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

const int mod = 1000000007;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (llint)a * b % mod; }

struct Pt { 
  int x, y; 
  void read() {
    scanf("%d%d", &x, &y);
  }
};

llint ccw(Pt a, Pt b, Pt c) {
  return (llint)a.x * (b.y - c.y) +
         (llint)b.x * (c.y - a.y) +
         (llint)c.x * (a.y - b.y);
}

int sccw(Pt a, Pt b, Pt c) {
  llint C = ccw(a, b, c);
  if (C < 0) return -1;
  if (C > 0) return +1;
  return 0;
}

llint area(Pt a, Pt b, Pt c) {
  return abs(ccw(a, b, c));
}


const int MAXN = 205;

int n;
Pt p[MAXN];

llint parea(vector< int > is) {
  int n = is.size();
  llint ret = 0;
  REP(I, n) {
    int i = is[I];
    int j = is[(I + 1) % n];
    ret += (llint)p[i].x * p[j].y - (llint)p[j].x * p[i].y;
  }
  return abs(ret);
}

bool inside_polygon(int a, int b) {
  vector< int > L, R, all;

  REP(i, n) {
    if (i >= a && i <= b) L.push_back(i);
    if (i <= a || i >= b) R.push_back(i);
    all.push_back(i);
  }

  return parea(L) + parea(R) == parea(all);
}

bool strictly_intersects(Pt a, Pt b, Pt c, Pt d) {
  int acb = sccw(a, c, b);
  int adb = sccw(a, d, b);
  int cad = sccw(c, a, d);
  int cbd = sccw(c, b, d);

  if (acb * adb != -1) return false;
  if (cad * cbd != -1) return false;

  return true;
}

bool point_on_segment(int a, int b) {
  REP(i, n) {
    if (i == a) continue;
    if (i == b) continue;
    if (ccw(p[a], p[b], p[i]) != 0) continue;
    if (p[i].x < min(p[a].x, p[b].x)) continue;
    if (p[i].y < min(p[a].y, p[b].y)) continue;
    if (p[i].x > max(p[a].x, p[b].x)) continue;
    if (p[i].y > max(p[a].y, p[b].y)) continue;
    return true;
  }
  return false;
}

bool check(int a, int b) {
  if (!inside_polygon(a, b)) 
    return false;

  if (point_on_segment(a, b))
    return false;

  REP(i, n) {
    int j = (i + 1) % n;
    if (strictly_intersects(p[a], p[b], p[i], p[j]))
      return false;
  }

  return true;
}

bool good[MAXN][MAXN];

bool tri_good(int a, int b, int c) {
  return good[a][b] && good[b][c] && good[c][a];
}

int memo[MAXN][MAXN];

int solve(int l, int r) {
  if ((l + 1) % n == r)
    return 1;

  int &ref = memo[l][r];
  if (ref >= 0) return ref;
  ref = 0;

  for (int i = (l + 1) % n; i != r; i = (i + 1) % n) 
    if (tri_good(l, i, r))
      ref = add(ref, mul(solve(l, i), solve(i, r)));

  return ref;
}

int main(void)
{
  scanf("%d", &n);
  REP(i, n) p[i].read();

  REP(i, n) FOR(j, i + 1, n) 
    good[i][j] = good[j][i] = check(i, j);

  memset(memo, -1, sizeof memo);

  printf("%d\n", solve(1, 0));

  return 0;
}
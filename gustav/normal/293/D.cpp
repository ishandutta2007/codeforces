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
#define log(...) fprintf(stderr, ##__VA_ARGS__)

struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
  friend bool operator<(const pt &a, const pt &b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
};

struct seg {
  pt a, b;
  llint A, B, C;

  seg() {}
  seg(pt a, pt b) : a(a), b(b) {
    A = a.y - b.y;
    B = b.x - a.x;
    C = A * a.x + B * a.y;
  }

  int cut_r(int y) { 
    int x = (C - B * y) / A;
    if (A * x + B * y < C) ++x;
    return x;
  }

  int cut_l(int y) {
    int x = (C - B * y) / A;
    if (A * x + B * y > C) --x;
    return x;
  }
};

int n, x, y;
vector< pt > p;
vector< seg > L;
vector< seg > R;

double tot;

double sum_range(int l, int r) {
  if (l > r) return 0;
  double len = r - l + 1;
  return len * l + len * (len - 1) * 0.5;
}

double _sum_squares(int n) {
  double ret = (double)(n + 1) * n * (n - 1) / 3;
  ret += (double)n * (n + 1) / 2;
  return ret;
}

double sum_squares(int l, int r) {
  if (l > r) return 0;
  if (l <= 0 && r >= 0)
    return _sum_squares(abs(l)) + _sum_squares(abs(r));

  l = abs(l);
  r = abs(r);

  if (l > r) swap(l, r);
  
  double ret = _sum_squares(r);
  if (l) ret -= _sum_squares(l - 1);
  
  return ret;
}

double solve() {
  int miny = +inf;
  int maxy = -inf;
  llint area = 0;

  REP(i, n) {
    miny = min(miny, p[i].y);
    maxy = max(maxy, p[i].y);

    int j = (i + 1) % n;
    area += (llint)p[i].x * p[j].y - (llint)p[i].y * p[j].x;
  }

  if (area < 0) 
    reverse(p.begin(), p.end());

  L.clear();
  R.clear();

  rotate(p.begin(), max_element(p.begin(), p.end()), p.end());

  FOR(i, (p[0].y == p[1].y), n) {
    if (p[i].y == miny) break;
    L.push_back(seg(p[i], p[i + 1]));
  }

  R.push_back(seg(p[0], p.back()));

  REP(i, n) {
    if (p[n - i - 1].y == miny) break;
    R.push_back(seg(p[n - i - 1], p[n - i - 2]));
  }

  tot = 0.0;
  double sum = 0.0;
  double sum_sq = 0.0;

  int li = 0, ri = 0;
  for (int y = maxy; y >= miny; --y) {
    if (y < L[li].b.y) ++li;
    if (y < R[ri].b.y) ++ri;

    int l = L[li].cut_r(y);
    int r = R[ri].cut_l(y);

    tot += r - l + 1;
    sum += sum_range(l, r);
    sum_sq += sum_squares(l, r);
  }

  return 2.0 * sum_sq - 2.0 * (sum / tot) * sum;
}

int main(void)
{
  scanf("%d", &n);

  REP(i, n) {
    scanf("%d%d", &x, &y);
    p.push_back(pt(x, y));
  }

  double sol = 0.0;

  sol += solve();
  REP(i, n) swap(p[i].x, p[i].y);
  sol += solve();

  sol /= (tot - 1.0);
  sol *= 0.5;

  printf("%.8lf\n", sol);

  return 0;
}
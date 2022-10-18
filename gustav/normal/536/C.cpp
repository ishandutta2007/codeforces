#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>


using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#define x first
#define y second

const int MAXN = 200005;

typedef pair< llint, llint > Point;

llint ccw(Point a, Point b, Point c) {
  llint ret = 0;
  ret += b.x * c.x * a.y * (c.y - b.y);
  ret += c.x * a.x * b.y * (a.y - c.y);
  ret += a.x * b.x * c.y * (b.y - a.y);
  return ret;
}

map< Point, int > M;

int r[MAXN];
int s[MAXN];
Point p[MAXN];
Point h[MAXN];

int main(void) 
{
  int n;
  scanf("%d", &n);
  set< Point > S;
  REP(i, n) {
    scanf("%d%d", &r[i], &s[i]);
    S.insert({r[i], s[i]});
  }

  int m = 0;
  for (auto it : S) p[m++] = it;

  auto cmp = [&](Point a, Point b) {
    if (a.x != b.x) return a.x > b.x;
    return a.y < b.y;
  };

  sort(p, p + m, cmp);

  int top = 0;
  REP(i, m) {
    while (top >= 2 && ccw(h[top - 2], h[top - 1], p[i]) < 0) --top;
    h[top++] = p[i];
  }

  while (top >= 2 && h[top - 1].y <= h[top - 2].y) --top;

  int start = 0;
  while (start + 1 < top && h[start].x == h[start + 1].x) ++start;
  FOR(i, start, top) M[h[i]] = 1;

  REP(i, n) if (M[{r[i], s[i]}]) printf("%d ", i + 1);
  puts("");

  return 0;
}
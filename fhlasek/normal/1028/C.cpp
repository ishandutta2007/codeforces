/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

typedef pair<int, int> coord;
typedef pair<coord, coord> rect;

rect intersect(rect a, rect b) {
  return rect(coord(max(a.first.first, b.first.first), max(a.first.second, b.first.second)), coord(min(a.second.first, b.second.first), min(a.second.second, b.second.second)));
}

#define MAXN 1111111
rect A[MAXN];
rect pref[MAXN], suff[MAXN];

#define INF 1000000000

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  pref[0] = rect(coord(-INF, -INF), coord(INF, INF));
  REP(i, N) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    A[i] = rect(coord(x1, y1), coord(x2, y2));
    pref[i + 1] = intersect(pref[i], A[i]);
  }

  suff[N] = rect(coord(-INF, -INF), coord(INF, INF));
  FORD(i, N - 1, 0) suff[i] = intersect(suff[i + 1], A[i]);

  REP(i, N) {
    rect tmp = intersect(pref[i], suff[i + 1]);
    if (tmp.first.first <= tmp.second.first && tmp.first.second <= tmp.second.second) {
      printf("%d %d\n", tmp.first.first, tmp.first.second);
      break;
    }
  }

  return 0;
}
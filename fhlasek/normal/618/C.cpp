/* Written by Filip Hlasek 2016 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

class Vector {
  public:
    long long x, y;
    Vector(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
};

#define MAXN 222222
int N;
Vector v[MAXN];

long long sq(long long x) { return x * x; }

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) { int x, y; scanf("%d%d", &x, &y); v[i] = Vector(x, y); }

  int i1 = 0, i2 = 1, i3 = 0;
  Vector v1 = v[0], v2 = v[1];
  FOR(i, 2, N - 1) if (
    sq(v[i].x - v1.x) + sq(v[i].y - v1.y) < sq(v2.x - v1.x) + sq(v2.y - v1.y)
  ) {
    v2 = v[i];
    i2 = i;
  }

  long long best = 8000000000000000000LL;
  FOR(i, 1, N - 1) {
    long long d = (v2.y - v1.y) * v[i].x - (v2.x - v1.x) * v[i].y + v2.x * v1.y - v2.y * v1.x;
    if (d != 0 && abs(d) < best) {
      best = abs(d);
      i3 = i;
    }
  }
  printf("%d %d %d\n", i1 + 1, i2 + 1, i3 + 1);

  return 0;
}
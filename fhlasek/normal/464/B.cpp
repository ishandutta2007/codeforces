/* Written by Filip Hlasek 2014 */
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

int C[3][10];
int c[3][10];
int perm[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

long long sq(int x) { return (long long)x * x; }

int main(int argc, char *argv[]) {
  REP(i, 8) scanf("%d%d%d", C[0] + i, C[1] + i, C[2] + i);
  REP(_mask, 279936) {
    int mask = _mask;
    REP(i, 8) {
      int p = mask % 6;
      mask /= 6;
      REP(j, 3) c[j][i] = C[perm[p][j]][i];
    }
    vector<long long> d;
    REP(i, 8) REP(j, i) d.push_back(sq(c[0][i] - c[0][j]) + sq(c[1][i] - c[1][j]) + sq(c[2][i] - c[2][j]));
    sort(d.begin(), d.end());
    bool ok = true;
    REP(i, d.size()) {
      if (i < 12 && d[i] != d[0]) ok = false;
      else if (i >= 12 && i < 24 && d[i] != 2 * d[0]) ok = false;
      else if (i >= 24 && d[i] != 3 * d[0]) ok = false;
    }
    long long s = sqrt(d[0]);
    if (!ok || d[0] == 0 || (s * s != d[0] && (s - 1) * (s - 1) != d[0] && (s + 1) * (s + 1) != d[0])) continue;
    printf("YES\n");
    REP(i, 8) printf("%d %d %d\n", c[0][i], c[1][i], c[2][i]);
    return 0;
  }
  printf("NO\n");
  return 0;
}
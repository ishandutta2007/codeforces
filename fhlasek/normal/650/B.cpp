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

#define MAXN 666666
int N, A, B, T;
char p[MAXN];
int tm[MAXN];

int solve() {

  int t = tm[0];
  if (t > T) return 0;

  int pos = 1;
  FORD(i, N - 1, 1) {
    if (t + tm[i] + A * (N - i) > T) {
      pos = i + 1;
      break;
    }
    t += tm[i];
  }

  int ans = N - pos + 1;
  FOR(i, 1, N) {
    t += tm[i];
    while (pos < N && t + (2LL * (N - pos) + i) * A > T) t -= tm[pos++];
    if (t + (2LL * (N - pos) + i) * A > T) break;
    ans = max(ans, N - pos + i + 1);
  }

  return min(N, ans);
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d%d", &N, &A, &B, &T);
  scanf("%s", p);
  REP(i, N) tm[i] = (p[i] == 'h' ? 1 : B + 1);

  int ans = solve();
  reverse(tm + 1, tm + N);
  ans = max(ans, solve());

  printf("%d\n", ans);
  return 0;
}
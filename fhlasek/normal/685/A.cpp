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

int used[10];

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  long long A = 1, B = 1, a = 7, b = 7;
  while (N > a) { a *= 7; A++; }
  while (M > b) { b *= 7; B++; }
  if (A + B > 7) { printf("0\n"); return 0; }
  int U = 0;
  int ans = 0;
  REP(_n, N) REP(_m, M) {
    ++U;
    int n = _n, m = _m;
    bool ok = true;
    REP(i, A) {
      if (used[n % 7] == U) ok = false;
      used[n % 7] = U;
      n /= 7;
    }
    REP(i, B) {
      if (used[m % 7] == U) ok = false;
      used[m % 7] = U;
      m /= 7;
    }
    ans += ok;
  }
  printf("%d\n", ans);
  return 0;
}
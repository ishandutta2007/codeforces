/* Written by Filip Hlasek 2012 */
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

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
#define REP(i, b) for(int i=0;i<b;i++)

using namespace std;

#define MAXC 111111
#define MOD 1000000007
int fac[MAXC], ifac[MAXC];

int power(int base, long long exponent) {
  int result = 1, m = base;
  while (exponent) {
    if (exponent & 1) result = ((long long)result * m) % MOD;
    m = ((long long)m * m) % MOD;
    exponent /= 2;
  }
  return result;
}

int c(int n, int k) { return (((long long)fac[n] * ifac[k])%MOD * ifac[n-k])%MOD; }

char s[MAXC];

int main(int argc, char *argv[]) {

  fac[0] = 1;
  REP(i, MAXC) fac[i+1] = ((long long)fac[i]*(i+1))%MOD;
  ifac[MAXC-1] = power(fac[MAXC-1], MOD-2);
  FORD(i, MAXC-2, 0) ifac[i] = ((long long)ifac[i+1]*(i+1))%MOD;

  int Q;
  scanf("%d", &Q);

  scanf("%s", s);
  int d = strlen(s);

  while (Q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) { scanf("%s", s); d = strlen(s); }
    else {
      int n;
      scanf("%d", &n);
      if (d <= n) {
        int ans = power(26, n);
        int tmp = power(25, n - d + 1);
        FORD(k, d - 1, 0) {
          ans = (ans - (long long)c(n, k) * tmp) % MOD;
          tmp = (25LL * tmp) % MOD;
        }
        printf("%d\n", (ans + MOD) % MOD);
      }
      else {
        printf("0\n");
      }
    }
  }
  return 0;
}
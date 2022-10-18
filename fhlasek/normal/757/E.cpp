/* Written by Filip Hlasek 2017 */
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

#define MOD 1000000007
#define MAXN 1111111
#define MAXC 2111111
int pd[MAXN], p2[MAXN];
vector<int> pf[MAXN], pc[MAXN];

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

int c(int n, int k) {
  return (((long long)fac[n] * ifac[k]) % MOD * ifac[n - k]) % MOD;
}

int main(int argc, char *argv[]) {

  fac[0] = 1;
  REP(i, MAXC) fac[i + 1] = ((long long)fac[i] * (i + 1)) % MOD;
  ifac[MAXC - 1] = power(fac[MAXC - 1], MOD - 2);
  FORD(i, MAXC - 2, 0) ifac[i] = ((long long)ifac[i + 1] * (i + 1)) % MOD;

  for (int i = 2; i < MAXN; ++i) if (!pd[i]) {
    for (int j = i; j < MAXN; j += i) {
      pd[j]++;
      // pf[j].push_back(i);
      int tmp = j / i;
      pc[j].push_back(1);
      while (tmp % i == 0) { pc[j][pd[j] - 1]++; tmp /= i; }
    }
  }
  p2[0] = 1;
  REP(i, MAXN - 1) p2[i + 1] = (2 * p2[i]) % MOD;

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int R, N;
    scanf("%d%d", &R, &N);
    int ans = 0;
    if (!R) ans = p2[pd[N]];
    else {
      ans = 1;
      REP(i, pd[N]) {
        int tmp = 0;
        FOR(j, 0, pc[N][i]) tmp = (tmp + c(j + R - 1, R - 1) * (1LL + (j != pc[N][i]))) % MOD;
        ans = ((long long)ans * tmp) % MOD;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
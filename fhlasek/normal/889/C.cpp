/* Written by Filip Hlasek 2017 */
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

#define MAXC 1111111
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

int valid[MAXC];

int main(int argc, char *argv[]) {

  fac[0] = 1;
  REP(i, MAXC) fac[i+1] = ((long long)fac[i]*(i+1))%MOD;
  ifac[MAXC-1] = power(fac[MAXC-1], MOD-2);
  FORD(i, MAXC-2, 0) ifac[i] = ((long long)ifac[i+1]*(i+1))%MOD;

  int n, k;
  scanf("%d%d", &n, &k);

  valid[0] = 1;
  FOR(m, 1, n) {
    valid[m] = (long long)valid[m - 1] * (m - 1) % MOD;
    if (m > k) {
      int i = m - k - 1;
      valid[m] = (valid[m] - (long long)valid[i] * c(m - 1, i) % MOD * fac[m - i - 1]) % MOD;
    }
    int i = m - 1;
    valid[m] = (valid[m] + (long long)valid[i] * c(m - 1, i) % MOD * fac[m - i - 1]) % MOD;
  }
  int ans = 0;
  FOR(i, 0, n - 1) {
    ans = (ans + (long long)valid[i] * c(n - 1, i) % MOD * fac[n - i - 1]) % MOD;
  }
  printf("%d\n", ((fac[n] - ans) % MOD + MOD) % MOD);
  return 0;
}
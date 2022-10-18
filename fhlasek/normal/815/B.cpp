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

#define MAXC 411111
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

vector<int> peform(vector<int> &input, bool &plus) {
  vector<int> output;
  REP(i, input.size() - 1) {
    if (plus) output.push_back((input[i] + input[i + 1]) % MOD);
    else output.push_back((input[i] - input[i + 1]) % MOD);
    plus = !plus;
  }
  return output;
}

int main(int argc, char *argv[]) {

  fac[0] = 1;
  REP(i, MAXC) fac[i+1] = ((long long)fac[i]*(i+1))%MOD;
  ifac[MAXC-1] = power(fac[MAXC-1], MOD-2);
  FORD(i, MAXC-2, 0) ifac[i] = ((long long)ifac[i+1]*(i+1))%MOD;

  int N;
  scanf("%d", &N);
  vector<int> a;
  REP(i, N) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }

  bool plus = true;
  while (!plus || (a.size() % 2 && a.size() > 1)) {
    a = peform(a, plus);
  }

  if (a.size() == 1) {
    printf("%d\n", (a[0] + MOD) % MOD);
    return 0;
  }

  N = a.size() / 2 - 1;
  // REP(i, a.size()) printf("%d ", a[i]); printf("\n");
  int ans = 0;
  REP(i, a.size()) {
    // printf("%d %d %d\n", N, i / 2, c(N, i / 2));
    ans = (ans + (long long)a[i] * c(N, i / 2) * (a.size() % 4 == 0 && i % 2 ? -1 : 1)) % MOD;
  }
  if (ans < 0) ans += MOD;
  printf("%d\n", ans);
  return 0;
}
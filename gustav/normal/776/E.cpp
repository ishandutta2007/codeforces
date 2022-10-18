#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int mod = 1e9 + 7;

llint gcd(llint x, llint y) {
  return y ? gcd(y, x % y) : x;
}

llint phi(llint n) {
  llint m = n;
  llint ret = n;
  for (llint i = 2; i * i <= m; ++i) {
    if (n % i == 0) {
      ret -= ret / i;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1)
    ret -= ret / n;
  return ret;
}

llint f_bf(llint n) {
  if (n == 1) return 1;
  int sol = 0;
  FOR(i, 1, n)
    sol += gcd(i, n - i) == 1;
  return sol;
}

int main(void) 
{
  llint n, k;
  scanf("%lld%lld", &n, &k);

  while (k) {
    llint on = n;
    if (k % 2 == 1) {
      n = phi(n);
      if (n == on) break;
    }
    --k;
  }

  printf("%lld\n", n % mod);

  return 0;
}
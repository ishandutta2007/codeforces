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

#define MAXN 111111
int sieve[MAXN], prime[MAXN], P = 0;

set<int> factor(int n) {
  set<int> ans;
  REP(i, P) {
    if (prime[i] * prime[i] > n) break;
    while (n % prime[i] == 0) { ans.insert(prime[i]); n /= prime[i]; }
  }
  if (n > 1) ans.insert(n);
  return ans;
}

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
  FOR(i, 2, MAXN - 1) if (!sieve[i]) {
    prime[P++] = i;
    for (int j = 2 * i; j < MAXN; j += i) sieve[j] = true;
  }

  int N;
  scanf("%d", &N);
  long long g = 0;
  int A, B;
  REP(i, N) {
    scanf("%d%d", &A, &B);
    g = gcd(g, (long long)A * B);
  }
  if (g > 1) {
    if (g > 2000000000) {
      g = max(gcd(g, A), gcd(g, B));
    }
    printf("%d\n", *factor(g).begin());
  } else {
    printf("-1\n");
  }

  return 0;
}
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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

bool solve(int n, int m, int k) {
  if (k % 2 == 0) {
    k /= 2;
    int kn = gcd(k, n);
    n /= kn;
    k /= kn;
    if (m % k) return false;
    m /= k;
  } else {
    int kn = gcd(k, n);
    n /= kn;
    k /= kn;
    if (m % k) return false;
    m /= k;
    if (kn > 1) n *= 2;
    else m *= 2;
  }
  printf("YES\n%d %d\n%d %d\n%d %d\n", 0, 0, n, 0, 0, m);
  return true;
}

int main(int argc, char *argv[]) {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  if (!solve(N, M, K)) {
    printf("NO\n");
  }
  return 0;
}
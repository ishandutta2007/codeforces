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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

#define MAXN 2222
int A[MAXN];
int N;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  int g = 0;
  REP(i, N) g = gcd(A[i], g);
  if (g != 1) { printf("-1\n"); return 0; }
  int ones = 0;
  REP(i, N) ones += A[i] == 1;
  if (ones) { printf("%d\n", N - ones); return 0; }
  int ans = 2 * N;
  REP(l, N) {
    int g = A[l], r = l + 1;
    while (g != 1 && r < N) g = gcd(g, A[r++]);
    if (g == 1) {
      ans = min(ans, N + r - l - 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}
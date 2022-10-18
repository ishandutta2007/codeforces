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
int a[MAXN], b[MAXN];

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  int A = N, B = 0;
  REP(i, N) scanf("%d", a + i);
  a[A] = 1000000000;
  REP(i, M) {
    int x1, x2, y;
    scanf("%d%d%d", &x1, &x2, &y);
    if (x1 == 1) b[B++] = x2;
  }
  sort(a, a + A);
  sort(b, b + B);
  reverse(b, b + B);
  int ans = B;
  FOR(i, 0, A) {
    while (B && b[B - 1] < a[i]) B--;
    ans = min(ans, B + i);
  }
  printf("%d\n", ans);
  return 0;
}
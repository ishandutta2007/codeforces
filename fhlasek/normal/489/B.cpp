/* Written by Filip Hlasek 2014 */
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

#define MAXN 22222
int a[MAXN], b[MAXN];

int main(int argc, char *argv[]) {
  int A, B;
  scanf("%d", &A);
  REP(i, A) scanf("%d", a + i);
  scanf("%d", &B);
  REP(i, B) scanf("%d", b + i);
  sort(a, a + A);
  sort(b, b + B);
  int pa = 0, pb = 0, ans = 0;
  while (pa < A && pb < B) {
    if (abs(a[pa] - b[pb]) <= 1) { ans++; pa++; pb++; }
    else if (a[pa] < b[pb]) pa++;
    else pb++;
    // printf("pa: %d pb: %d ans: %d\n", pa, pb, ans);
  }
  printf("%d\n", ans);
  return 0;
}
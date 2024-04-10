/* Written by Filip Hlasek 2016 */
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

int main(int argc, char *argv[]) {
  int N, H, D;
  scanf("%d%d%d", &N, &D, &H);
  if (D + 1 > N || D - H > H || (N > 2 && D == 1)) {
    printf("-1\n");
    return 0;
  }
  REP(i, H) {
    printf("%d %d\n", i + 1, i + 2);
  }
  if (D == H) {
    REP(i, N - H - 1) {
      printf("2 %d\n", H + i + 2);
    }
  }
  else {
    printf("1 %d\n", H + 2);
    REP(i, D - H - 1) printf("%d %d\n", H + 2 + i, H + 2 + i + 1);
    REP(i, N - D - 1) printf("1 %d\n", D + 2 + i);
  }
  return 0;
}
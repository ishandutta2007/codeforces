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

int main(int argc, char *argv[]) {
  int N, K;
  scanf("%d%d", &N, &K);

  if (N < 4 || K == 1 || K > 3) printf("-1\n");
  else if (K == 2) {
    if (N == 4) printf("-1\n");
    else {
      printf("%d\n", N - 1);
      REP(i, N - 1) printf("%d %d\n", i + 1, i + 2);
    }
  }
  else if (K == 3) {
    printf("%d\n", 3 + 2 * (N - 4));
    printf("1 3\n");
    printf("1 4\n");
    printf("2 3\n");
    REP(i, N - 4) {
      printf("1 %d\n", i + 5);
      printf("2 %d\n", i + 5);
    }
  }
  return 0;
}
/* Written by Filip Hlasek 2020 */
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

#define MAXN 11111
int A[MAXN], N;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", A + i);

    int sum = 0;
    REP(i, N) sum += A[i];
    if (sum % N) { printf("-1\n"); continue; }

    printf("%d\n", 3 * (N - 1));
    FOR(i, 1, N - 1) {
      int rem = ((i + 1) - A[i] % (i + 1)) % (i + 1);
      printf("%d %d %d\n", 1, i + 1, rem);
      A[i] += rem;
      printf("%d %d %d\n", i + 1, 1, A[i] / (i + 1));
      A[i] = 0;
    }

    FOR(i, 1, N - 1) {
      printf("%d %d %d\n", 1, i + 1, sum / N);
    }
  }

  return 0;
}
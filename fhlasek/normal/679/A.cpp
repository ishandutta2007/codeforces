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

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int P = 15;

int main(int argc, char *argv[]) {
  char ans[5];
  REP(a, 4) {
    printf("%d\n", primes[a]); fflush(stdout);
    scanf("%s", ans);
    if (ans[0] == 'y') {
      REP(b, P) if (b >= a && primes[a] * primes[b] <= 100) {
        printf("%d\n", primes[a] * primes[b]); fflush(stdout);
        scanf("%s", ans);
        if (ans[0] == 'y') { printf("composite\n"); return 0; }
      }
      break;
    }
  }
  printf("prime\n");
  return 0;
}
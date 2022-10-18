/* Written by Filip Hlasek 2015 */
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

#define MAXN 111
int N;
char a[MAXN][MAXN];
int A[MAXN];
bool chosen[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%s", a[i]);
  REP(i, N) scanf("%d", A + i);
  while (true) {
    bool ok = true;
    REP(i, N) {
      int cnt = 0;
      REP(j, N) if (a[j][i] == '1' && chosen[j]) cnt++;
      if (cnt == A[i]) {
        chosen[i] = true;
        ok = false;
        break;
      }
    }
    if (ok) break;
  }
  int A = 0;
  REP(i, N) if (chosen[i]) A++;
  printf("%d\n", A);
  bool printed = false;
  REP(i, N) if (chosen[i]) {
    if (printed) printf(" ");
    printed = true;
    printf("%d", i + 1);
  }
  printf("\n");
  return 0;
}
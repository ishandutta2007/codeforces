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
bool fail[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) REP(j, N) {
    int a;
    scanf("%d", &a);
    if (a > 1) fail[j] = true;
  }
  int ans = 0;
  REP(i, N) if (!fail[i]) ans++;
  printf("%d\n", ans);
  bool printed = false;
  REP(i, N) if (!fail[i]) {
    if (printed) printf(" ");
    printed = true;
    printf("%d", i + 1);
  }
  printf("\n");
  return 0;
}
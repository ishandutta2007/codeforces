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

#define MAXN 111111
char input[MAXN];

int main(int argc, char *argv[]) {
  int L = 0, U = 0, R = 0, D = 0;
  scanf("%s", input);
  int N = strlen(input);
  if (N % 2) { printf("-1\n"); return 0; }
  REP(i, N) {
    if (input[i] == 'L') L++;
    if (input[i] == 'R') R++;
    if (input[i] == 'U') U++;
    if (input[i] == 'D') D++;
  }
  printf("%d\n", abs(L - R) / 2 + (abs(U - D) + 1) / 2);
  return 0;
}
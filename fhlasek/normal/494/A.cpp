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

#define MAXN 1111111
char input[MAXN];
int N;
int ans[MAXN];

int solve() {
  int balance = 0, last = 0;
  REP(i, N) {
    if (input[i] == '#') { last = i; ans[i] = 1; balance -= 1; }
    if (input[i] == '(') balance++;
    if (input[i] == ')') balance--;
  }
  if (balance < 0) return -1;

  ans[last] += balance;

  balance = 0;
  REP(i, N) {
    if (input[i] == '#') balance -= ans[i];
    if (input[i] == '(') balance++;
    if (input[i] == ')') balance--;
    if (balance < 0) return -1;
  }
  REP(i, N) if (input[i] == '#') printf("%d\n", ans[i]);

  return 0;
}

int main(int argc, char *argv[]) {
  scanf("%s", input);
  N = strlen(input);
  int ans = solve();
  if (ans == -1) printf("-1\n");
  return 0;
}
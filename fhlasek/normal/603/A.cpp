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

#define MAXN 1111111
char input[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  scanf("%s", input);
  int ans = 1;
  REP(i, N - 1) if (input[i] != input[i + 1]) ans++;
  ans += min(2, N - ans);
  printf("%d\n", ans);
  return 0;
}
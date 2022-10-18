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

#define MAXN 222222
char input[MAXN];
int cnt[333];

int main(int argc, char *argv[]) {
  scanf("%s", input);
  int N = strlen(input);
  REP(i, N) cnt[input[i]]++;
  int ans = cnt['B'];
  ans = min(ans, cnt['l']);
  ans = min(ans, cnt['b']);
  ans = min(ans, cnt['s']);
  ans = min(ans, cnt['r']);
  ans = min(ans, cnt['u'] / 2);
  ans = min(ans, cnt['a'] / 2);
  printf("%d\n", ans);
  return 0;
}
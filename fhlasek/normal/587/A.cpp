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
int cnt[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) { int a; scanf("%d", &a); cnt[a]++; }
  int ans = 0;
  REP(i, MAXN - 1) {
    ans += cnt[i] % 2;
    cnt[i + 1] += cnt[i] / 2;
  }
  printf("%d\n", ans);
  return 0;
}
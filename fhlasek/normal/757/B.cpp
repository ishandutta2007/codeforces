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
int cnt[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  while(N--) {
    int s;
    scanf("%d", &s);
    for (int i = 2; i * i <= s; ++i) if (s % i == 0) {
      cnt[i]++;
      while(s % i == 0) s /= i;
    }
    if (s > 1) cnt[s]++;
  }
  int ans = 1;
  REP(i, MAXN) ans = max(ans, cnt[i]);
  printf("%d\n", ans);
  return 0;
}
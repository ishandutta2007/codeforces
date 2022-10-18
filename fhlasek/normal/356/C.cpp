/* Written by Filip Hlasek 2013 */
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

int N, cnt[5], new_cnt[5];

int main(int argc, char *argv[]){
  scanf("%d", &N);
  int sum = 0; 
  REP(i, N) { int a; scanf("%d", &a); cnt[a]++; sum += a; }
  if(sum == 1 || sum == 2 || sum == 5) {
    printf("-1\n");
    return 0;
  }
  
  int best = sum;

  REP(i, 1000000) if (4 * i <= sum && (sum - 4 * i) % 3 == 0) {
    int c4 = i, c3 = (sum - 4 * i) / 3;

    new_cnt[4] = c4;
    new_cnt[3] = c3;
    new_cnt[0] = 1000000;

    int ans = 0;

    int x1 = 4, x2 = 4, pos = 0, cnt1 = cnt[4], cnt2 = new_cnt[4];
    while(pos < N) {
      if (cnt1 < cnt2) {
        if (x1 < x2) ans += (x2 - x1) * cnt1;
        pos += cnt1; 
        cnt2 -= cnt1;
        x1--;
        cnt1 = cnt[x1];
      }
      else {
        if (x1 < x2) ans += (x2 - x1) * cnt2;
        pos += cnt2;
        cnt1 -= cnt2;
        x2--;
        cnt2 = new_cnt[x2];
      }
    }

    best = min(best, ans);
  }

  printf("%d\n", best);

  return 0;
}
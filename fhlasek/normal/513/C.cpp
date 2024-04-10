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

#define MAXN 10
int L[MAXN], R[MAXN];
int N;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", L + i, R + i);
  double ans = 0;

  FOR(cost, 1, 10000) {
    REP(mask, 1 << N) {
      if (!mask) continue;
      int cnt = 0;
      double prob = 1;
      REP(i, N) if (mask & (1 << i)) {
        cnt++;
        if (!(L[i] <= cost && cost <= R[i])) prob = 0;
        prob *= 1.0 / (R[i] - L[i] + 1);
      }
      // if (prob > 0) printf("cost: %d mask: %d prob: %lf\n", cost, mask, prob);
      double pprob = prob;
      if (cnt >= 2) {
        REP(i, N) if (!(mask & (1 << i))) {
          if (R[i] < cost) continue;
          if (L[i] >= cost) prob = 0;
          else prob *= ((double)cost - L[i]) / (R[i] - L[i] + 1);
        }
        // if (prob > 0) printf("cost: %d mask: %d prob: %lf\n", cost, mask, prob);
        ans += prob * cost;
      }
      REP(j, N) if (!(mask & (1 << j))) {
        prob = pprob;
        if (R[j] <= cost) continue;
        if (L[j] <= cost) prob *= ((double)R[j] - cost) / (R[j] - L[j] + 1);
        // if (prob > 0) printf("j: %d prob: %lf\n", j, prob);
        REP(i, N) if (!(mask & (1 << i)) && i != j) {
          // if (prob > 0) printf("i: %d\n", i);
          if (R[i] < cost) continue;
          if (L[i] >= cost) prob = 0;
          else prob *= ((double)cost - L[i]) / (R[i] - L[i] + 1);
        }
        // if (prob > 0) printf("cost: %d mask: %d j: %d prob: %lf\n", cost, mask, j, prob);
        ans += prob * cost;
      }
    }
  }

  printf("%.12lf\n", ans);
  return 0;
}
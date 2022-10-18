/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define INF 1000000000000000000LL
#define MAXN 5555
vector<int> child[MAXN];
vector<long long> cost_discount[MAXN], cost_full[MAXN];
int N, B;
int C[MAXN], D[MAXN];
int P[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &B);
  REP(i, N) {
    scanf("%d%d", C + i, D + i);
    if (i) {
      scanf("%d", P + i);
      P[i]--;
      child[P[i]].push_back(i);
    }
  }

  FORD(i, N - 1, 0) {
    cost_discount[i].push_back(INF);
    cost_discount[i].push_back(C[i] - D[i]);
    cost_full[i].push_back(0);
    cost_full[i].push_back(C[i]);
    REP(jj, child[i].size()) {
      int j = child[i][jj];
      vector<long long> new_discount, new_full;
      REP(k, cost_full[i].size() + cost_full[j].size()) {
        new_discount.push_back(INF);
        new_full.push_back(INF);
      }
      REP(a, cost_full[i].size()) REP(b, cost_full[j].size()) {
        new_discount[a + b] = min(
          new_discount[a + b],
          cost_discount[i][a] + min(cost_discount[j][b], cost_full[j][b])
        );
        new_full[a + b] = min(
          new_full[a + b],
          cost_full[i][a] + cost_full[j][b]
        );
      }
      cost_discount[i] = new_discount;
      cost_full[i] = new_full;
    }
  }

  int ans = 0;
  REP(i, cost_discount[0].size()) if (cost_discount[0][i] <= B || cost_full[0][i] <= B) {
    ans = i;
  }
  printf("%d\n", ans);
  return 0;
}
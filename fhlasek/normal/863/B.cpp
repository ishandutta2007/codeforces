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

int N, W[111];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, 2 * N) scanf("%d", W + i);
  sort(W, W + 2 * N);
  int best = 1000000;
  REP(i, 2 * N) REP(j, i) {
    vector<int> w;
    REP(k, 2 * N) if (k != i && k != j) w.push_back(W[k]);
    int ans = 0;
    REP(k, N - 1) ans += w[2 * k + 1] - w[2 * k];
    best = min(best, ans);
  }
  printf("%d\n", best);
  return 0;
}
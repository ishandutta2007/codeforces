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

int K, N;

priority_queue< pair<int, int> > pq;
#define MAXN 333333
int C[MAXN];

long long cost = 0;
int ans[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d", C + i);

  REP(i, K) {
    pq.push(make_pair(C[i], i));
  }

  FOR(t, K, N + K - 1) {
    if (t < N) pq.push(make_pair(C[t], t));
    int id = pq.top().second;
    pq.pop();
    ans[id] = t + 1;
    cost += (long long)(t - id) * C[id];
  }

  cout << cost << endl;
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
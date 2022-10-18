/* Written by Filip Hlasek 2016 */
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

#define MAXN 111
int N, P[MAXN];
double p[MAXN];

priority_queue< pair<double, pair<double, int> > > pq;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  double prob = 1;
  REP(i, N) {
    scanf("%d", P + i);
    p[i] = P[i] / 100.0;
    double pcur = 1 - (1 - p[i]) * (1 - p[i]);
    pq.push(make_pair(pcur / p[i], make_pair(p[i], i)));
    prob *= p[i];
  }
  double ans = N * prob;
  FOR(step, N + 1, 200000) {
    double pcur = pq.top().second.first;
    int i = pq.top().second.second;
    pq.pop();
    double prob_before = prob;
    prob /= pcur;
    pcur = 1 - (1 - pcur) * (1 - p[i]);
    prob *= pcur;
    pq.push(make_pair((1 - (1 - pcur) * (1 - p[i])) / pcur, make_pair(pcur, i)));
    ans += (prob - prob_before) * step;
  }
  printf("%.15lf\n", ans);
  return 0;
}
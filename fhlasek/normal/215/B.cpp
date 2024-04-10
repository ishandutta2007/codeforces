/* Writen by Filip Hlasek 2012 */
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

#define MAXN 5555
int X[MAXN], Y[MAXN], Z[MAXN];
int N,M,K,A,B;

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%d", X + i);
  scanf("%d", &M);
  REP(i, M) scanf("%d", Y + i);
  scanf("%d", &K);
  REP(i, K) scanf("%d", Z + i);
  scanf("%d%d",&A,&B);

  sort(X, X + N);
  double best = 0, r1 = X[N - 1];
  REP(i, M) REP(j, K){
    double r = (double)Y[i] * B / Z[j] / A;
    best = max(best, sqrt(r / (1 + r) * r1 *r1));
  }
  printf("%.12lf\n", best);
  return 0;
}
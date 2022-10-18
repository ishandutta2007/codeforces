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

#define MAXN 111
int N, M;
bool g[MAXN][MAXN];
int dist[MAXN][MAXN];

long long paths1[MAXN][MAXN], paths2[MAXN][MAXN];

int main(int argc, char *argv[]){
  scanf("%d%d", &N, &M);
  int a, b;
  REP(i, M){
    scanf("%d%d",&a,&b);
    g[a-1][b-1] = g[b-1][a-1] = true;
  }
  REP(i, N) REP(j, N){
    if(i == j) dist[i][j] = 0;
    else if(g[i][j]) dist[i][j] = 1;
    else dist[i][j] = MAXN;
  }
  REP(k, N) REP(i, N) REP(j, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  double best = 1;
  paths1[0][0] = 1;
  REP(dist, N) REP(i, N) REP(j, N) if(g[i][j]) paths1[dist+1][j] += paths1[dist][i];
  paths2[0][N-1] = 1;
  REP(dist, N) REP(i, N) REP(j, N) if(g[i][j]) paths2[dist+1][j] += paths2[dist][i];
  FOR(i, 1, N-2) if(dist[0][i] + dist[i][N-1] == dist[0][N-1]){
    best = max(best, 2 * (double)(paths1[dist[0][i]][i] * paths2[dist[i][N-1]][i])/ paths1[dist[0][N-1]][N-1]);
  }
  printf("%.12lf\n", best);
  return 0;
}
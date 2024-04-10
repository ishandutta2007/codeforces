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

#define MAXN 222
#define INF 1000000000
int d[MAXN][MAXN], m[MAXN][MAXN];
bool road[MAXN][MAXN];
int N, M;

int main(int argc, char *argv[]){
  scanf("%d%d", &N, &M);
  REP(i, N) REP(j, N) d[i][j] = (i == j ? 0 : INF); 
  REP(i, M){
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    a--; b--;
    d[a][b] = d[b][a] = w;
    road[a][b] = road[b][a] = true;
  }
  REP(k, N) REP(i, N) REP(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  double best = INF;
  REP(i, N){
    double Max = 0;
    REP(j, N) Max = max(Max, (double)d[i][j]);
    best = min(best, Max);
  }
  vector<pair<double, double> > xs;
  REP(i, N) REP(j, i) if(road[i][j]){
    //printf("i: %d j: %d\n", i, j);
    xs.clear();
    REP(k, N) if(abs(d[i][k] - d[j][k]) != d[i][j]){
      double x = (d[i][j] - d[i][k] + d[j][k]) / 2., y = x + d[i][k];
      xs.push_back(make_pair(x - y, y));
    }
    double m = 0;
    REP(k, N) m = max(m, (double)d[i][k]);
    xs.push_back(make_pair(-m, m));
    m = 0;
    REP(k, N) m = max(m, (double)d[j][k]);
    xs.push_back(make_pair(d[i][j] - m, m));
    sort(xs.begin(), xs.end());
    //REP(i, xs.size()) printf("(%lf, %lf) ", xs[i].first, xs[i].second);
    //printf("\n");
    int pos = 0;
    while(pos < xs.size()){
      int i = pos + 1;
      double y = xs[pos].second, x = y + xs[pos].first;
      while(i < xs.size() && x + y >= xs[i].first + 2*xs[i].second) i++;
      if(i == xs.size()) break;
      double yy = xs[i].second, xx = yy + xs[i].first;
      best = min(best, (y + yy + x - xx) / 2);
      pos = i;
    }

/*
    REP(k, N) REP(l, N){
      double x = (d[i][j] - d[i][k] + d[j][l]) / 2.;
      double Max = 0;
      REP(m, N) Max = max(Max, min(x + d[i][m], d[i][j] - x + d[j][m]));
      best = min(best, Max);
    }
*/
  }
  printf("%.12lf\n", best);
  return 0;
}
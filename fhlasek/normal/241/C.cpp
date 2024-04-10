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
#define EPS 1e-9
int H1, H2, N;
int X1[MAXN], X2[MAXN], val[MAXN];
bool Floor[MAXN], used[MAXN];

int solve(int y){
  int dx = 100000, dy;
  if(y % 2) dy = 100 - H1 + 100 * (y - 1) + 100 - H2;
  else dy = H2 - H1 + 100 * y;
  REP(i, N) used[i] = false;
  FOR(i, 1, y){
    double j = (double) (i * 100 - H1) * dx / dy;
    bool found = false;
    REP(n, N) if(Floor[n] != i % 2 && X1[n] - EPS < j && j < X2[n] + EPS){
      found = true;
      if(used[n]) return 0;
      used[n] = true;
      break;
    }
    if(!found) return 0;
  }
  int ans = 0;
  REP(i, N) if(used[i]) ans += val[i];
  return ans;
}

int main(int argc, char *argv[]){
  scanf("%d%d%d", &H1, &H2, &N);
  REP(i, N){
    char tmp[5];
    scanf("%d%s%d%d", val + i, tmp, X1 + i, X2 + i);
    Floor[i] = (tmp[0] == 'F');
  }
  int best = 0;
  FOR(j, 1, MAXN) best = max(best, solve(j));
  REP(i, N) Floor[i] = !Floor[i];
  H1 = 100 - H1;
  H2 = 100 - H2;
  FOR(j, 1, MAXN) best = max(best, solve(j));
  printf("%d\n", best);
  return 0;
}
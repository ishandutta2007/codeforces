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

char a[55][55], b[55][55];

int main(int argc, char *argv[]){
  int Na, Ma, Nb, Mb; 
  int best = -1, bestx, besty;
  scanf("%d%d", &Na, &Ma);
  REP(i, Na) scanf("%s", a[i]);
  scanf("%d%d", &Nb, &Mb);
  REP(i, Nb) scanf("%s", b[i]);
  FOR(x, -50, 50) FOR(y, -50, 50){
    int tmp = 0;
    REP(i, Na) REP(j, Ma) if(i + x >= 0 && i + x < Nb && j + y >= 0 && j + y < Mb)
      tmp += (a[i][j] - '0') * (b[i + x][j + y] - '0');
    if(tmp > best){ best = tmp; bestx = x; besty = y; }
  }
  printf("%d %d\n", bestx, besty);
  return 0;
}
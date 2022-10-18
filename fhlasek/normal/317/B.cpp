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

#define MAXN 333

int c[MAXN][MAXN];
bool inq[MAXN][MAXN];

queue<int> qx, qy;

void add(int x, int y, int d) {
  c[x][y] += d;
  if(c[x][y] >= 4 && !inq[x][y]) {
    inq[x][y] = true;
    qx.push(x);
    qy.push(y);
  }
}

int main(int argc, char *argv[]){
  int N, T; 
  scanf("%d%d", &N, &T);
  int S = MAXN/2;
  add(S, S, N);
  while(!qx.empty()) {
    int x = qx.front(), y = qy.front(); qx.pop(); qy.pop();
    inq[x][y] = false;
    int d = c[x][y] / 4;
    add(x-1, y, d); add(x+1, y, d); add(x, y-1, d);  add(x, y+1, d);
    c[x][y] %= 4;
  }
  /*
  FOR(i, MAXN/2 - 50, MAXN/2 + 50) {
    FOR(j, MAXN/2 - 50, MAXN/2 + 50) printf("%d", c[i][j]);
    printf("\n");
  }
  */
  while(T--) {
    int X, Y;
    scanf("%d%d", &X, &Y);
    if (X + S < 0 || X + S >= MAXN || Y + S < 0 || Y + S >= MAXN) printf("0\n");
    else printf("%d\n", c[X + S][Y + S]);
  }
  return 0;
}
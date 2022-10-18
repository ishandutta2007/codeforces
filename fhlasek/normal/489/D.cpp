/* Written by Filip Hlasek 2014 */
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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 3033
int N, M;
int ga[MAXN][MAXN], GA[MAXN];
int gb[MAXN][MAXN], GB[MAXN];
bool g[MAXN][MAXN];

int wa[MAXN][MAXN], wb[MAXN][MAXN];

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int x, y;
    scanf("%d%d", &x, &y); x--; y--;
    ga[x][GA[x]++] = y;
    gb[y][GB[y]++] = x;
    g[x][y] = true;
  }

  long long total = 0;
  REP(i, N) {
    sort(ga[i], ga[i] + GA[i]);
    REP(x, GA[i]) REP(y, x) wa[ga[i][x]][ga[i][y]]++;
    sort(gb[i], gb[i] + GB[i]);
    REP(x, GB[i]) REP(y, x) wb[gb[i][x]][gb[i][y]]++;
    int bothways = 0;
    REP(x, GA[i]) if (g[ga[i][x]][i]) bothways++;
    total -= (long long)bothways * (bothways - 1) / 2;
  }

  REP(i, N) REP(j, i) total += (long long)wa[i][j] * wb[i][j];

  cout << total << endl;

  return 0;
}
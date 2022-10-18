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

bool dp[55][55][55][55];
int N;
char card[55][3];

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%s", card[N - i - 1]);
  card[N][0] = card[N + 1][0] = card[N + 2][0] = '0';
  card[N][0] = card[N + 1][0] = card[N + 2][0] = 'O';
  dp[0][0][1][2] = true;
  REP(i, N - 1) REP(a, N + 3) REP(b, N + 3) REP(c, N + 3) if(dp[i][a][b][c]){
    if(card[a][0] == card[b][0] || card[a][1] == card[b][1]) dp[i+1][a][c][i+3] = true;
    if(card[a][0] == card[i+3][0] || card[a][1] == card[i+3][1]) dp[i+1][b][c][a] = true;
  }
  bool ok = false;
  REP(a, N + 3) REP(b, N + 3) REP(c, N + 3) if(dp[N-1][a][b][c]) ok = true;
  if(ok) printf("YES\n");
  else   printf("NO\n");
  return 0;
}
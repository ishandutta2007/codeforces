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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MAXN 55
char m[MAXN][MAXN];
int N,M;
bool visited[MAXN][MAXN];

void dfs(int x, int y){
  if(x < 0 || y < 0 || x >= N || y >= M || m[x][y] == '.' || visited[x][y]) return;
  visited[x][y] = true;
  dfs(x-1,y);
  dfs(x+1,y);
  dfs(x,y-1);
  dfs(x,y+1);
}

bool ok(){
  REP(i,N) REP(j,M) visited[i][j] = false;
  REP(i,N) REP(j,M) if(m[i][j] == '#'){
    dfs(i,j);
    REP(k,N) REP(l,M) if(m[k][l] == '#' && !visited[k][l]) return true;
    return false;
  }
  return false;
}

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&M);
  REP(i,N) scanf("%s",m[i]);
  int cnt = 0;
  REP(i,N) REP(j,M) cnt += (m[i][j] == '#');
  if(cnt < 3){
    printf("-1\n");
    return 0;
  }
  REP(i,N) REP(j,M) if(m[i][j] == '#'){
    m[i][j] = '.';
    if(ok()){ printf("1\n"); return 0; } 
    m[i][j] = '#';
  }
  printf("2\n");
  return 0;
}
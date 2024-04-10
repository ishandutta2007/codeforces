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

#define MAXN 1002
int graph[2*MAXN][MAXN],G[2*MAXN];
int R,C;
char m[MAXN][MAXN];
int dist[2*MAXN];
int q[2*MAXN],qstart,qend;

void add(int x,int d){
  if(dist[x] == -1){
    dist[x] = d;
    q[qend++] = x;
  }
}

int bfs(int start,int end){
  REP(i,2*MAXN) dist[i] = -1;
  qstart = qend = 0;
  add(start,0);
  while(qstart != qend){
    int x = q[qstart++];
    if(x == end) return dist[x];
    REP(i,G[x]) add(graph[x][i],dist[x]+1);
  }
  return -1;
}

int main(int argc, char *argv[]){
  scanf("%d%d",&R,&C); 
  int start = 0, end = R-1;
  REP(i,R) scanf("%s",m[i]);
  REP(i,R) REP(j,C){
    if(m[i][j] == '#'){
      graph[i][G[i]++] = j + R;
      graph[j+R][G[j+R]++] = i;
    }
  }
  printf("%d\n",bfs(0,R-1));
  return 0;
}
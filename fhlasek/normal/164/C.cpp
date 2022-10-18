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

#define MAXN 1111
int N,K;
int s[MAXN],t[MAXN],c[MAXN];
bool used[MAXN];

int cap[MAXN][MAXN],cost[MAXN][MAXN];
int g[MAXN][MAXN];

int E=0,Ea[10*MAXN],Eb[10*MAXN];

void addEdge(int x,int y){ Ea[E] = x; Eb[E++] = y; Ea[E] = y; Eb[E++] = x; }

long long dist[MAXN];
int Prev[MAXN],Prev_type[MAXN];
void go(int start,int end){
  REP(i,N) dist[i] = 10000000000000LL;
  dist[start] = 0;
  REP(i,N) Prev[i] = -1;
  REP(k,N) REP(e,E){
    int i = Ea[e], j = Eb[e];
    if(cap[i][j]>0){
      if(dist[j] > dist[i] + cost[i][j]){
        dist[j] = dist[i] + cost[i][j];
        Prev[j] = i;
        Prev_type[j] = 0;
      }
    }
    if(g[i][j]>0){
      if(dist[j] > dist[i]){
        dist[j] = dist[i];
        Prev[j] = i;
        Prev_type[j] = 1;
      }
    }
  }
  int x = end;
  while(Prev[x] != -1){
    if(Prev_type[x] == 0){
      cap[Prev[x]][x]--;
      cap[x][Prev[x]]++;
      if(cost[Prev[x]][x] > 0) used[x] = !used[x];
      else used[Prev[x]] = !used[Prev[x]];
    }
    else{
      g[Prev[x]][x]--;
      g[x][Prev[x]]++;
    }
    x = Prev[x];
  }
}


void mcmf(int start,int end){
  REP(i,K) go(start,end);
}

bool better(int x,int y){
  if(x == -1) return true;
  if(s[x] != s[y]) return s[y] < s[x];
  return y < x;
}

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&K);
  REP(i,N) scanf("%d%d%d",s+i,t+i,c+i);
  REP(i,N){
    g[i][N+1] = K;
    addEdge(i,N+1);
  }
  REP(i,N){
    g[N][i] = K;
    addEdge(i,N+1);
  }
  REP(i,N){
    int best1 = -1, best2 = -1;
    REP(j,N){
      if(j == i) continue;
      if(s[i] + t[i] <= s[j] && better(best1,j)) best1 = j;
      if(better(j,i) && better(best2,j)) best2 = j;
    }
    if(best1 == -1) best1 = N+1;
    if(best1 != -1){
      cap[i][best1] = 1;
      cost[i][best1] = -c[i];
      cost[best1][i] = c[i];
      addEdge(i,best1);
    }
    if(best2 != -1){
      g[i][best2] = K;
      addEdge(i,best2);
    }
  }
  N += 2;
  mcmf(N-2,N-1);
  REP(i,N-2){
    if(i) printf(" ");
    printf("%d",(int)used[i]);
  }
  printf("\n");
  return 0;
}
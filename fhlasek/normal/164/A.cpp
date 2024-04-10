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

#define MAXN 111111
vector<int> graph[MAXN],rgraph[MAXN];
int f[MAXN];
bool fA[MAXN],fG[MAXN];
int N,M;

queue<int> q;
void bfs1(int x){
  q.push(x);
  fA[x] = true;
  while(!q.empty()){
    x = q.front();
    q.pop();
    REP(i,graph[x].size()) if(!fA[graph[x][i]]){
      fA[graph[x][i]] = true;
      q.push(graph[x][i]);
    }
  }
}

void bfs2(int x){
  q.push(x);
  fG[x] = true;
  while(!q.empty()){
    x = q.front();
    q.pop();
    fG[x] = true;
    if(f[x] == 1) continue;
    REP(i,rgraph[x].size()) if(!fG[rgraph[x][i]]){
      fG[rgraph[x][i]] = true;
      q.push(rgraph[x][i]);
    }
  }
}

int main(int argc, char *argv[]){
  int a,b;
  scanf("%d%d",&N,&M); 
  REP(i,N) scanf("%d",f+i);
  REP(i,M){
    scanf("%d%d",&a,&b);
    graph[a-1].push_back(b-1);
    rgraph[b-1].push_back(a-1);
  }
  REP(i,N){
    if(f[i] == 1) bfs1(i);
    if(f[i] == 2) bfs2(i);
  }
  REP(i,N){
    if(fA[i] && fG[i]) printf("1\n");
    else printf("0\n");
  }
  return 0;
}
/* Written by Filip Hlasek 2012 */
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

int N, M, K; 
#define MAXN 111111
vector<int> graph[MAXN];
int t[MAXN], next[MAXN];

int main(int argc, char *argv[]){
  scanf("%d%d%d", &N, &M, &K);
  REP(i, M){
    int a, b;
    scanf("%d%d", &a, &b);
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }
  t[0] = 1;
  int v = 0;
  bool run = true;
  while(run){
    run = false;
    REP(i, graph[v].size()) if(!t[graph[v][i]]){
      next[v] = graph[v][i];
      t[next[v]] = t[v]+1;
      v = next[v];
      run = true;
      break;
    }
  }
  int best = graph[v][0];
  REP(i, graph[v].size()) if(t[graph[v][i]] < t[best]) best = graph[v][i];
  printf("%d\n", t[v] - t[best] + 1);
  int w = best;
  while(w != v){ printf("%d ", w + 1); w = next[w]; }
  printf("%d\n", w + 1);
  return 0;
}
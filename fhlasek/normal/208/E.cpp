/* Writen by Filip Hlasek 2012 */
#pragma comment (linker, "/STACK:65777216")
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

#define MAXN 111111
#define LOG 20
#define SQ 600

class Graph{
  public:
    int start[MAXN], n[2 * MAXN], tmp[MAXN], eA[MAXN], eB[MAXN], N, M;
    void buildFromEdges(int _N, int _M){
      N = _N;
      M = _M;
      REP(i,N) tmp[i] = 0;
      REP(i,M){
        tmp[eA[i]]++;
        tmp[eB[i]]++; // comment if only one direction
      }
      REP(i,N) start[i+1] = start[i] + tmp[i];
      REP(i,M){
        int a = start[eA[i]] + (--tmp[eA[i]]), b = start[eB[i]] + (--tmp[eB[i]]);
        n[a] = eB[i];
        n[b] = eA[i]; // comment if only one direction
      }
    }
};
int s[MAXN], S;
class Tree : public Graph{
  public:
    int father[MAXN], depth[MAXN], root;
    void buildFromEdges(int _N){
      Graph::buildFromEdges(_N, _N - 1);
      root = 0;
      father[root] = root;
      depth[root] = 0;
      S = 0;
      s[S++] = root;
      while(S){
        int x = s[S-1];
        S--;
        for(int i = start[x]; i < start[x+1]; i++) if(n[i] != father[x]){
          father[n[i]] = x;
          depth[n[i]] = depth[x] + 1;
          s[S++] = n[i];
        }
      }
    }
    
    int left[MAXN], right[MAXN], array[MAXN], INDEX;
    void decompose_dfs(int v){
      array[INDEX] = depth[v]; // WHATEVER
      left[v] = INDEX++;
      for(int i = start[v]; i < start[v+1]; i++) if(n[i] != father[v]) decompose_dfs(n[i]);
      right[v] = INDEX;
    }
    void decompose(){
      INDEX = 0;
      decompose_dfs(0);
    }

    int _lca[MAXN][LOG];
    void initLCA(){
      REP(i,N) _lca[i][0] = father[i];
      REP(l,LOG-1) REP(i,N) _lca[i][l+1] = _lca[_lca[i][l]][l];
    }
    int up(int v, int dist){
      REP(i, LOG) if(dist & (1 << i)) v = _lca[v][i];
      return v;
    }
    int lca(int a, int b){
      if(depth[b] > depth[a]) swap(a, b);
      a = up(a, depth[a] - depth[b]);
      if(a == b) return a;
      FORD(i,LOG-1,0) if(_lca[a][i] != _lca[b][i]){
        a = _lca[a][i];
        b = _lca[b][i];
      }
      return father[a];
    }
 
    int _array[MAXN / SQ + 2][MAXN], _a[MAXN];
    void init_array(){
      REP(i,N) _a[i] = 0;
      REP(i,N+1){
        if(i % SQ == 0) REP(j, N) _array[i / SQ][j] = _a[j];
        if(i < N) _a[array[i]]++;
      }
    }
    int get_array(int pos, int d){
      int ans = _array[pos / SQ][d];
      FOR(i,(pos/SQ)*SQ, pos - 1) if(array[i] == d) ans++;
      return ans;
    }

    int solve(int v, int p){
      p = up(v, p);
      if(!p) return 0;
      return get_array(right[p], depth[v]) - get_array(left[p], depth[v]) - 1;
    }
};

Tree t;
int main(int argc, char *argv[]){
  int N;
  scanf("%d", &N);
  N++;
  REP(i,N-1){
    int f;
    scanf("%d", &f);
    t.eA[i] = i + 1; t.eB[i] = f;
  }
  t.buildFromEdges(N);
  t.initLCA();
  t.decompose();
  t.init_array();
  int Q, v, p;

  scanf("%d",&Q);
  while(Q--){
    scanf("%d%d",&v,&p);
    printf("%d", t.solve(v, p));
    if(Q) printf(" ");
  }
  printf("\n");
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define N 202020
#define PB push_back
#define SZ(X) ((int)X.size())
struct BccVertex {
#define MXN 202020
  int n,nScc,step,dfn[MXN],low[MXN];
  vector<int> E[MXN],sccv[MXN];
  int top,stk[MXN];
  void init(int _n) {
    n = _n;
    nScc = step = 0;
    for (int i=1; i<=n; i++) E[i].clear();
  }
  void add_edge(int u, int v) {
    E[u].PB(v);
    E[v].PB(u);
  }
  void DFS(int u, int f) {
    dfn[u] = low[u] = step++;
    stk[top++] = u;
    for (auto v:E[u]) {
      if (v == f) continue;
      if (dfn[v] == -1) {
        DFS(v,u);
        low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u]) {
          int z;
          sccv[nScc].clear();
          do {
            z = stk[--top];
            sccv[nScc].PB(z);
          } while (z != v);
          sccv[nScc].PB(u);
          nScc++;
        }
      } else {
        low[u] = min(low[u],dfn[v]);
      }
    }
  }
  vector<vector<int>> solve() {
    vector<vector<int>> res;
    for (int i=1; i<=n; i++) {
      dfn[i] = low[i] = -1;
    }
    for (int i=1; i<=n; i++) {
      if (dfn[i] == -1) {
        top = 0;
        DFS(i,i);
      }
    }
    for( int i = 0 ; i < nScc ; i ++ )
      res.PB(sccv[i]);
    return res;
  }
} graph;
int n , m;
vector< int > v[ N ];
vector< vector<int> > ret;
void init(){
  scanf( "%d%d" , &n , &m );
  graph.init( n );
  while( m -- ){
    int ui , vi; scanf( "%d%d" , &ui , &vi );
    graph.add_edge( ui , vi );
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  ret = graph.solve();
}
int cc[ N ] , ccstmp;
int dep[ N ] , stk[ N ];
vector< int > cyc;
bool go( int now , int far , int tdep ){
  dep[ now ] = tdep;
  stk[ tdep ] = now;
  for( int x : v[ now ] ){
    if( x == far ) continue;
    if( cc[ x ] != ccstmp ) continue;
    if( dep[ x ] ){
      for( int i = dep[ x ] ; i <= tdep ; i ++ )
        cyc.push_back( stk[ i ] );
      return true;
    }
    if( go( x , now , tdep + 1 ) )
      return true;
  }
  return false;
}
int cand , tail;
bool oncyc[ N ];
set< pair<int,int> > cyce;
bool gogo( int now , int far , int tdep ){
  dep[ now ] = tdep;
  stk[ tdep ] = now;
  for( int x : v[ now ] ){
    if( x == far ) continue;
    if( cc[ x ] != ccstmp ) continue;
    if( cyce.count( { now , x } ) ) continue;
    if( cyce.count( { x , now } ) ) continue;
    if( oncyc[ x ] && x != cand ){
      tail = x;
      stk[ tdep + 1 ] = x;
      for( int i = 1 ; i <= tdep ; i ++ )
        cyce.insert( { stk[ i ] , stk[ i + 1 ] } );
      return true;
    }
    if( dep[ x ] || oncyc[ x ] ) continue;
    if( gogo( x , now , tdep + 1 ) )
      return true;
  }
  return false;
}
void print( int now , int far , int tdep ){
  stk[ tdep ] = now;
  if( now == tail ){
    printf( "%d " , tdep );
    for( int i = 1 ; i <= tdep ; i ++ )
      printf( "%d%c" , stk[ i ] , " \n"[ i == tdep ] );
    return;
  }
  for( int x : v[ now ] ){
    if( x == far ) continue;
    print( x , now , tdep + 1 );
  }
}
void find_ans(){
  for( size_t i = 0 ; i < cyc.size() ; i ++ ){
    cyce.insert( { cyc[ i ] , cyc[ ( i + 1 ) % cyc.size() ] } );
    oncyc[ cyc[ i ] ] = true;
  }
  for( int i = 1 ; i <= n ; i ++ )
    dep[ i ] = 0;
  assert( gogo( cand , cand , 1 ) );
  for( int i = 1 ; i <= n ; i ++ )
    v[ i ].clear();
  for( auto e : cyce ){
    v[ e.first ].push_back( e.second );
    v[ e.second ].push_back( e.first );
  }
  puts( "YES" );
  print( cand , cand , 1 );
  exit( 0 );
}
void go( int now ){
  cyc.clear();
  if( !go( now , -1 , 1 ) ) return;
  cand = -1;
  for( int x : cyc ){
    int ee = 0;
    for( int y : v[ x ] )
      if( cc[ y ] == ccstmp )
        ee ++;
    if( ee > 2 ){
      cand = x;
      break;
    }
  }
  if( cand == -1 ) return;
  find_ans();
}
clock_t start;
void solve(){
  for( auto i : ret ){
    ++ ccstmp;
    for( int j : i ){
      dep[ j ] = 0;
      cc[ j ] = ccstmp;
    }
    go( i[ 0 ] );
    clock_t end = clock();
    if( (double)( end - start ) / CLOCKS_PER_SEC > 1.9 )
      break;
  }
  puts( "NO" );
}
int main(){
  start = clock();
  init();
  solve();
}
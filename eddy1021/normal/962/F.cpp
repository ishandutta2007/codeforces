#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
#define MXN 101010
#define PB push_back
#define REP(i,v) for(int i=0;i<v;i++)
struct BccVertex {
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
    REP(i,nScc) res.PB(sccv[i]);
    return res;
  }
}graph;
int n , m;
map< pair<int,int> , int > id;
unordered_set<int> S[ N ];
bool on[ N ];
void solve(){
  vector< vector<int> > ret = graph.solve();
  for( auto&& i : ret ){
    int sz = i.size();
    vector<int> eid;
    if( (LL)sz * sz < N ){
      for( size_t j = 0 ; j < i.size() ; j ++ )
        for( size_t k = j + 1 ; k < i.size() ; k ++ )
          if( S[ i[ j ] ].find( i[ k ] ) !=
              S[ i[ j ] ].end() )
            eid.push_back( id[ {i[ j ] , i[ k ]} ] );
    }else{
      unordered_set<int> cur;
      for( auto ii : i ) cur.insert( ii );
      for( auto ii : i ){
        for( auto j : S[ ii ] )
          if( cur.find( j ) != cur.end() )
            eid.push_back( id[ {ii , j} ] );
      }
      sort( eid.begin() , eid.end() );
      eid.resize( unique( eid.begin() , eid.end() ) - eid.begin() );
    }
    if( eid.size() == i.size() ){
      for( auto j : eid )
        on[ j ] = true;
    }
  }
  vector<int> ans;
  for( int i = 1 ; i <= m ; i ++ )
    if( on[ i ] )
      ans.push_back( i );
  printf( "%d\n" , (int)ans.size() );
  for( auto x : ans )
    printf( "%d " , x );
  puts( "" );
}
int main(){
  scanf( "%d%d" , &n , &m );
  graph.init( n );
  for( int i = 1 ; i <= m ; i ++ ){
    int ui , vi;
    scanf( "%d%d" , &ui , &vi );
    graph.add_edge( ui , vi );
    S[ ui ].insert( vi );
    S[ vi ].insert( ui );
    id[ {ui, vi} ] =
    id[ {vi, ui} ] = i;
  }
  solve();
}
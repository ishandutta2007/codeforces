/********************************************************/
/*             _      _          _   __      __      _  */
/*            ( )    ( )       /' )/' _`\  /'__`\  /' ) */
/*    __     _| |   _| | _   _(_, || ( ) |(_)  ) )(_, | */
/*  /'__`\ /'_` | /'_` |( ) ( ) | || | | |   /' /   | | */
/* (  ___/( (_| |( (_| || (_) | | || (_) | /' /( )  | | */
/* `\____)`\__,_)`\__,_)`\__, | (_)`\___/'(_____/'  (_) */
/*                      ( )_| |                         */
/*                      `\___/'                         */
/*                                                      */
/********************************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
/*
  A template for Min Cost Max Flow
  tested with TIOJ 1724
*/
struct MinCostMaxFlow{
typedef int Tcost;
  static const int MAXV = 20010;
  static const int INFf = 1000000;
  static const Tcost INFc  = 1e9;
  struct Edge{
    int v, cap;
    Tcost w;
    int rev;
    Edge(){}
    Edge(int t2, int t3, Tcost t4, int t5)
    : v(t2), cap(t3), w(t4), rev(t5) {}
  };
  int V, s, t;
  vector<Edge> g[MAXV];
  void init(int n){
    V = n+2;
    s = n+1, t = n+2;
    for(int i = 0; i <= V; i++) g[i].clear();
  }
  void addEdge(int a, int b, int cap, Tcost w){
    g[a].push_back(Edge(b, cap, w, (int)g[b].size()));
    g[b].push_back(Edge(a, 0, -w, (int)g[a].size()-1));
  }
  Tcost d[MAXV];
  int id[MAXV], mom[MAXV];
  bool inqu[MAXV];
  queue<int> q;
  Tcost solve(){
    int mxf = 0; Tcost mnc = 0;
    while(1){
      fill(d, d+1+V, INFc);
      fill(inqu, inqu+1+V, 0);
      fill(mom, mom+1+V, -1);
      mom[s] = s;
      d[s] = 0;
      q.push(s); inqu[s] = 1;
      while(q.size()){
        int u = q.front(); q.pop();
        inqu[u] = 0;
        for(int i = 0; i < (int) g[u].size(); i++){
          Edge &e = g[u][i];
          int v = e.v;
          if(e.cap > 0 && d[v] > d[u]+e.w){
            d[v] = d[u]+e.w;
            mom[v] = u;
            id[v] = i;
            if(!inqu[v]) q.push(v), inqu[v] = 1;
          }
        }
      }
      if(mom[t] == -1) break ;
      int df = INFf;
      for(int u = t; u != s; u = mom[u])
        df = min(df, g[mom[u]][id[u]].cap);
      for(int u = t; u != s; u = mom[u]){
        Edge &e = g[mom[u]][id[u]];
        e.cap             -= df;
        g[e.v][e.rev].cap += df;
      }
      mxf += df;
      mnc += df*d[t];
    }
    return mnc;
  }
} flow;
#define N 111
int n , q , l[ N ] , r[ N ];
int main(){
  cin >> n >> q;
  for( int i = 1 ; i <= n ; i ++ )
    l[ i ] = 1 , r[ i ] = n;
  while( q -- ){
    int cmd , li , ri , xi;
    cin >> cmd >> li >> ri >> xi;
    if( cmd == 1 ){
      for( int i = li ; i <= ri ; i ++ )
        l[ i ] = max( l[ i ] , xi );
    }else{
      for( int i = li ; i <= ri ; i ++ )
        r[ i ] = min( r[ i ] , xi );
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( l[ i ] > r[ i ] ){
      puts( "-1" );
      exit(0);
    }
  flow.init( n + n );
  for( int i = 1 ; i <= n ; i ++ )
    flow.addEdge( flow.s , i , 1 , 0 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = l[ i ] ; j <= r[ i ] ; j ++ )
      flow.addEdge( i , j + n , 1 , 0 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      flow.addEdge( i + n , flow.t , 1 , j + j - 1 );
  cout << flow.solve() << endl;
}
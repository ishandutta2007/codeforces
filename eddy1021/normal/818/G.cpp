#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
inline int getint(){
  int _x=0; char _tc=getchar();    
  while(_tc<'0'||_tc>'9') _tc=getchar();
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x;
}
/*
  A template for Min Cost Max Flow
  tested with TIOJ 1724
*/
struct MinCostMaxFlow{
  static const int MAXV = 10010;
  static const int INF  = 1000000;
  struct Edge{
    int v, cap, w, rev;
    Edge(){}
    Edge(int t2, int t3, int t4, int t5)
    : v(t2), cap(t3), w(t4), rev(t5) {}
  };
  int V, s, t;
  vector<Edge> g[MAXV];
  void init(int n){
    V = n+2;
    s = n+1, t = n+2;
    for(int i = 1; i <= V; i++) g[i].clear();
  }
  void addEdge(int a, int b, int cap, int w){
    g[a].push_back(Edge(b, cap, w, (int)g[b].size()));
    g[b].push_back(Edge(a, 0, -w, (int)g[a].size()-1));
  }
  int d[MAXV], id[MAXV], mom[MAXV];
  bool inqu[MAXV];
  //the size of qu should be much large than MAXV
  int solve(){
    int mxf = 0, mnc = 0;
    while(1){
      fill(d+1, d+1+V, INF);
      fill(inqu+1, inqu+1+V, 0);
      fill(mom+1, mom+1+V, -1);
      mom[s] = s;
      d[s] = 0;
      queue<int> Q;
      Q.push(s);
      inqu[s] = 1;
      while(not Q.empty()){
        int u = Q.front(); Q.pop();
        inqu[u] = 0;
        for(int i = 0; i < (int) g[u].size(); i++){
          Edge &e = g[u][i];
          int v = e.v;
          if(e.cap > 0 && d[v] > d[u]+e.w){
            d[v] = d[u]+e.w;
            mom[v] = u;
            id[v] = i;
            if(!inqu[v]) Q.push(v), inqu[v] = 1;
          }
        }
      }
      if(mom[t] == -1) break ;
      int df = INF;
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
#define N 3030
int n , a[ N ];
void init(){
  n = getint();
  //n = 3000;
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    //a[ i ] = 2 - (i % 2);
  }
}
void solve(){
  flow.init( n + n + 1 );
  int s = n + n + 1;
  flow.addEdge( flow.s , s , 4 , 0 );
// void addEdge(int a, int b, int cap, int w){
  for( int i = 1 ; i <= n ; i ++ ){
    flow.addEdge( s , i , 1 , 0 );
    flow.addEdge( i , i + n , 1 , -1 );
    flow.addEdge( i + n , flow.t , 1 , 0 );
    //for( int j = i + 1 ; j <= n ; j ++ )
      //if( abs( a[ i ] - a[ j ] ) == 1 or a[ i ] % 7 == a[ j ] % 7 )
        //flow.addEdge( i + n , j , 1 , 0 );
    int con = 0;
    int neg = 0;
    int pos = 0;
#define MAGIC 10
    for( int j = i + 1 ; j <= n ; j ++ ){
      if( a[ j ] - a[ i ] == -1 and neg < MAGIC ){
        neg ++;
        flow.addEdge( i + n , j , 1 , 0 );
      }
      if( a[ j ] - a[ i ] == +1 and pos < MAGIC ){
        pos ++;
        flow.addEdge( i + n , j , 1 , 0 );
      }
      if( a[ j ] % 7 == a[ i ] % 7 and con < MAGIC ){
        con ++;
        flow.addEdge( i + n , j , 1 , 0 );
      }
    }
  }
  cout << -flow.solve() << endl;
}
int main(){
  init();
  solve();
}
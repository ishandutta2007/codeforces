#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
/*
  A template for Min Cost Max Flow
  tested with TIOJ 1724
*/
struct MinCostMaxFlow{
  static const int MAXV = 110;
  static const int INF  = 1000000000;
  struct Edge{
    int v, cap;
    double w;
    int rev;
    Edge(){}
    Edge(int t2, int t3, double t4, int t5)
    : v(t2), cap(t3), w(t4), rev(t5) {}
  };
  int V, s, t;
  vector<Edge> g[MAXV];
  void init(int n){
    V = n+2;
    s = n+1, t = n+2;
    for(int i = 1; i <= V; i++) g[i].clear();
  }
  void addEdge(int a, int b, int cap, double w){
    //printf( "%d -(cap=%d, w=%.4f)-> %d\n" , a , cap , w , b );
    g[a].push_back(Edge(b, cap, w, (int)g[b].size()));
    g[b].push_back(Edge(a, 0, -w, (int)g[a].size()-1));
  }
  double d[ MAXV ];
  int id[MAXV], mom[MAXV];
  bool inqu[MAXV];
  queue<int> qu;
  //the size of qu should be much large than MAXV
  double solve(){
    int mxf = 0;
    double mnc = 0;
    while(1){
      for( int i = 0 ; i <= V ; i ++ ){
        d[ i ] = 1e9;
        inqu[ i ] = false;
        mom[ i ] = -1;
      }
      mom[s] = s;
      d[s] = 0;
      qu.push(s);
      inqu[s] = 1;
      while(qu.size()){
        int u = qu.front(); qu.pop();
        inqu[u] = 0;
        for(int i = 0; i < (int) g[u].size(); i++){
          Edge &e = g[u][i];
          int v = e.v;
          if(e.cap > 0 && d[v] > d[u]+e.w + eps){
            d[v] = d[u]+e.w;
            mom[v] = u;
            id[v] = i;
            if(!inqu[v]){
              qu.push(v);
              inqu[v] = 1;
            }
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
int nf , ne , ns;
int rf , re , rs;
int df , de;
double drf , dre , drs;
void init(){
  cin >> nf >> ne >> ns;
  cin >> rf >> re >> rs;
  cin >> df >> de;
  drf = sqrt( rf * rf - 1 );
  dre = sqrt( re * re - 1 );
  drs = sqrt( rs * rs - 1 );
}
#define N 13
// 0123456789012
// XOXOXOXOXOXOO
// OOOOOOOOOOOOO
double ans;
int f[ N + N ];
pair<double, pair<int,int>> vv[ 99 ];
double score( int at , double r , int d ){
  //vector< pair<double, pair<int,int> > > vv;
  int vt = 0;
  vv[ vt ++ ] = { at - r , { 1 , +d } };
  vv[ vt ++ ] = { at + r , { 1 , -d } };
  //vv.push_back( { at - r , { 1 , +d } } );
  //vv.push_back( { at + r , { 1 , -d } } );
  int tms = 1 , dmg = 0;
  for( int i = 0 ; i < N ; i ++ ){
    if( f[ i ] == 0 ) continue;
    if( i + drs < at - r ) continue;
    if( i - drs > at + r ) continue;
    if( i - drs < at - r )
      tms += f[ i ];
    else{
      vv[ vt ++ ] = { i - drs , { 0 , +f[ i ] } };
      //vv.push_back( { i - drs , { 0 , +f[ i ] } } );
    }
    if( i + drs < at + r ){
      vv[ vt ++ ] = { i + drs , { 0 , -f[ i ] } };
      //vv.push_back( { i + drs , { 0 , -f[ i ] } } );
    }
  }
  //sort( vv.begin() , vv.end() );
  sort( vv , vv + vt );
  double ret = 0;
  for( int i = 0 ; i + 1 < vt ; i ++ ){
  //for( size_t i = 0 ; i + 1 < vv.size() ; i ++ ){
    double tint = vv[ i + 1 ].first - vv[ i ].first;
    //if( vv[ i ].first > at + r )
      //break;
    if( vv[ i ].second.first )
      dmg += vv[ i ].second.second;
    else
      tms += vv[ i ].second.second;
    ret += tint * dmg * tms;
  }
  return ret;
}
double dp[ 22 ][ 22 ];
inline int enc(){
  int ret1 = 0;
  for( int i = 0 ; i < N ; i ++ )
    ret1 = (ret1 << 2) | f[ i ];
  int ret2 = 0;
  for( int i = N - 1 ; i >= 0 ; i -- )
    ret2 = (ret2 << 2) | f[ i ];
  return min( ret1 , ret2 );
}
unordered_set<int> vst;
void cal(){
  int r = enc();
  if( vst.find( r ) != vst.end() )
    return;
  vst.insert( r );
  if( ns < 12 ){
    flow.init( 2 + N );
    flow.addEdge( flow.s , N + 1 , nf , 0 );
    flow.addEdge( flow.s , N + 2 , ne , 0 );
    for( int i = 0 ; i < N ; i ++ ){
      if( f[ i ] == 2 ) continue;
      double scoref = score( i , drf , df );
      double scoree = score( i , dre , de );
      flow.addEdge( N + 1 , i + 1 , 2 - f[ i ] , -scoref );
      flow.addEdge( N + 2 , i + 1 , 2 - f[ i ] , -scoree );
      flow.addEdge( i + 1 , flow.t , 2 - f[ i ] , 0 );
      //for( int j = f[ i ] ; j < 2 ; j ++ ){
        //sf.push_back( scoref );
        //se.push_back( scoree );
      //}
    }
    double tret = -flow.solve();
    ans = max( ans , tret );
    return;
  }
  vector< double > sf , se;
  for( int i = 0 ; i < N ; i ++ ){
    if( f[ i ] == 2 ) continue;
    double scoref = score( i , drf , df );
    double scoree = score( i , dre , de );
    for( int j = f[ i ] ; j < 2 ; j ++ ){
      sf.push_back( scoref );
      se.push_back( scoree );
    }
  }
  sort( sf.begin() , sf.end() , greater<double>() );
  sort( se.begin() , se.end() , greater<double>() );
  for( int i = 0 ; i <= nf ; i ++ )
    for( int j = 0 ; j <= ne ; j ++ )
      dp[ i ][ j ] = 0.0;
  for( int i = 0 ; i <= nf ; i ++ )
    for( int j = 0 ; j <= ne ; j ++ ){
      int nxt = i + j;
      if( i < nf )
        dp[ i + 1 ][ j ] = max( dp[ i + 1 ][ j ] ,
                                dp[ i ][ j ] + sf[ nxt ] );
      if( j < ne )
        dp[ i ][ j + 1 ] = max( dp[ i ][ j + 1 ] ,
                                dp[ i ][ j ] + se[ nxt ] );
    }
  ans = max( ans , dp[ nf ][ ne ] );
  //for( int i = 0 ; i < N ; i ++ )
    //printf( "%d%c" , f[ i ] , " \n"[ i + 1 == N ] );
  //printf( "%.12f\n" , dp[ nf ][ ne ] );
}
void go( int now , int res ){
  if( now == N ){
    if( res == 0 )
      cal();
    return;
  }
  if( ( N - now ) * 2 < res )
    return;
  for( int i = 0 ; i <= min( 2 , res ) ; i ++ ){
    f[ now ] = i;
    go( now + 1 , res - i );
  }
}
void solve(){
  go( 0 , ns );
  printf( "%.12f\n" , ans );
}
int main(){
  init();
  solve();
}
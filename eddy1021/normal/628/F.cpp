// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
#define mod9 1000000009ll
#define mod7 1000000007ll
// #define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 10101
struct Maxflow {
  static const int MAXV = 20010;
  static const int INF  = 1000000;
  struct Edge {
    int v, c, r;
    Edge(int _v, int _c, int _r) : v(_v), c(_c), r(_r) {}
  };
  int s, t;
  vector<Edge> G[MAXV*2];
  int iter[MAXV*2], d[MAXV*2], gap[MAXV*2], tot;
  void flowinit(int x) {
    tot = x+2;
    s = x+1, t = x+2;
    for(int i = 0; i <= tot; i++) {
      G[i].clear();
      iter[i] = d[i] = gap[i] = 0;
    }
  }
  void addEdge(int u, int v, int c) {
    G[u].push_back(Edge(v, c, SZ(G[v]) ));
    G[v].push_back(Edge(u, 0, SZ(G[u]) - 1));
  }
  int dfs(int p, int flow) {
    if(p == t) return flow;
    for(int &i = iter[p]; i < SZ(G[p]); i++) {
      Edge &e = G[p][i];
      if(e.c > 0 && d[p] == d[e.v]+1) {
        int f = dfs(e.v, min(flow, e.c));
        if(f) {
          e.c -= f;
          G[e.v][e.r].c += f;
          return f;
        }
      }
    }
    if( (--gap[d[p]]) == 0) d[s] = tot;
    else {
      d[p]++;
      iter[p] = 0;
      ++gap[d[p]];
    }
    return 0;
  }
  int maxflow() {
    //puts("MF");
    int res = 0;
    gap[0] = tot;
    for(res = 0; d[s] < tot; res += dfs(s, INF));
    return res;
  }
} flow;
void build(){

}
int n , b , q;
vector<PII> v;
void init(){
  n = getint();
  b = getint();
  q = getint();
  v.PB( MP( 0 , 0 ) );
  v.PB( MP( b , n ) );
  for( int i = 0 ; i < q ; i ++ ){
    int ui = getint();
    int qi = getint();
    v.PB( MP( ui , qi ) );
  }
  q ++;
  sort( ALL( v ) );
}
int res[ 5 ] , md[ 5 ];
void solve(){
  for( int i = 1 ; i <= q ; i ++ )
    if( v[ i ].FI - v[ i - 1 ].FI <
        v[ i ].SE - v[ i - 1 ].SE ||
        v[ i ].SE < v[ i - 1 ].SE ){
      puts( "unfair" );
      return;
    }
  for( int i = 1 ; i < q ; i ++ )
    if( v[ i ].FI == v[ i + 1 ].FI &&
        v[ i ].SE != v[ i + 1 ].SE ){
      puts( "unfair" );
      return;
    }
  int per = n / 5;
  for( int i = 1 ; i <= b ; i ++ )
    res[ i % 5 ] ++;
  for( int i = 1 ; i <= q ; i ++ )
    if( v[ i ].SE == v[ i - 1 ].SE ){
      for( int k = v[ i - 1 ].FI + 1 ; k <= v[ i ].FI ; k ++ )
        res[ k % 5 ] --;
    }
  for( int i = 0 ; i < 5 ; i ++ )
    if( res[ i ] < per ){
      puts( "unfair" );
      return;
    }
  flow.flowinit( 5 + q + b );
  for( int i = q + b + 1 ; i <= q + b + 5 ; i ++ ){
    flow.addEdge( flow.s , i , per );
    md[ i - ( q + b + 1 ) ] = i;
  }
  for( int i = 1 ; i <= b ; i ++ )
    flow.addEdge( md[ i % 5 ] , i , 1 );
  for( int i = 1 ; i <= q ; i ++ ){
    for( int j = v[ i - 1 ].FI + 1 ; j <= v[ i ].FI ; j ++ )
      flow.addEdge( j , b + i , 1 );
    if( v[ i ].SE > v[ i - 1 ].SE )
      flow.addEdge( b + i , flow.t , v[ i ].SE - v[ i - 1 ].SE );
  }
  if( flow.maxflow() == n )
    puts( "fair" );
  else
    puts( "unfair" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
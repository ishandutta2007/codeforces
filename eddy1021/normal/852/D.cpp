// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
//#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 666
//#define SZ(c) ((int)(c).size())
struct Maxflow {
  static const int MAXV = 20010;
  static const int INF  = 1000000;
  struct Edge {
    int v, c, r;
    Edge(int _v, int _c, int _r):
      v(_v), c(_c), r(_r) {}
  };
  int s, t;
  vector<Edge> G[MAXV*2];
  int iter[MAXV*2], d[MAXV*2], gap[MAXV*2], tot;
  void init(int x) {
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
  int solve() {
    int res = 0;
    gap[0] = tot;
    for(res = 0; d[s] < tot; res += dfs(s, INF));
    return res;
  }
} flow;
void build(){

}
#define inf (1731311 * 2)
int v , e , n , K , s[ N ];
int d[ N ][ N ] , ss[ N ];
void init(){
  v = getint();
  e = getint();
  n = getint();
  K = getint();
  for( int i = 1 ; i <= n ; i ++ )
    ss[ getint() ] ++;
  for( int i = 1 ; i <= v ; i ++ ){
    for( int j = 1 ; j <= v ; j ++ )
      d[ i ][ j ] = inf;
    d[ i ][ i ] = 0;
  }
  while( e -- ){
    int ai = getint();
    int bi = getint();
    int wi = getint();
    if( wi < d[ ai ][ bi ] )
      d[ ai ][ bi ] = d[ bi ][ ai ] = wi;
  }
  for( int k = 1 ; k <= v ; k ++ )
    for( int i = 1 ; i <= v ; i ++ )
      for( int j = 1 ; j <= v ; j ++ )
        if( d[ i ][ k ] + d[ k ][ j ] < d[ i ][ j ] )
          d[ i ][ j ] = d[ i ][ k ] + d[ k ][ j ];
}
bool okay( int tar ){
  flow.init( v + v );
  for( int i = 1 ; i <= v ; i ++ ){
    if( ss[ i ] )
      flow.addEdge( flow.s , i , ss[ i ] );
    flow.addEdge( v + i , flow.t , 1 );
    for( int j = 1 ; j <= v ; j ++ )
      if( d[ i ][ j ] <= tar )
        flow.addEdge( i , v + j , 1 );
  }
  return flow.solve() >= K;
}
void solve(){
  int bl = 0 , br = 1731311 , ba = -1;
  while( bl <= br ){
    int bmid = (bl + br) >> 1;
    if( okay( bmid ) ) ba = bmid , br = bmid - 1;
    else bl = bmid + 1;
  }
  printf( "%d\n" , ba );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
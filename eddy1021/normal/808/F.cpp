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
//#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
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
#define SZ(c) ((int)(c).size())
static const int INF  = 1000000;
struct Maxflow {
  static const int MAXV = 20010;
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
    //puts("MF");
    int res = 0;
    gap[0] = tot;
    for(res = 0; d[s] < tot; res += dfs(s, INF));
    return res;
  }
} flow;
#define P 202020
bool pr[ 202020 ];
void build(){
  for( int i = 0 ; i < P ; i ++ ) pr[ i ] = true;
  for( int i = 2 ; i < P ; i ++ ) if( pr[ i ] )
    for( int j = i + i ; j < P ; j += i )
      pr[ j ] = false;
}
#define N 111
int n , k;
int p[ N ] , c[ N ] , l[ N ];
int go( const vector< pair<int,int> >& odd ,
        const vector< pair<int,int> >& even ){
  if( odd.empty() or even.empty() ) return 0;
  int osz = (int)odd.size();
  int esz = (int)even.size();
  flow.init( osz + esz );
  for( int i = 0 ; i < osz ; i ++ )
    flow.addEdge( flow.s , i , odd[ i ].first );
  for( int i = 0 ; i < esz ; i ++ )
    flow.addEdge( osz + i , flow.t , even[ i ].first );
  for( int i = 0 ; i < osz ; i ++ )
    for( int j = 0 ; j < esz ; j ++ )
      if( pr[ odd[ i ].second + even[ j ].second ] )
        flow.addEdge( i , osz + j , INF );
  return flow.solve();
}
bool okay( int lvl ){
  vector< pair<int,int> > v[ 2 ];
  int bst = -1 , sum = 0;
  for( int i = 0 ; i < n ; i ++ ){
    if( l[ i ] > lvl ) continue;
    if( c[ i ] == 1 ){
      if( bst == -1 ) bst = i;
      else if( p[ i ] > p[ bst ] )
          bst = i;
    }else
      v[ c[ i ] % 2 ].push_back( { p[ i ] , c[ i ] } );
  }
  if( bst != -1 ) v[ 1 ].push_back( { p[ bst ] , 1 } );
  for( auto i : v[ 0 ] ) sum += i.first;
  for( auto i : v[ 1 ] ) sum += i.first;
  sum -= go( v[ 0 ] , v[ 1 ] );
  return sum >= k;
}
void init(){
  n = getint();
  k = getint();
  for( int i = 0 ; i < n ; i ++ ){
    p[ i ] = getint();
    c[ i ] = getint();
    l[ i ] = getint();
  }
}
void solve(){
  int bl = 1 , br = n , ba = -1;
  while( bl <= br ){
    int bmid = ( bl + br ) >> 1;
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
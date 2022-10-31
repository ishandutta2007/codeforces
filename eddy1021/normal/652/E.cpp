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
#define INF  1023456789ll
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
#define N 606060
struct Arc{
  int to , nxt;
  bool vl;
  Arc(){ vl = false; to = nxt = 0; }
}r[ N ];
int n , m , from[ N ] , mcnt = 1 , u , v;
int p[ N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  p[ x ] = y;
}
void add_edge( int a , int b , int c ){
  r[ ++ mcnt ].to = b;
  r[ mcnt ].vl = c;
  r[ mcnt ].nxt = from[ a ];
  from[ a ] = mcnt;
}
void build(){
  
}
void init(){
  n = getint(); m = getint();
  for( int i = 0 ; i < m ; i ++ ){
    int ai = getint();
    int bi = getint();
    int ci = getint();
    add_edge( ai , bi , ci );
    add_edge( bi , ai , ci );
  }
  u = getint(); v = getint();
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i;
}
int low[ N ] , dis[ N ] , tcnt;
bool vst[ N ];
void DFS( int now , int prt ){
  low[ now ] = dis[ now ] = ++ tcnt;
  vst[ now ] = true;
  int xxx = 0;
  for( int i = from[ now ] ; i ; i = r[ i ].nxt ){
    int nxt = r[ i ].to;
    if( nxt == prt && xxx == 0 ){
      xxx ++;
      continue;
    }
    if( !vst[ nxt ] ){
      DFS( nxt , now );
      low[ now ] = min( low[ now ] , low[ nxt ] );
      if( low[ nxt ] <= dis[ now ] )
        Union( nxt , now );
    }else
      low[ now ] = min( low[ now ] , dis[ nxt ] );
  }
}
bool g[ N ] , ans;
vector<PII> rr[ N ];
void gogogo( int now , bool okay , int prt ){
  if( ans ) return;
  if( find_p( now ) == find_p( v ) ){
    if( okay || g[ find_p( now ) ] )
      ans = true;
    return;
  }
  for( size_t i = 0 ; i < rr[ now ].size() ; i ++ ){
    int nxt = rr[ now ][ i ].FI;
    if( nxt == prt ) continue;
    if( find_p( now ) == find_p( nxt ) ) continue;
    gogogo( nxt , okay || rr[ now ][ i ].SE || g[ find_p( now ) ] , now );
  }
}
void solve(){
  DFS( 1 , -1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = from[ i ] ; j ; j = r[ j ].nxt )
      if( find_p( i ) == find_p( r[ j ].to ) && r[ j ].vl )
        g[ find_p( i ) ] = true;
      else if( find_p( i ) != find_p( r[ j ].to ) )
        rr[ find_p( i ) ].PB( MP( find_p( r[ j ].to ) , r[ j ].vl ) );
  // for( int i = 1 ; i <= n ; i ++ )
    // printf( "%d %d %d\n" , i , find_p( i ) , g[ i ] );
  gogogo( find_p( u ) , false , -1 );
  puts( ans ? "YES" : "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
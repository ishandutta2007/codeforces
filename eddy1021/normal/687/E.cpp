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
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 5140
int n , m , scc[ N ] , scnt;
vector<int> g[ N ] , rg[ N ];
vector<int> st;
bool vst[ N ] , odeg[ N ];
void build(){

}
void dfs( int now ){
  vst[ now ] = true;
  for( int nxt : g[ now ] )
    if( !vst[ nxt ] )
      dfs( nxt );
  st.push_back( now );
}
void rdfs( int now ){
  vst[ now ] = true;
  scc[ now ] = scnt;
  for( int nxt : rg[ now ] )
    if( !vst[ nxt ] )
      rdfs( nxt );
}
inline void kosaraju(){
  for( int i = 1 ; i <= n ; i ++ )
    if( !vst[ i ] )
      dfs( i );
  reverse( ALL( st ) );
  for( int i = 1 ; i <= n ; i ++ )
    vst[ i ] = false;
  for( int i : st ){
    if( vst[ i ] ) continue;
    rdfs( i );
    scnt ++;
  }
}
void init(){
  n = getint();
  m = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    g[ ui ].push_back( vi );
    rg[ vi ].push_back( ui );
  }
  kosaraju();
  for( int i = 1 ; i <= n ; i ++ )
    for( int nxt : g[ i ] )
      if( scc[ i ] != scc[ nxt ] )
        odeg[ scc[ i ] ] = true;
}
int dep[ N ], mn , ss;
void go( int now , int ndep ){
  dep[ now ] = ndep;
  vst[ now ] = true;
  for( int nxt : g[ now ] ){
    if( scc[ now ] != scc[ nxt ] ) continue;
    if( nxt == ss ) mn = min( mn , dep[ now ] + 1 );
    else if( !vst[ nxt ] ) go( nxt , ndep + 1 );
  }
}
inline int find_cyc( int now ){
  for( int i = 1 ; i <= n ; i ++ )
    vst[ i ] = false;
  mn = N; ss = now;
  go( now , 0 );
  return mn;
}
void solve(){
  int sum = 0 , cnt = 0;
  for( int i = 0 ; i < scnt ; i ++ ){
    if( odeg[ i ] ) continue;
    int omn = N;
    for( int j = 1 ; j <= n ; j ++ )
      if( scc[ j ] == i )
        omn = min( omn , find_cyc( j ) );
    if( omn == N ) continue;
    cnt ++;
    sum += omn;
  }
  printf( "%d\n" , n + cnt + 998 * sum );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
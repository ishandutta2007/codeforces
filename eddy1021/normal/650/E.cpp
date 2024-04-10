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
#define N 505050
int n , p[ N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x == y ) return;
  p[ x ] = y;
}
set< PII > s[ 2 ];
typedef set< PII >::iterator si;
vector< PII > nxt[ N ];
PII pt[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ) p[ i ] = i;
  for( int ii = 0 ; ii < 2 ; ii ++ )
    for( int i = 1 ; i < n ; i ++ ){
      int ai = getint(); 
      int bi = getint(); 
      if( ai > bi ) swap( ai , bi );
      if( ii == 1 && s[ 0 ].count( MP( ai , bi ) ) ){
        s[ 0 ].erase( MP( ai , bi ) );
        Union( ai , bi );
      }else s[ ii ].insert( MP( ai , bi ) );
    }
}
vector< pair<PII,PII> > ans;
void DFS( int now , PII prt = MP( 0 , 0 ) ){
  pt[ now ] = prt;
  for( size_t i = 0 ; i < nxt[ now ].size() ; i ++ )
    if( nxt[ now ][ i ].FI != prt.SE )
      DFS( find_p( nxt[ now ][ i ].FI ) , nxt[ now ][ i ] );
}
void DFS2( int now , PII prt = MP( 0 , 0 ) ){
  for( size_t i = 0 ; i < nxt[ now ].size() ; i ++ )
    if( nxt[ now ][ i ].FI != prt.SE )
      DFS2( find_p( nxt[ now ][ i ].FI ) , nxt[ now ][ i ] );
  if( now == find_p( 1 ) ) return;
  ans.PB( MP( prt , pt[ now ] ) );
}
void build_edge( int idx ){
  for( si it = s[ idx ].begin() ; it != s[ idx ].end() ; it ++ ){
    nxt[ find_p( it->FI ) ].PB( MP( it->SE , it->FI ) );
    nxt[ find_p( it->SE ) ].PB( MP( it->FI , it->SE ) );
  }
}
void solve(){
  build_edge( 1 );
  DFS( find_p( 1 ) );
  for( int i = 1 ; i <= n ; i ++ ) nxt[ i ].clear();
  build_edge( 0 );
  DFS2( find_p( 1 ) );
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d %d %d %d\n" , ans[ i ].FI.FI , ans[ i ].FI.SE ,
                              ans[ i ].SE.FI , ans[ i ].SE.SE );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
#define N 101010
inline Pt operator-( const Pt& p1 , const Pt& p2 ){
  return MP( p1.X - p2.X , p1.Y - p2.Y );
}
inline LD operator%( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
inline LD norm( const Pt& tp ){
  return sqrtl( tp % tp );
}
inline void scan( Pt& tp ){
  tp.X = getint();
  tp.Y = getint();
}
Pt a , b , t , x[ N ];
LD at , bt;
int n;
void build(){
  scan( a );
  scan( b );
  scan( t );
  at = norm( a - t );
  bt = norm( b - t );
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    scan( x[ i ] );
}
inline LD cal(){
  LD tans = norm( a - t ) , dlt = 0;
  for( int i = 0 ; i < n ; i ++ ){
    tans += 2.0 * norm( x[ i ] - t );
    dlt = min( dlt , norm( x[ i ] - a ) - norm( x[ i ] - t ) - at );
  }
  tans += dlt;
  return tans;
}
LD ldp[ N ][ 2 ] , rdp[ N ][ 2 ] , td[ N ];
inline LD cal2(){
  LD tans = norm( a - t ) + norm( b - t ) , dlt = 0.0;
  for( int i = 0 ; i < n ; i ++ ){
    td[ i ] = norm( x[ i ] - t );
    tans += 2.0 * td[ i ];
  }
  for( int i = 0 ; i < n ; i ++ ){
    ldp[ i ][ 0 ] = norm( x[ i ] - a ) - td[ i ] - at;
    if( i ) ldp[ i ][ 0 ] = min( ldp[ i ][ 0 ] , ldp[ i - 1 ][ 0 ] );
    ldp[ i ][ 1 ] = norm( x[ i ] - b ) - td[ i ] - bt;
    if( i ) ldp[ i ][ 1 ] = min( ldp[ i ][ 1 ] , ldp[ i - 1 ][ 1 ] );
  }
  for( int i = n - 1 ; i >= 0 ; i -- ){
    rdp[ i ][ 0 ] = norm( x[ i ] - a ) - td[ i ] - at;
    if( i < n - 1 ) rdp[ i ][ 0 ] = min( rdp[ i ][ 0 ] , rdp[ i + 1 ][ 0 ] );
    rdp[ i ][ 1 ] = norm( x[ i ] - b ) - td[ i ] - bt;
    if( i < n - 1 ) rdp[ i ][ 1 ] = min( rdp[ i ][ 1 ] , rdp[ i + 1 ][ 1 ] );
  }
  for( int i = 0 ; i + 1 < n ; i ++ ){
    dlt = min( dlt , ldp[ i ][ 0 ] + rdp[ i + 1 ][ 1 ] );
    dlt = min( dlt , ldp[ i ][ 1 ] + rdp[ i + 1 ][ 0 ] );
  }
  tans += dlt;
  return tans;
}
void init(){
  LD ans = cal();
  swap( a , b );
  swap( at , bt );
  ans = min( ans , cal() );
  ans = min( ans , cal2() );
  printf( "%.12f\n" , (D)ans );
}
void solve(){

}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
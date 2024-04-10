// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<LD,LD> Pt;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
// #define X FI
// #define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-13
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
int __ = 1 , cs;
/*********default*********/
#define N 111111
typedef tuple<D,D,D> PT;
#define X(O) get<0>(O)
#define Y(O) get<1>(O)
#define Z(O) get<2>(O)
vector<PT> v;
D sqr( const D& x ){ return x * x; }
D dist( const PT& p1 , const PT& p2 ){
  return sqrt( sqr( X( p1 ) - X( p2 ) ) +
               sqr( Y( p1 ) - Y( p2 ) ) +
               sqr( Z( p1 ) - Z( p2 ) ) );
}
PT operator+( const PT& p1 , const PT& p2 ){
  return MT( X( p1 ) + X( p2 ) ,
             Y( p1 ) + Y( p2 ) ,
             Z( p1 ) + Z( p2 ) );
}
PT operator-( const PT& p1 , const PT& p2 ){
  return MT( X( p1 ) - X( p2 ) ,
             Y( p1 ) - Y( p2 ) ,
             Z( p1 ) - Z( p2 ) );
}
PT operator*( const PT& p1 , const D& tk ){
  return MT( X( p1 ) * tk ,
             Y( p1 ) * tk ,
             Z( p1 ) * tk );
}
void scan( PT& tp ){
  D tx , ty , tz;
  scanf( "%lf%lf%lf" , &tx , &ty , &tz );
  tp = MT( tx , ty , tz );
}
void build(){

}
int n;
PT p[ N ] , s;
D vp , vs , sum;
void init(){
  n = getint() + 1;
  for( int i = 0 ; i < n ; i ++ ){
    scan( p[ i ] );
    if( i ) sum += dist( p[ i - 1 ] , p[ i ] );
  }
  scanf( "%lf%lf" , &vp , &vs );
  scan( s );
}
PT ans;
bool okay( D mid ){
  PT pos = p[ 0 ]; D elp = 0.0;
  for( int i = 1 ; i < n ; i ++ ){
    D tdist = dist( p[ i - 1 ] , p[ i ] );
    D tt = tdist / vs;
    if( elp + tt > mid ){
      D lft = mid - elp;
      pos = pos + ( p[ i ] - p[ i - 1 ] ) * ( lft / tt );
      break;
    }else{
      elp += tt;
      pos = p[ i ];
    }
  }
  D dlt = dist( s , pos );
  D ttt = dlt / vp;
  if( ttt > mid && !equal( ttt , mid ) ) return false;
  ans = pos;
  return true;
}
void solve(){
  D l = 0.0 , r = sum / vs + eps , mid; bool good = false;
  for( int i = 0 ; i < 200 ; i ++ ){
    mid = ( l + r ) * 0.5;
    if( okay( mid ) ) r = mid , good = true;
    else l = mid;
  }
  if( !good ) puts( "NO" );
  else{
    puts( "YES" );
    printf( "%.12f\n" , l );
    printf( "%.12f %.12f %.12f\n" , X( ans ) , Y( ans ) , Z( ans ) );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
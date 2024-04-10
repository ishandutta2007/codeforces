// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
inline bool equal( LD _x ,  LD _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
inline LD getLD(){
  D _; scanf( "%lf" , &_ );
  return _;
}
typedef tuple<LD,LD,LD> Pt;
#define X(U) get<0>(U)
#define Y(U) get<1>(U)
#define Z(U) get<2>(U)
inline void scan( Pt& tp ){
  X( tp ) = getLD();
  Y( tp ) = getLD();
  Z( tp ) = getLD();
}
inline void print( const Pt& tp ){
  printf( "(%.6f,%.6f,%.6f)\n" , (D)X( tp ) , (D)Y( tp ) , (D)Z( tp ) );
}
inline bool onbase( const Pt& tp ){
  return equal( Z( tp ) , 0.0 );
}
inline LD sqr( const LD& x ){ return x * x; }
LD r , h , ans , rr;
Pt p[ 2 ];
const LD pi = acosl( -1.0 );
const LD pi2 = 2.0 * acosl( -1.0 );
void build(){
}
void init(){
  r = getLD();
  h = getLD();
  rr = sqrtl( sqr( r ) + sqr( h ) );
  scan( p[ 0 ] );
  scan( p[ 1 ] );
}
inline LD dist( const Pt& x , const Pt&y ){
  return sqrtl( sqr( X( x ) - X( y ) ) +
                sqr( Y( x ) - Y( y ) ) +
                sqr( Z( x ) - Z( y ) ) );
}
inline LD dist_oncone( const Pt& x , const Pt& y ){
  LD ang1 = atan2( Y( x ) , X( x ) );
  LD ang2 = atan2( Y( y ) , X( y ) );
  LD dang = fabsl( ang1 - ang2 );
  dang *= r / rr;
  LD r1 = rr * ( 1.0 - Z( x ) / h );
  LD r2 = rr * ( 1.0 - Z( y ) / h );
  Pt p1 = MT( r1 , 0.0 , 0.0 );
  Pt p2 = MT( cosl( dang ) * r2 , sinl( dang ) * r2 , 0.0 );
  dang = r / rr * pi2 - dang;
  Pt p3 = MT( r1 , 0.0 , 0.0 );
  Pt p4 = MT( cosl( dang ) * r2 , sinl( dang ) * r2 , 0.0 );
  return min( dist( p1 , p2 ) , dist( p3 , p4 ) );
}
inline void cal1(){
  ans = min( ans , dist( p[ 0 ] , p[ 1 ] ) );
}
#define XX 10
#define KK 60
#define K 60
inline void cal2(){
  for( int y = 0 ; y < XX ; y ++ ){
    LD bans = 1e40 , bl = pi2 / XX * y , br = pi2 / XX * ( y + 1 ) , m1 , m2;
    for( int i = 0 ; i < K ; i ++ ){
      m1 = bl + ( br - bl ) / 3;
      m2 = br - ( br - bl ) / 3;
      Pt tmp1 = MT( cosl( m1 ) * r , sinl( m1 ) * r , 0.0 );
      Pt tmp2 = MT( cosl( m2 ) * r , sinl( m2 ) * r , 0.0 );
      LD tans1 = dist_oncone( p[ 1 ] , tmp1 ) + dist( tmp1 , p[ 0 ] );
      LD tans2 = dist_oncone( p[ 1 ] , tmp2 ) + dist( tmp2 , p[ 0 ] );
      if( tans1 < tans2 ){
        bans = min( bans , tans1 );
        br = m2;
      }else{
        bans = min( bans , tans2 );
        bl = m1;
      }
    }
    ans = min( ans , bans );
  }
}
inline LD cal4( const Pt& p1 , const Pt& p2 ){
  LD bbans = 1e40;
  for( int y = 0 ; y < XX ; y ++ ){
    LD bans = 1e40 , bl = pi2 / XX * y , br = pi2 / XX * ( y + 1 ) , m1 , m2;
    for( int i = 0 ; i < KK ; i ++ ){
      m1 = bl + ( br - bl ) / 3;
      m2 = br - ( br - bl ) / 3;
      Pt tmp1 = MT( cosl( m1 ) * r , sinl( m1 ) * r , 0.0 );
      Pt tmp2 = MT( cosl( m2 ) * r , sinl( m2 ) * r , 0.0 );
      LD tans1 = dist_oncone( p2 , tmp1 ) + dist( p1 , tmp1 );
      LD tans2 = dist_oncone( p2 , tmp2 ) + dist( p1 , tmp2 );
      if( tans1 < tans2 ){
        bans = min( bans , tans1 );
        br = m2;
      }else{
        bans = min( bans , tans2 );
        bl = m1;
      }
    }
    bbans = min( bbans , bans );
  }
  return bbans;
}
inline void cal3(){
  ans = min( ans , dist_oncone( p[ 0 ] , p[ 1 ] ) );
  for( int y = 0 ; y < XX ; y ++ ){
    LD bans = 1e40 , bl = pi2 / XX * y , br = pi2 / XX * ( y + 1 ) , m1 , m2;
    for( int i = 0 ; i < KK ; i ++ ){
      m1 = bl + ( br - bl ) / 3;
      m2 = br - ( br - bl ) / 3;
      Pt tmp1 = MT( cosl( m1 ) * r , sinl( m1 ) * r , 0.0 );
      Pt tmp2 = MT( cosl( m2 ) * r , sinl( m2 ) * r , 0.0 );
      LD tans1 = dist_oncone( p[ 0 ] , tmp1 ) + cal4( tmp1 , p[ 1 ] );
      LD tans2 = dist_oncone( p[ 0 ] , tmp2 ) + cal4( tmp2 , p[ 1 ] );
      if( tans1 < tans2 ){
        bans = min( bans , tans1 );
        br = m2;
      }else{
        bans = min( bans , tans2 );
        bl = m1;
      }
    }
    ans = min( ans , bans );
  }
}
void solve(){
  ans = 1e40;
  if( onbase( p[ 0 ] ) && onbase( p[ 1 ] ) ) cal1();
  else if( onbase( p[ 0 ] ) || onbase( p[ 1 ] ) ){
    if( onbase( p[ 1 ] ) ) swap( p[ 0 ] , p[ 1 ] );
    cal2();
  }else cal3();
  printf( "%.12f\n" , (D)ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
//typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
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
struct frac{
  LL p , q;
  frac( LL x , LL y = 1 ){
    p = x; q = y;
    reduce();
  }
  void reduce(){
    LL r = __gcd( abs( p ) , abs( q ) );
    p /= r; q /= r;
    if( q < 0 ) p = -p , q = -q;
  }
};
frac operator+( const frac& lhs , const frac& rhs ){
  frac ret( lhs.p * rhs.q + rhs.p * lhs.q ,
            lhs.q * rhs.q );
  return ret;
}
frac operator-( const frac& lhs , const frac& rhs ){
  frac ret( lhs.p * rhs.q - rhs.p * lhs.q ,
            lhs.q * rhs.q );
  return ret;
}
frac operator*( const frac& lhs , const frac& rhs ){
  frac ret( lhs.p * rhs.p , lhs.q * rhs.q );
  return ret;
}
frac operator/( const frac& lhs , const frac& rhs ){
  frac ret( lhs.p * rhs.q , lhs.q * rhs.p );
  return ret;
}
bool operator<( const frac& lhs , const frac& rhs ){
  return lhs.p * rhs.q < lhs.q * rhs.p;
}
bool operator==( const frac& lhs , const frac& rhs ){
  return lhs.p * rhs.q == lhs.q * rhs.p;
}
#define X first
#define Y second
typedef pair<LL,LL> Pt;
void scan( Pt& tp ){
  tp.X = getint();
  tp.Y = getint();
}
void build(){

}
#define N 101010
LL n;
Pt l , r;
Pt p[ N ] , v[ N ];
void init(){
  n = getint();
  scan( l );
  scan( r );
  for( int i = 0 ; i < n ; i ++ ){
    scan( p[ i ] );
    scan( v[ i ] );
  }
}
void no(){
  puts( "-1" );
  Bye;
}
inline pair<frac,frac> intv( LL bl , LL br , LL s , LL dir ){
  if( s <= bl and ( br - bl ) * dir <= 0 )
    no();
  if( s >= br and ( bl - br ) * dir <= 0 )
    no();
  if( bl < s and s < br ){
    if( dir == 0 ) return { frac( 0 ) , frac( -1 ) };
    if( dir > 0 )
      return { frac( 0 ) , frac( br - s , dir ) };
    return { frac( 0 ) , frac( s - bl , abs( dir ) ) };
  }
  if( s <= bl )
    return { frac( bl - s , abs( dir ) ) , frac( br - s , abs( dir ) ) };
  if( s >= br )
    return { frac( s - br , abs( dir ) ) , frac( s - bl , abs( dir ) ) };
  assert( false );
  return { frac( 1 ) , frac( 0 ) };
}
void upd( frac& lft , frac& rgt , frac ul , frac ur ){
  if( lft < ul ) lft = ul;
  if( not ( ur == frac( -1 ) ) and ( rgt == frac( -1 ) ) )
    rgt = ur;
  if( not ( ur == frac( -1 ) ) and ur < rgt ) rgt = ur;
  if( not ( rgt == frac( -1 ) ) and not ( lft < rgt ) ) no();
}
void solve(){
  frac lft( 0 ) , rgt( 0 );
  for( int i = 0 ; i < n ; i ++ ){
    {
      auto ret = intv( l.X , r.X , p[ i ].X , v[ i ].X );
      if( i == 0 ) tie( lft , rgt ) = ret;
      else upd( lft , rgt , ret.first , ret.second );
    }
    {
      auto ret = intv( l.Y , r.Y , p[ i ].Y , v[ i ].Y );
      upd( lft , rgt , ret.first , ret.second );
    }
  }
  printf( "%.12f\n" , (double)lft.p / lft.q );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
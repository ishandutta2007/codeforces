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
#define INF  1023456789LL
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
typedef double type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
#define O first
#define R second
Pt operator+( const Pt& p1 , const Pt& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
Pt operator*( const Pt& tp , const type& tk ){
  return { tp.X * tk , tp.Y * tk };
}
Pt operator/( const Pt& tp , const type& tk ){
  return { tp.X / tk , tp.Y / tk };
}
type operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
type operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
type norm2( const Pt& tp ){
  return tp * tp;
}
double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
void scan( Pt& tp ){
  scanf( "%lf%lf" , &tp.X , &tp.Y );
}
void print( Pt& tp , char cc = ' ' ){
  printf( "(%.6f, %.6f)%c" , tp.X , tp.Y , cc );
}
void build(){

}
Pt he , my , ori;
double hev , myv , r;
double her , heang;
void init(){
  ori = { 0 , 0 };
  scan( he );
  scanf( "%lf" , &hev );
  scan( my );
  scanf( "%lf" , &myv );
  scanf( "%lf" , &r );
  her = norm( he );
  heang = atan2( he.Y , he.X );
}
double loop , perloop;
const double pi = acos( -1.0 );
double mind( const Pt& p1 , const Pt& p2 , const Pt& p3 ){
  double tmp = ( p2 - p1 ) * ( p3 - p1 ) / norm2( p3 - p1 );
  if( -eps < tmp and tmp < 1. + eps )
    return fabs( ( p2 - p1 ) ^ ( p3 - p1 ) ) / norm( p3 - p1 );
  return min( norm( p2 - p1 ) , norm( p3 - p2 ) );
}
double normal( double ang ){
  while( ang < eps     ) ang += pi + pi;
  while( ang > pi + pi ) ang -= pi + pi;
  return ang;
}
double cdist( double ang1 , double ang2 ){
  ang1 = normal( ang1 );
  ang2 = normal( ang2 );
  if( ang1 > ang2 ) swap( ang1 , ang2 );
  return min( (ang2 - ang1) * r ,
              (ang1 - ang2 + pi + pi) * r );
}
double dist( const Pt& tar ){
  if( mind( my , ori , tar ) > r ) return norm( my - tar );
  double ang1 = asin( r / norm( my ) );
  double ang2 = asin( r / norm( tar ) );
  double bs1 = atan2( my.Y , my.X );
  double bs2 = atan2( tar.Y , tar.X );
  double bst = 1e9;
  for( int bns = -1 ; bns <= 1 ; bns += 2 )
    for( int bns2 = -1 ; bns2 <= 1 ; bns2 += 2 ){
      bst = min( bst , 
                 fabs( cos( ang1 ) * norm( my ) ) +
                 fabs( cos( ang2 ) * norm( tar ) ) +
                 cdist( bs1 + bns * ( pi / 2 - ang1 ) ,
                        bs2 + bns2 * ( pi / 2 - ang2 ) ) );
    }
  return bst;
}
double okay( double tt ){
  double ang = tt * 2 * pi / perloop;
  double cur = heang + ang;
  Pt at = { cos( cur ) * her , sin( cur ) * her };
  double d = dist( at );
  //print( at , ' ' );
  //printf( "d = %.6f, myv = %.6f, d/myv = %.6f , ot = %.6f\n" ,
          //d , myv , d / myv , ot );
  return d / myv < tt;
}
void solve(){
  loop = 2 * pi * her;
  perloop = loop / hev;
  double bl = 0 , br = 1e9;
  for( int i = 0 ; i < 60 ; i ++ ){
    double bmid = (bl + br) * 0.5;
    if( okay( bmid ) ) br = bmid;
    else bl = bmid;
  }
  printf( "%.12f\n" , (bl + br) * 0.5 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
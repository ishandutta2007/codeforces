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
Pt rotate( const Pt& tp , const double& ang ){
  return { tp.X * cos( ang ) - tp.Y * sin( ang ) ,
           tp.X * sin( ang ) + tp.Y * cos( ang ) };
}
void print( const Pt& tp ){
  printf( "(%.6f, %.6f)\n" , tp.X , tp.Y );
}
const double pi = acos( -1 );
double dd;
Pt bs[ 5 ];
void build(){
  dd = sqrt( 100. + 100. - 2. * 100. * cos( 108. / 180. * pi ) );
  bs[ 4 ] = { -dd , 0 };
  bs[ 0 ] = rotate( bs[ 4 ] * -1 , -36. / 180. * pi );
  bs[ 1 ] = rotate( bs[ 0 ] * -1 , -36. / 180. * pi );
  bs[ 2 ] = rotate( bs[ 1 ] * -1 , -36. / 180. * pi );
  bs[ 3 ] = rotate( bs[ 2 ] * -1 , -36. / 180. * pi );
}
int n;
void init(){
  n = getint();
}
vector<Pt> wt;
void solve(){
  Pt st = {0, 0};
  wt.push_back( st );
  vector<int> fans = { 0 };
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < 4 ; j ++ ){
      st = st + bs[ j ];
      fans.push_back( wt.size() );
      wt.push_back( st );
    }
  printf( "%d\n" , (int)wt.size() );
  for( auto p : wt )
    printf( "%.12f %.12f\n" , p.X , p.Y );
  for( int i = 0 ; i < n ; i ++ ){
    int aa = i * 4 + 1;
    printf( "%d %d %d %d %d\n" , aa , aa + 2 , aa + 4 , aa + 1 , aa + 3 );
  }
  int lst = wt.size() - 1;
  while( lst ){
    fans.push_back( lst - 4 );
    lst -= 4;
  }
  for( auto i : fans )
    printf( "%d " , i + 1 );
  puts( "" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
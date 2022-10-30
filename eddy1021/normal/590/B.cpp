// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
typedef pair<D,D> PDD;
#define X FI
#define Y SE
PDD operator+( const PDD& p1 , const PDD& p2 ){
  return MP( p1.X + p2.X , p1.Y + p2.Y );
}
PDD operator-( const PDD& p1 , const PDD& p2 ){
  return MP( p1.X - p2.X , p1.Y - p2.Y );
}
PDD operator*( const PDD& tp , const D& tk ){
  return MP( tp.X * tk  , tp.Y * tk );
}
PDD operator/( const PDD& tp , const D& tk ){
  return MP( tp.X / tk  , tp.Y / tk );
}
D operator%( const PDD& p1 , const PDD& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
int vmax , t;
PDD s1 , s2 , v , w;
void build(){

}
void init(){
  s1.X = getint();
  s1.Y = getint();
  s2.X = getint();
  s2.Y = getint();
  vmax = getint();
  t = getint();
  v.X = getint();
  v.Y = getint();
  w.X = getint();
  w.Y = getint();
}
bool good( D x ){
  PDD npos = s1;
  npos = npos + v * min( x , (D)t );
  if( x > t ) npos = npos + w * ( x - t );
  D dist = sqrt( ( s2 - npos ) % ( s2 - npos ) );
  return ( dist / x ) < (D)vmax;
}
void solve(){
  D l = 0.0 , r = 1e10 , mid;
  for( int i = 0 ; i < 10000 ; i ++ ){
    mid = ( l + r ) * 0.5;
    if( good( mid ) ) r = mid;
    else l = mid;
  }
  printf( "%.12f\n" , ( l + r ) * 0.5 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
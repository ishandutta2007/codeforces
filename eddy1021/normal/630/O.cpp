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
void build(){

}
inline void Scan( Pt& tp ){
  tp.X = getint();
  tp.Y = getint();
}
inline Pt operator+( const Pt& p1 , const Pt& p2 ){
  return MP( p1.X + p2.X , p1.Y + p2.Y );
}
inline Pt operator*( const Pt& tp , const LD& tk ){
  return MP( tp.X * tk , tp.Y * tk );
}
inline LD operator%( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
inline LD norm( const Pt& tp ){
  return sqrt( tp % tp );
}
Pt p , v;
LD a , b , c , d;
void init(){
  Scan( p );
  Scan( v );
  a = getint();
  b = getint();
  c = getint();
  d = getint();
}
Pt v2 , v3 , v4;
Pt rotate( const Pt& tp ){
  Pt tv;
  tv = tp; swap( tv.X , tv.Y ); tv.X = -tv.X;
  return tv;
}
vector<Pt> ans;
void solve(){
  v2 = rotate( v );
  v3 = rotate( v2 );
  v4 = rotate( v3 );
  ans.PB( p + v * ( b / norm( v ) ) );
  ans.PB( p + v2 * ( a * 0.5 / norm( v2 ) ) );
  ans.PB( p + v2 * ( c * 0.5 / norm( v2 ) ) );
  ans.PB( ans.back() + v3 * ( d / norm( v3 ) ) );
  ans.PB( ans.back() + v4 * ( c / norm( v4 ) ) );
  ans.PB( ans.back() + v * ( d / norm( v ) ) );
  ans.PB( p + v4 * ( a * 0.5 / norm( v4 ) ) );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%.12f %.12f\n" , (D)ans[ i ].X , (D)ans[ i ].Y );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
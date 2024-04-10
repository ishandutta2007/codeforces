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
void Print( const Pt& tp ){
  printf( "%.6f %.6f\n" , (D)tp.X , (D)tp.Y );
}
inline Pt operator+( const Pt& p1 , const Pt& p2 ){
  return MP( p1.X + p2.X , p1.Y + p2.Y );
}
inline Pt operator-( const Pt& p1 , const Pt& p2 ){
  return MP( p1.X - p2.X , p1.Y - p2.Y );
}
inline Pt operator*( const LD& tk , const Pt& tp ){
  return MP( tk * tp.X , tk * tp.Y );
}
inline LD operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
Pt inter( Pt p1, Pt p2, Pt q1, Pt q2){
	LD f1 = (p2 - p1) ^ (q1 - p1); // cross
	LD f2 = (p2 - p1) ^ (p1 - q2); // cross
	LD f = (f1 + f2);
	return (f2 / f) * q1 + (f1 / f) * q2;
}
ll n;
LD r;
Pt p1 , p2 , p3 , p4;
const LD PI = acosl( -1.0 );
void init(){
  n = getint();
  r = getint();
  p1 = MP( cosl( ( (LD)( n / 2 ) / (LD)n ) * 2.0 * PI ) ,
           sinl( ( (LD)( n / 2 ) / (LD)n ) * 2.0 * PI ) );
  p2 = MP( cosl( ( (LD)( n / 2 + 1 ) / (LD)n ) * 2.0 * PI ) ,
           sinl( ( (LD)( n / 2 + 1 ) / (LD)n ) * 2.0 * PI ) );
  p3 = MP( cosl( ( (LD)( n - 1 ) / (LD)n ) * 2.0 * PI ) ,
           sinl( ( (LD)( n - 1 ) / (LD)n ) * 2.0 * PI ) );
  p4 = MP( cosl( ( 1.0 / (LD)n ) * 2.0 * PI ) ,
           sinl( ( 1.0 / (LD)n ) * 2.0 * PI ) );
  // Print( p1 );
  // Print( p2 );
  // Print( p3 );
  // Print( p4 );
}
void solve(){
  Pt mid = inter( p1 , p3 , p2 , p4 );
  // Print( mid );
  LD area = ( p1 ^ mid ) + ( mid ^ p2 );
  area *= (LD)n * r * r * 0.5;
  if( area < 0 ) area = -area;
  printf( "%.12f\n" , (D)area );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
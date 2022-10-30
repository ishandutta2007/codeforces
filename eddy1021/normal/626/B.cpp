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
#define N 222
int n;
char c[ N ];
inline int trans( char ctmp ){
  if( ctmp == 'B' ) return 0;
  if( ctmp == 'G' ) return 1;
  if( ctmp == 'R' ) return 2;
  return -1;
}
int cnt[ N ] , len;
void init(){
  n = getint();
  scanf( "%s" , c );
  len = strlen( c );
  for( int i = 0 ; i < len ; i ++ )
    cnt[ trans( c[ i ] ) ] ++;
}
char aa[9]="BGR";
bool got[ N + 2 ][ N + 2 ][ N + 2 ];
void solve(){
  got[ cnt[ 0 ] ][ cnt[ 1 ] ][ cnt[ 2 ] ] = true;
  for( int _ = N + N ; _ >= 0 ; _ -- )
    for( int i = min( N , _ ) ; i >= 0 ; i -- )
      for( int j = min( N , _ - i ) ; j >= 0 ; j -- ){
        int k = _ - i - j;
        if( k < 0 || k >= N ) continue;
        if( !got[ i ][ j ][ k ] ) continue;
        if( i && j ) got[ i - 1 ][ j - 1 ][ k + 1 ] = true;
        if( i && k ) got[ i - 1 ][ j + 1 ][ k - 1 ] = true;
        if( j && k ) got[ i + 1 ][ j - 1 ][ k - 1 ] = true;
        if( i > 1 ) got[ i - 1 ][ j ][ k ] = true;
        if( j > 1 ) got[ i ][ j - 1 ][ k ] = true;
        if( k > 1 ) got[ i ][ j ][ k - 1 ] = true;
      }
  if( got[ 1 ][ 0 ][ 0 ] ) putchar( 'B' );
  if( got[ 0 ][ 1 ][ 0 ] ) putchar( 'G' );
  if( got[ 0 ][ 0 ][ 1 ] ) putchar( 'R' );
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
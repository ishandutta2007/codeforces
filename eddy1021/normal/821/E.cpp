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
#define N 20
struct Mat{
  int n , a[ N ][ N ];
  Mat( int _n ) : n( _n ){
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        a[ i ][ j ] = 0;
  }
  Mat operator*( const Mat& he ) const{
    Mat ret( n );
    for( int k = 0 ; k < n ; k ++ )
      for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < n ; j ++ )
          ret.a[ i ][ j ] = add( ret.a[ i ][ j ] ,
                                 mul( a[ i ][ k ] , he.a[ k ][ j ] ) );
    return ret;
  }
  Mat operator^( LL tk ) const{
    Mat ret( n ) , aa( n );
    for( int i = 0 ; i < n ; i ++ ){
      ret.a[ i ][ i ] = 1;
      for( int j = 0 ; j < n ; j ++ )
        aa.a[ i ][ j ] = a[ i ][ j ];
    }
    while( tk ){
      if( tk & 1LL ) ret = ret * aa;
      aa = aa * aa; tk >>= 1;
    }
    return ret;
  }
  void print(){
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        printf( "%d%c" , a[ i ][ j ] , " \n"[ j + 1 == n ] );
  }
};
void build(){

}
int n;
LL k;
void init(){
  n = getint();
  k = getint();
}
Mat Bound( int ci ){
  Mat ret( 16 );
  for( int i = 0 ; i <= ci ; i ++ )
    for( int j = max( 0 , i - 1 ) ; j <= min( 15 , i + 1 ) ; j ++ )
      ret.a[ i ][ j ] = 1;
  return ret;
}
void solve(){
  int bdr = 15;
  Mat ret( 16 );
  for( int i = 0 ; i <= 15 ; i ++ )
    ret.a[ i ][ i ] = 1;
  for( int i = 0 ; i < n ; i ++ ){
    LL ai = getint();
    if( ai == 0 ) ai ++;
    LL bi = getint();
    if( bi >= k ) bi = k;
    int ci = getint();
    ret = Bound( min( ci , bdr ) ) * ret;
    LL tmp = bi - ai - 1;
    if( bi >= k ) tmp ++;
    //cout << tmp << endl;
    if( tmp > 0 ){
      Mat mm = Bound( ci );
      ret = ( mm ^ tmp ) * ret;
    }
    if( bi >= k ) break;
    bdr = ci;
    //for( int j = 0 ; j <= 15 ; j ++ )
      //printf( "%d%c" , ret.a[ j ][ 0 ] , " \n"[ j == 15 ] );
  }
  printf( "%d\n" , ret.a[ 0 ][ 0 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
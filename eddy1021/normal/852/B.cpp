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
#define N 101
struct Mat{
  int n , a[ N ][ N ];
  Mat( int _n ){
    n = _n;
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        a[ i ][ j ] = 0;
  }
  Mat operator*( const Mat& he ) const{
    Mat ret( n );
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        for( int k = 0 ; k < n ; k ++ )
          ret.a[ i ][ j ] = add( ret.a[ i ][ j ] ,
                                 mul( a[ i ][ k ] , he.a[ k ][ j ] ) );
    return ret;
  }
  Mat operator^( int tms ) const{
    Mat ret( n ) , tmp( n );
    for( int i = 0 ; i < n ; i ++ ){
      ret.a[ i ][ i ] = 1;
      for( int j = 0 ; j < n ; j ++ )
        tmp.a[ i ][ j ] = a[ i ][ j ];
    }
    while( tms > 0 ){
      if( tms & 1 ) ret = ret * tmp;
      tmp = tmp * tmp;
      tms >>= 1;
    }
    return ret;
  }
};
void build(){

}
#define X 1010101
int n , l , m , s[ X ] , u[ X ] , o[ X ];
void init(){
  n = getint();
  l = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ )
    s[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    u[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    o[ i ] = getint();
}
int cnt[ 111 ] , sc[ 111 ] , oc[ 111 ][ 111 ];
void solve(){
  Mat tmp( m );
  for( int i = 0 ; i < n ; i ++ )
    cnt[ u[ i ] % m ] ++;
  for( int i = 0 ; i < m ; i ++ )
    for( int j = 0 ; j < m ; j ++ ){
      int dlt = ( i - j + m ) % m;
      tmp.a[ i ][ j ] = cnt[ dlt ];
    }
  for( int i = 0 ; i < n ; i ++ )
    sc[ s[ i ] % m ] ++;
  for( int i = 0 ; i < n ; i ++ )
    oc[ u[ i ] % m ][ o[ i ] % m ] ++;
  tmp = tmp ^ ( l - 2 );
  int ans = 0;
  for( int i = 0 ; i < m ; i ++ ) if( sc[ i ] )
    for( int j = 0 ; j < m ; j ++ )
      for( int k = 0 ; k < m ; k ++ ){
        if( oc[ j ][ k ] == 0 ) continue;
        int tar = ( m - ( i + j + k ) % m ) % m;
        ans = add( ans ,
                   mul( sc[ i ] , mul( oc[ j ][ k ] , tmp.a[ tar ][ 0 ] ) ) );
      }
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
#define N 1021
void build(){

}
int h , w , k;
char r[ N ][ N ] , c[ N ][ N ];
bool right( int i , int j ){
  return r[ i ][ j ] == 'E';
}
bool down( int i , int j ){
  return c[ i ][ j ] == 'E';
}
int tot;
void init(){
  h = getint();
  w = getint();
  k = getint();
  tot = h * ( w - 1 ) + w * ( h - 1 );
  for( int i = 0 ; i < h + h - 1 ; i ++ )
    if( i % 2 ) // column
      scanf( "%s" , c[ i / 2 ] );
    else // row
      scanf( "%s" , r[ i / 2 ] );
}
int ans[ N ][ N ];
void print(){
  int ok = 0;
  for( int i = 0 ; i < h ; i ++ )
    for( int j = 0 ; j < w ; j ++ ){
      if( i + 1 < h and ( ans[ i ][ j ] == ans[ i + 1 ][ j ] ) == down( i , j ) )
        ok ++;
      if( j + 1 < w and ( ans[ i ][ j ] == ans[ i ][ j + 1 ] ) == right( i , j ) )
        ok ++;
    }
  if( 4 * ok < 3 * tot )
    return;
  puts( "YES" );
  for( int i = 0 ; i < h ; i ++ )
    for( int j = 0 ; j < w ; j ++ )
      printf( "%d%c" , ans[ i ][ j ] + 1 , " \n"[ j + 1 == w ] );
  exit(0);
}
void solve(){
  if( k == 1 ){
    print();
    puts( "NO" );
    exit(0);
  }
  { // fix all row
    for( int i = 0 ; i < h ; i ++ ){
      for( int j = 1 ; j < w ; j ++ ){
        if( right( i , j - 1 ) )
          ans[ i ][ j ] = ans[ i ][ j - 1 ];
        else
          ans[ i ][ j ] = 1 - ans[ i ][ j - 1 ];
      }
      if( !i ) continue;
      int ok = 0;
      for( int j = 0 ; j < w ; j ++ )
        if( down( i - 1 , j ) == ( ans[ i - 1 ][ j ] == ans[ i ][ j ] ) )
          ok ++;
      if( w - ok > ok )
        for( int j = 0 ; j < w ; j ++ )
          ans[ i ][ j ] = 1 - ans[ i ][ j ];
    }
    print();
  }
  { // fix all col
    for( int j = 0 ; j < w ; j ++ ){
      for( int i = 1 ; i < h ; i ++ ){
        if( down( i - 1 , j ) )
          ans[ i ][ j ] = ans[ i - 1 ][ j ];
        else
          ans[ i ][ j ] = 1 - ans[ i - 1 ][ j ];
      }
      if( !j ) continue;
      int ok = 0;
      for( int i = 0 ; i < h ; i ++ )
        if( right( i , j - 1 ) == ( ans[ i ][ j - 1 ] == ans[ i ][ j ] ) )
          ok ++;
      if( h - ok > ok )
        for( int i = 0 ; i < h ; i ++ )
          ans[ i ][ j ] = 1 - ans[ i ][ j ];
    }
    print();
  }
  puts( "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
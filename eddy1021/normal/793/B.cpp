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
int n , m;
char c[ N ][ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%s" , c[ i ] );
}
bool t[ N ][ N ] , s[ N ][ N ];
int nt , mt; 
int ns , ms; 
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ ){
      if( c[ i ][ j ] == 'S' )
        ns = i , ms = j;
      if( c[ i ][ j ] == 'T' )
        nt = i , mt = j;
    }
  for( int i = nt ; i < n ; i ++ ){
    if( c[ i ][ mt ] == '*' ) break;
    t[ i ][ mt ] = true;
  }
  for( int i = nt ; i >= 0 ; i -- ){
    if( c[ i ][ mt ] == '*' ) break;
    t[ i ][ mt ] = true;
  }
  for( int j = mt ; j < m ; j ++ ){
    if( c[ nt ][ j ] == '*' ) break;
    t[ nt ][ j ] = true;
  }
  for( int j = mt ; j >= 0 ; j -- ){
    if( c[ nt ][ j ] == '*' ) break;
    t[ nt ][ j ] = true;
  }
  for( int i = ns ; i < n ; i ++ ){
    if( c[ i ][ ms ] == '*' ) break;
    s[ i ][ ms ] = true;
  }
  for( int i = ns ; i >= 0 ; i -- ){
    if( c[ i ][ ms ] == '*' ) break;
    s[ i ][ ms ] = true;
  }
  for( int j = ms ; j < m ; j ++ ){
    if( c[ ns ][ j ] == '*' ) break;
    s[ ns ][ j ] = true;
  }
  for( int j = ms ; j >= 0 ; j -- ){
    if( c[ ns ][ j ] == '*' ) break;
    s[ ns ][ j ] = true;
  }
  //for( int i = 0 ; i < n ; i ++ , puts( "" ) )
    //for( int j = 0 ; j < m ; j ++ )
      //printf( "%d" , s[ i ][ j ] );
  //for( int i = 0 ; i < n ; i ++ , puts( "" ) )
    //for( int j = 0 ; j < m ; j ++ )
      //printf( "%d" , t[ i ][ j ] );
  for( int i = 0 ; i < n ; i ++ ){
    bool gots = false , gott = false;
    for( int j = 0 ; j < m ; j ++ ){
      if( c[ i ][ j ] == '*' )
        gots = gott = false;
      if( s[ i ][ j ] )
        gots = true;
      if( t[ i ][ j ] )
        gott = true;
      if( gots and gott ){
        puts( "YES" );
        exit( 0 );
      }
    }
  }
  for( int j = 0 ; j < m ; j ++ ){
    bool gots = false , gott = false;
    for( int i = 0 ; i < n ; i ++ ){
      if( c[ i ][ j ] == '*' )
        gots = gott = false;
      if( s[ i ][ j ] )
        gots = true;
      if( t[ i ][ j ] )
        gott = true;
      if( gots and gott ){
        puts( "YES" );
        exit( 0 );
      }
    }
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
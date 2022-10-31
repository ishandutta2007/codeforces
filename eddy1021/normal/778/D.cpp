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
#define N 55
void build(){

}
int n , m;
char c[ 2 ][ N ][ N ] , t[ N ][ N ];
bool rev;
inline char chg( char ctmp ){
  if( ctmp == 'U' ) return 'L';
  if( ctmp == 'D' ) return 'R';
  if( ctmp == 'L' ) return 'U';
  if( ctmp == 'R' ) return 'D';
  assert( false );
  return 0;
}
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      scanf( "%s" , c[ i ][ j ] + 1 );
  if( n & 1 ){
    for( int i = 0 ; i < 2 ; i ++ ){
      for( int j = 1 ; j <= n ; j ++ )
        for( int k = 1 ; k <= m ; k ++ )
          t[ k ][ j ] = chg( c[ i ][ j ][ k ] );
      for( int j = 1 ; j <= m ; j ++ )
        for( int k = 1 ; k <= n ; k ++ )
          c[ i ][ j ][ k ] = t[ j ][ k ];
    }
    swap( n , m );
    rev = true;
  }
}
vector< pair<int,int> > op;
void turn( int iid , int id , int i , int j ){
  if( id == 0 ){
    if( c[ iid ][ i + 1 ][ j ] != 'L' )
      turn( iid , 1 , i + 1 , j );
    op.push_back( { i , j } );
    c[ iid ][ i ][ j ] = 'U';
    c[ iid ][ i ][ j + 1 ] = 'U';
    c[ iid ][ i + 1 ][ j ] = 'D';
    c[ iid ][ i + 1 ][ j + 1 ] = 'D';
  }else{
    if( c[ iid ][ i ][ j + 1 ] != 'U' )
      turn( iid , 0 , i , j + 1 );
    op.push_back( { i , j } );
    c[ iid ][ i ][ j ] = 'L';
    c[ iid ][ i ][ j + 1 ] = 'R';
    c[ iid ][ i + 1 ][ j ] = 'L';
    c[ iid ][ i + 1 ][ j + 1 ] = 'R';
  }
}
void Reset( int id ){
  for( int i = 1 ; i <= n ; i += 2 )
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ id ][ i ][ j ] != 'U' )
        turn( id , 0 , i , j );
}
void solve(){
  Reset( 0 );
  vector< pair<int,int> > top = op;
  op.clear();
  Reset( 1 );
  reverse( op.begin() , op.end() );
  for( auto i : op )
    top.push_back( i );
  op = top;
  printf( "%d\n" , (int)op.size() );
  for( auto i : op )
    if( rev )
      printf( "%d %d\n" , i.second , i.first );
    else
      printf( "%d %d\n" , i.first , i.second );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
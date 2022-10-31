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
#define N 5050
#define X 1021
void build(){

}
bool kd[ N ][ X ][ 2 ];
int n , m;
map<string,int> M;
char c[ X * 10 ];
inline int Op( const string& ss ){
  if( ss == "AND" ) return 0;
  if( ss == "OR" ) return 1;
  if( ss == "XOR" ) return 2;
  assert( false );
  return -1;
}
inline void AND( int id , int lop , int rop ){
  for( int i = 0 ; i < m ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ )
      kd[ id ][ i ][ j ] = kd[ lop ][ i ][ j ] and kd[ rop ][ i ][ j ];
}
inline void OR( int id , int lop , int rop ){
  for( int i = 0 ; i < m ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ )
      kd[ id ][ i ][ j ] = kd[ lop ][ i ][ j ] or kd[ rop ][ i ][ j ];
}
inline void XOR( int id , int lop , int rop ){
  for( int i = 0 ; i < m ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ )
      kd[ id ][ i ][ j ] = kd[ lop ][ i ][ j ] xor kd[ rop ][ i ][ j ];
}
void parse( int id ){
  fgets( c , X * 10 , stdin );
  int ptr = 0;
  while( c[ ptr ] != ':' ) ptr ++;
  string var = "";
  for( int i = 0 ; i < ptr - 1 ; i ++ )
    var += c[ i ];
  M[ var ] = id;
  vector<string> tokens;
  string token = "";
  int len = strlen( c );
  for( int i = ptr + 3 ; i < len ; i ++ )
    if( i + 1 == len or c[ i ] == ' ' ){
      tokens.push_back( token );
      token = "";
    }else
      token += c[ i ];
  if( tokens.size() == 1u ){
    for( int i = 0 ; i < m ; i ++ )
      kd[ id ][ i ][ 0 ] =
      kd[ id ][ i ][ 1 ] = tokens[ 0 ][ i ] - '0';
  }else if( tokens.size() == 3u ){
    int op = Op( tokens[ 1 ] );
    if( op == 0 )
      AND( id , M[ tokens[ 0 ] ] , M[ tokens[ 2 ] ] );
    else if( op == 1 )
      OR( id , M[ tokens[ 0 ] ] , M[ tokens[ 2 ] ] );
    else if( op == 2 )
      XOR( id , M[ tokens[ 0 ] ] , M[ tokens[ 2 ] ] );
    else 
      assert( false );
  }else assert( false );
}
void init(){
  scanf( "%d%d" , &n , &m );
  fgets( c , X * 10 , stdin );
  M[ "?" ] = 0;
  for( int i = 0 ; i < m ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ )
      kd[ 0 ][ i ][ j ] = j;
  for( int i = 1 ; i <= n ; i ++ )
    parse( i );
}
bool ans[ X ];
void solve(){
  {
    for( int i = 0 ; i < m ; i ++ ){
      int cnt[ 2 ] = {};
      for( int j = 1 ; j <= n ; j ++ )
        for( int k = 0 ; k < 2 ; k ++ )
          if( kd[ j ][ i ][ k ] )
            cnt[ k ] ++;
      if( cnt[ 0 ] <= cnt[ 1 ] )
        ans[ i ] = false;
      else
        ans[ i ] = true;
    }
    for( int i = 0 ; i < m ; i ++ )
      printf( "%c" , "01"[ ans[ i ] ] );
    puts( "" );
  }
  {
    for( int i = 0 ; i < m ; i ++ ){
      int cnt[ 2 ] = {};
      for( int j = 1 ; j <= n ; j ++ )
        for( int k = 0 ; k < 2 ; k ++ )
          if( kd[ j ][ i ][ k ] )
            cnt[ k ] ++;
      if( cnt[ 0 ] >= cnt[ 1 ] )
        ans[ i ] = false;
      else
        ans[ i ] = true;
    }
    for( int i = 0 ; i < m ; i ++ )
      printf( "%c" , "01"[ ans[ i ] ] );
    puts( "" );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
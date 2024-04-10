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
char c[ 9 ][ 9 ];
void build(){

}
void init(){
  for( int i = 0 ; i < 4 ; i ++ )
    scanf( "%s" , c[ i ] );
}
bool okay(){
  for( int i = 0 ; i < 2 ; i ++ )
    if( c[ 0 ][ i ] != c[ 2 ][ i ] ||
        c[ 1 ][ i ] != c[ 3 ][ i ]  )
      return false;
  return true;
}
void rotate(){
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ )
      if( c[ i ][ j ] == 'X' ){
        if( i == 0 && j == 0 ){
          swap( c[ i ][ j ] , c[ i + 1 ][ j ] );
        }else if( i == 0 ){
          swap( c[ i ][ j ] , c[ i ][ j - 1 ] );
        }else if( j == 0 ){
          swap( c[ i ][ j ] , c[ i ][ j + 1 ] );
        }else{
          swap( c[ i ][ j ] , c[ i - 1 ][ j ] );
        }
        return;
      }
}
void rotate2(){
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ )
      if( c[ i ][ j ] == 'X' ){
        if( i == 0 && j == 0 ){
          swap( c[ i ][ j ] , c[ i ][ j + 1 ] );
        }else if( i == 0 ){
          swap( c[ i ][ j ] , c[ i + 1 ][ j ] );
        }else if( j == 0 ){
          swap( c[ i ][ j ] , c[ i - 1 ][ j ] );
        }else{
          swap( c[ i ][ j ] , c[ i ][ j - 1 ] );
        }
        return;
      }
}
void solve(){
  for( int i = 0 ; i < 100 ; i ++ ){
    if( okay() ){
      puts( "YES" );
      exit( 0 );
    }
    rotate();
  }
  for( int i = 0 ; i < 200 ; i ++ ){
    if( okay() ){
      puts( "YES" );
      exit( 0 );
    }
    rotate2();
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
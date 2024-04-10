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
#define N 11
bool tag[ N ][ N ];
int trans( char ctmp ){
  return ctmp - 'a' + 1;
}
char c[ 4 ][ 4 ];
int pi[ 4 ];
int pj[ 4 ];
void build(){

}
void init(){
  for( int i = 0 ; i < 4 ; i ++ )
    scanf( "%s" , c[ i ] );
}
void goRook( int ni , int nj ){
  tag[ ni ][ nj ] = true;
  for( int i = 1 ; i <= 8 ; i ++ )
    if( ni + i <= 8 ){
      bool flag = false;
      for( int j = 0 ; j < 3 ; j ++ )
        if( ni + i == pi[ j ] && nj == pj[ j ] ){
          flag = true; break;
        }
      tag[ ni + i ][ nj ] = true;
      if( flag ) break;
    }else break;
  for( int i = 1 ; i <= 8 ; i ++ )
    if( ni - i >= 1 ){
      bool flag = false;
      for( int j = 0 ; j < 3 ; j ++ )
        if( ni - i == pi[ j ] && nj == pj[ j ] ){
          flag = true; break;
        }
      tag[ ni - i ][ nj ] = true;
      if( flag ) break;
    }else break;
  for( int i = 1 ; i <= 8 ; i ++ )
    if( nj + i <= 8 ){
      bool flag = false;
      for( int j = 0 ; j < 3 ; j ++ )
        if( ni == pi[ j ] && nj + i == pj[ j ] ){
          flag = true; break;
        }
      tag[ ni ][ nj + i ] = true;
      if( flag ) break;
    }else break;
  for( int i = 1 ; i <= 8 ; i ++ )
    if( nj - i >= 1 ){
      bool flag = false;
      for( int j = 0 ; j < 3 ; j ++ )
        if( ni == pi[ j ] && nj - i == pj[ j ] ){
          flag = true; break;
        }
      tag[ ni ][ nj - i ] = true;
      if( flag ) break;
    }else break;
}
void goKing( int ni , int nj ){
  for( int i = -1 ; i <= 1 ; i ++ )
    for( int j = -1 ; j <= 1 ; j ++ )
      tag[ ni + i ][ nj + j ] = true;
}
void test( int ni , int nj ){
  for( int i = -1 ; i <= 1 ; i ++ )
    for( int j = -1 ; j <= 1 ; j ++ )
      if( ni + i >= 1 && ni + i <= 8 &&
          nj + j >= 1 && nj + j <= 8 ){
        if( !tag[ ni + i ][ nj + j ] ){
          puts( "OTHER" );
          exit( 0 );
        }
      }
}
void test2( int kk , int ppi , int ppj ){
  for( int i = 1 ; i <= 8 ; i ++ )
    for( int j = 1 ; j <= 8 ; j ++ )
      tag[ i ][ j ] = false;
  for( int i = 0 ; i < 3 ; i ++ ){
    if( i == kk ) continue;
    if( i < 2 ) goRook( pi[ i ] , pj[ i ] );
    else goKing( pi[ i ] , pj[ i ] );
  }
  if( !tag[ ppi ][ ppj ] ){
    puts( "OTHER" );
    exit( 0 );
  }
}
void solve(){
  for( int i = 0 ; i < 4 ; i ++ ){
    pi[ i ] = trans( c[ i ][ 0 ] );
    pj[ i ] = c[ i ][ 1 ] - '0';
  }
  goRook( trans( c[ 0 ][ 0 ] ) , c[ 0 ][ 1 ] - '0' );
  goRook( trans( c[ 1 ][ 0 ] ) , c[ 1 ][ 1 ] - '0' );
  goKing( trans( c[ 2 ][ 0 ] ) , c[ 2 ][ 1 ] - '0' );
  test( trans( c[ 3 ][ 0 ] ) , c[ 3 ][ 1 ] - '0' );
  for( int i = -1 ; i <= 1 ; i ++ )
    for( int j = -1 ; j <= 1 ; j ++ ){
      int nxti = pi[ 3 ] + i , nxtj = pj[ 3 ] + j;
      for( int k = 0 ; k < 3 ; k ++ )
        if( nxti == pi[ k ] && nxtj == pj[ k ] )
          test2( k , nxti , nxtj );
    }
  puts( "CHECKMATE" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
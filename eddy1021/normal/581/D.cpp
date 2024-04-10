// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 110
char c[ N ][ N ];
int x[ 3 ] , y[ 3 ];
int tx[ 3 ] , ty[ 3 ];
bool okay;
int an;
void build(){

}
void init(){
  for( int i = 0 ; i < 3 ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
  }
}
void test( int msk ){
  for( int i = 0 ; i < 3 ; i ++ )
    tx[ i ] = x[ i ],
    ty[ i ] = y[ i ];
  char sgn[] = "ABC";
  for( int i = 0 ; i < 3 ; i ++ )
    if( msk & ( 1 << i ) )
      swap( tx[ i ] , ty[ i ] );
// y = y = y
  if( ty[ 0 ] == ty[ 1 ] && ty[ 1 ] == ty[ 2 ] ){
    if( tx[ 0 ] + tx[ 1 ] + tx[ 2 ] == ty[ 0 ] ){
      an = ty[ 0 ];
      for( int i = 1 ; i <= tx[ 0 ] ; i ++ )
        for( int j = 1 ; j <= ty[ 0 ] ; j ++ )
          c[ i ][ j ] = 'A';
      for( int i = tx[ 0 ] + 1 ; i <= tx[ 0 ] + tx[ 1 ] ; i ++ )
        for( int j = 1 ; j <= ty[ 0 ] ; j ++ )
          c[ i ][ j ] = 'B';
      for( int i = tx[ 0 ] + tx[ 1 ] + 1  ;
              i <= tx[ 0 ] + tx[ 1 ] + tx[ 2 ] ; i ++ )
        for( int j = 1 ; j <= ty[ 0 ] ; j ++ )
          c[ i ][ j ] = 'C';
      okay = true;
      return;
    }
  }
// x = x = x
  if( tx[ 0 ] == tx[ 1 ] && tx[ 1 ] == tx[ 2 ] ){
    if( ty[ 0 ] + ty[ 1 ] + ty[ 2 ] == tx[ 0 ] ){
      an = tx[ 0 ];
      for( int i = 1 ; i <= tx[ 0 ] ; i ++ )
        for( int j = 1 ; j <= ty[ 0 ] ; j ++ )
          c[ i ][ j ] = 'A';
      for( int i = 1 ; i <= tx[ 0 ] ; i ++ )
        for( int j = ty[ 0 ] + 1 ; j <= ty[ 0 ] + ty[ 1 ] ; j ++ )
          c[ i ][ j ] = 'B';
      for( int i = 1 ; i <= tx[ 0 ] ; i ++ )
        for( int j = ty[ 0 ] + ty[ 1 ] + 1 ;
                j <= ty[ 0 ] + ty[ 1 ] + ty[ 2 ] ; j ++ )
          c[ i ][ j ] = 'C';
      okay = true;
      return;
    }
  }
// |-
  if( tx[ 1 ] > tx[ 0 ] ){
    swap( tx[ 0 ] , tx[ 1 ] );
    swap( ty[ 0 ] , ty[ 1 ] );
    swap( sgn[ 0 ] , sgn[ 1 ] );
  }
  if( tx[ 2 ] > tx[ 0 ] ){
    swap( tx[ 0 ] , tx[ 2 ] );
    swap( ty[ 0 ] , ty[ 2 ] );
    swap( sgn[ 0 ] , sgn[ 2 ] );
  }
  if( tx[ 0 ] == tx[ 1 ] + tx[ 2 ] &&
      ty[ 1 ] == ty[ 2 ] && ty[ 0 ] + ty[ 1 ] == tx[ 0 ] ){
    okay = true;
    an = tx[ 0 ];
    for( int i = 1 ; i <= tx[ 0 ] ; i ++ )
      for( int j = 1 ; j <= ty[ 0 ] ; j ++ )
        c[ i ][ j ] = sgn[ 0 ];
    for( int i = 1 ; i <= tx[ 1 ] ; i ++ )
      for( int j = ty[ 0 ] + 1 ; j <= ty[ 0 ] + ty[ 1 ] ; j ++ )
        c[ i ][ j ] = sgn[ 1 ];
    for( int i = tx[ 1 ] + 1 ; i <= tx[ 1 ] + tx[ 2 ] ; i ++ )
      for( int j = ty[ 0 ] + 1 ; j <= ty[ 0 ] + ty[ 2 ] ; j ++ )
        c[ i ][ j ] = sgn[ 2 ];
  }
}
void solve(){
  for( int i = 0 ; i < 8 ; i ++ )
    if( !okay )
      test( i );
  if( !okay ) puts( "-1" );
  else{
    printf( "%d\n" , an );
    for( int i = 1 ; i <= an ; i ++ , puts( "" ) )
      for( int j = 1 ; j <= an ; j ++ )
        putchar( c[ i ][ j ] );
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
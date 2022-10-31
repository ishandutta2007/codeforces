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
#define N 1010101
int a[ 9 ] , c[ N ];
void init(){
  for( int i = 1 ; i <= 4 ; i ++ )
    a[ i ] = getint();
}
void solve(){
  if( a[ 3 ] == 0 ){
    if( a[ 4 ] == 0 ){
      if( a[ 1 ] && a[ 2 ] ){
        puts( "-1" );
        exit( 0 );
      }
      for( int i = 0 ; i < a[ 1 ] ; i ++ )
        putchar( '4' );
      for( int i = 0 ; i < a[ 2 ] ; i ++ )
        putchar( '7' );
      puts( "" );
      exit( 0 );
    }
    if( a[ 4 ] > 1 ){
      puts( "-1" );
      exit( 0 );
    }
    if( a[ 1 ] == 0 || a[ 2 ] == 0 ){
      puts( "-1" );
      exit( 0 );
    }
    for( int i = 0 ; i < a[ 2 ] ; i ++ )
      putchar( '7' );
    for( int i = 0 ; i < a[ 1 ] ; i ++ )
      putchar( '4' );
    puts( "" );
  }else if( a[ 4 ] == 0 ){
    if( a[ 3 ] > 1 ){
      puts( "-1" );
      exit( 0 );
    }
    if( a[ 1 ] == 0 || a[ 2 ] == 0 ){
      puts( "-1" );
      exit( 0 );
    }
    for( int i = 0 ; i < a[ 1 ] ; i ++ )
      putchar( '4' );
    for( int i = 0 ; i < a[ 2 ] ; i ++ )
      putchar( '7' );
    puts( "" );
  }else if( a[ 3 ] == a[ 4 ] + 1 ){
    if( a[ 1 ] < a[ 3 ] || a[ 2 ] < a[ 3 ] ){
      puts( "-1" );
      exit( 0 );
    }
    for( int i = a[ 3 ] ; i < a[ 1 ] ; i ++ )
      putchar( '4' );
    for( int i = 0 ; i < a[ 3 ] ; i ++ )
      printf( "47" );
    for( int i = a[ 3 ] ; i < a[ 2 ] ; i ++ )
      putchar( '7' );
    puts( "" );
  }else if( a[ 4 ] == a[ 3 ] + 1 ){
    if( a[ 1 ] < a[ 4 ] || a[ 2 ] < a[ 4 ] ){
      puts( "-1" );
      exit( 0 );
    }
    putchar( '7' );
    for( int i = a[ 3 ] ; i < a[ 1 ] ; i ++ )
      putchar( '4' );
    for( int i = 1 ; i < a[ 3 ] ; i ++ )
      printf( "74" );
    for( int i = a[ 3 ] ; i < a[ 2 ] ; i ++ )
      putchar( '7' );
    putchar( '4' );
  }else if( a[ 3 ] == a[ 4 ] ){
    if( a[ 1 ] < a[ 3 ] || a[ 2 ] < a[ 3 ] ){
      puts( "-1" );
      exit( 0 );
    }else if( a[ 1 ] == a[ 3 ] ){
      if( a[ 2 ] < a[ 3 ] + 1 ){
        puts( "-1" );
        exit( 0 );
      }
      for( int i = 0 ; i < a[ 3 ] ; i ++ )
        printf( "74" );
      for( int i = a[ 3 ] ; i < a[ 2 ] ; i ++ )
        putchar( '7' );
      puts( "" );
    }else if( a[ 2 ] == a[ 3 ] ){
      if( a[ 1 ] < a[ 3 ] + 1 ){
        puts( "-1" );
        exit( 0 );
      }
      for( int i = a[ 3 ] ; i < a[ 1 ] ; i ++ )
        putchar( '4' );
      for( int i = 0 ; i < a[ 3 ] ; i ++ )
        printf( "74" );
      puts( "" );
    }else{
      for( int i = a[ 3 ] ; i < a[ 1 ] ; i ++ )
        putchar( '4' );
      for( int i = 1 ; i < a[ 3 ] ; i ++ )
        printf( "74" );
      for( int i = a[ 3 ] ; i <= a[ 2 ] ; i ++ )
        putchar( '7' );
      putchar( '4' );
      puts( "" );
    }
  }else{
    puts( "-1" );
    exit( 0 );
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
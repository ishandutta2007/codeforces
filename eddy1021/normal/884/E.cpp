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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N (1 << 14)
struct DJS{
  int sz;
  pair<int,int> p[ 2 ][ N ];
  int m[ N << 1 ];
  DJS(){
    sz = 0;
    for( int i = 0 ; i < (N << 1) ; i ++ )
      m[ i ] = -1;
  }
  void reset( int which , int n , int* a ){
    for( int i = 0 ; i < n ; i ++ ){
      p[ which ][ i ] = { which , i };
      if( a[ i ] == 1 )
        sz ++;
    }
  }
  pair<int,int> f( int which , int x ){
    if( make_pair( which , x ) == p[ which ][ x ] )
      return p[ which ][ x ];
    return p[ which ][ x ] = f( p[ which ][ x ].first ,
                                p[ which ][ x ].second );
  }
  void uni( int w1 , int x1 , int w2 , int x2 ){
    tie( w1 , x1 ) = f( w1 , x1 );
    tie( w2 , x2 ) = f( w2 , x2 );
    if( w1 == w2 and x1 == x2 ) return;
    sz --;
    p[ w1 ][ x1 ] = { w2 , x2 };
  }
  pair<int,int> sv[ N ];
  void rebuild( int which , int n ){
    for( int i = 0 ; i < n ; i ++ )
      sv[ i ] = f( which , i );
    for( int i = 0 ; i < n ; i ++ ){
      int hs = ( sv[ i ].second << 1 ) | sv[ i ].first;
      if( m[ hs ] == -1 ) m[ hs ] = (i << 1) | which;
      p[ which ][ i ] = { m[ hs ] & 1 , m[ hs ] >> 1 };
    }
    for( int i = 0 ; i < n ; i ++ )
      m[ ( sv[ i ].second << 1 ) | sv[ i ].first ] = -1;
  }
} djs;
void build(){

}
int n , m , a[ 2 ][ N ];
void init(){
  n = getint();
  m = getint();
}
char r[ N ];
int chg( char ctmp ){
  if( '0' <= ctmp and ctmp <= '9' ) return ctmp - '0';
  return ctmp - 'A' + 10;
}
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s" , r );
    for( int j = 0 , k = 0 ; j < m / 4 ; j ++ ){
      int num = chg( r[ j ] );
      for( int bt = 3 ; bt >= 0 ; bt -- )
        a[ i & 1 ][ k ++ ] = (num >> bt) & 1;
    }
    int now = i & 1 , pre = 1 - now;
    //for( int j = 0 ; j < m ; j ++ )
      //printf( "%d" , a[ now ][ j ] );
    //puts( "" );
    djs.reset( now , m , a[ now ] );
    if( i ){
      for( int j = 0 ; j < m ; j ++ )
        if( a[ pre ][ j ] and a[ now ][ j ] )
          djs.uni( 0 , j , 1 , j );
    }
    for( int j = 1 ; j < m ; j ++ )
      if( a[ now ][ j - 1 ] and a[ now ][ j ] )
        djs.uni( now , j - 1 , now , j );
    djs.rebuild( now , m );
  }
  cout << djs.sz << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
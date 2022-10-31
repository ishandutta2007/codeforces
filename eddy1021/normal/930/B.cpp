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
#define N 101010
void build(){

}
char c[ N ];
int len , f[ N ];
void imp(){
  puts( "0" );
  Bye;
}
void init(){
  scanf( "%s" , c );
  len = strlen( c );
  for( int i = len ; i < len + len ; i ++ )
    c[ i ] = c[ i - len ];
  f[ 0 ] = -1;
  for( int i = 1 , fl = -1 ; i + 1 < len + len ; i ++ ){
    while( fl >= 0 and c[ i ] != c[ fl + 1 ] ) fl = f[ fl ];
    if( c[ i ] == c[ fl + 1 ] ) fl ++;
    f[ i ] = fl;
    if( fl + 1 == len ) imp();
  }
}
vector<int> pos[ 26 ];
#define K 5140
char cc[ K ][ K ];
LL win;
void solve(){
  for( int i = 0 ; i < len ; i ++ )
    pos[ c[ i ] - 'a' ].push_back( i );
  for( int ch = 0 ; ch < 26 ; ch ++ ){
    if( pos[ ch ].empty() ) continue;
    for( size_t j = 0 ; j < pos[ ch ].size() ; j ++ ){
      int i = pos[ ch ][ j ];
      for( int k = 0 ; k < len ; k ++ )
        cc[ j ][ k ] = c[ i + k ];
    }
    int mx = 0;
    for( int k = 0 ; k < len ; k ++ ){
      int cnt[ 26 ] = {};
      for( size_t j = 0 ; j < pos[ ch ].size() ; j ++ )
        cnt[ cc[ j ][ k ] - 'a' ] ++;
      int tmx = 0;
      for( int u = 0 ; u < 26 ; u ++ )
        if( cnt[ u ] == 1 )
          tmx ++;
      mx = max( mx , tmx );
    }
    win += mx;
  }
  printf( "%.12f\n" , (double)win / ((double)len) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
int n , q , a[ N ] , ans[ N ];
vector< pair<int,int> > qry[ N ];
void init(){
  n = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < q ; i ++ ){
    int l = getint();
    int x = getint();
    qry[ l ].push_back( {x, i} );
  }
}
int way = 1;
int b[ 20 ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    int res = a[ i ];
    for( int j = 0 ; j < 20 ; j ++ )
      if( (res >> j) & 1 )
        res ^= b[ j ];
    if( res == 0 ) way = mul( way , 2 );
    else{
      for( int j = 0 ; j < 20 ; j ++ )
        if( (res >> j) & 1 ){
          b[ j ] = res;
          for( int ii = 0 ; ii < 20 ; ii ++ ){
            if( ii == j ) continue;
            if( (b[ ii ] >> j) & 1 )
              b[ ii ] ^= b[ j ];
          }
          break;
        }
    }
    for( auto qq : qry[ i ] ){
      res = qq.first;
      for( int j = 0 ; j < 20 ; j ++ )
        if( (res >> j) & 1 )
          res ^= b[ j ];
      if( res == 0 )
        ans[ qq.second ] = way;
    }
  }
  for( int i = 0 ; i < q ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
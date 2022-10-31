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
#define N 303030
void build(){

}
int n , m;
vector<LL> v[ 4 ];
void init(){
  n = getint();
  m = getint();
  while( n -- ){
    int wi = getint();
    int ci = getint();
    v[ wi ].push_back( ci );
  }
  for( int i = 1 ; i <= 3 ; i ++ ){
    sort( v[ i ].begin() , v[ i ].end() );
    reverse( v[ i ].begin() , v[ i ].end() );
  }
}
LL ans;
LL bst[ 4 ][ N ] , cc[ N ];
int sz[ 4 ];
void solve(){
  for( int i = 1 ; i <= 3 ; i ++ ){
    sz[ i ] = (int)v[ i ].size();
    for( int j = 1 ; j <= sz[ i ] ; j ++ ){
      bst[ i ][ i * j ] = bst[ i ][ i * ( j - 1 ) ] + v[ i ][ j - 1 ];
      if( i * j <= m ){
        ans = max( ans , bst[ i ][ i * j ] );
        if( i < 3 )
          cc[ i * j ] = max( cc[ i * j ] , bst[ i ][ i * j ] );
      }
    }
    for( int j = 1 ; j <= m ; j ++ )
      bst[ i ][ j ] = max( bst[ i ][ j ] , bst[ i ][ j - 1 ] );
  }
  for( int j = 1 ; j <= m ; j ++ )
    cc[ j ] = max( cc[ j ] , cc[ j - 1 ] );
  for( int i = 1 ; i <= m ; i ++ ){
    int bl = 0 , br = min( i / 2 , sz[ 2 ] );
    bl = max( 0 , ( i - sz[ 1 ] + 1 ) / 2 );
    while( br - bl > 9 ){
      int mid1 = bl + ( br - bl ) / 3;
      int mid2 = br - ( br - bl ) / 3;
      LL vl1 = bst[ 1 ][ i - mid1 * 2 ] + bst[ 2 ][ mid1 * 2 ];
      LL vl2 = bst[ 1 ][ i - mid2 * 2 ] + bst[ 2 ][ mid2 * 2 ];
      if( vl1 < vl2 ){
        cc[ i ] = max( cc[ i ] , vl2 );
        bl = mid1 + 1;
      }else{
        cc[ i ] = max( cc[ i ] , vl1 );
        br = mid2 - 1;
      }
    }
    for( int j = bl ; j <= br ; j ++ )
      cc[ i ] = max( cc[ i ] ,
                     bst[ 1 ][ i - j * 2 ] + bst[ 2 ][ j * 2 ] );
    cc[ i ] = max( cc[ i ] , cc[ i - 1 ] );
  }
  ans = max( ans , cc[ m ] );
  for( int i = 1 ; i <= m ; i ++ )
    ans = max( ans , bst[ 3 ][ i ] + cc[ m - i ] );
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
#define N 514
void build(){

}
int n , a[ N ][ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      a[ i ][ j ] = getint();
}
int dp[ N ][ N ][ 2 ];
bool g[ N ][ N ][ 2 ];
int dp2[ N ][ N ];
bool g2[ N ][ N ];
int DP( int l , int r , int bt );
int DP2( int l , int r ){
  l %= n; r %= n;
  if( ( l + 1 ) % n == r ) return 1;
  if( l == r ) return 1;
  if( g2[ l ][ r ] ) return dp2[ l ][ r ];
  int ret = 0;
  ret = add( DP( r , l + 1 , 0 ) ,
             DP( r + n - 1 , l , 0 ) );
  for( int i = l + 1 ; ( i + 1 ) % n != r ; i ++ )
    ret = add( ret , 
               mul( DP( i , l , 0 ) ,
                    DP( r , i + 1 , 0 ) ) );
  g2[ l ][ r ] = true;
  return dp2[ l ][ r ] = ret;
}
int DP( int l , int r , int bt ){
  l %= n; r %= n;
  if( l == r ) return 1;
  if( g[ l ][ r ][ bt ] ) return dp[ l ][ r ][ bt ];
  int ret = 0;
  if( bt == 0 ){
    for( int i = r ; ; i ++ ){
      if( i % n == l ) break;
      if( !a[ l % n ][ i % n ] ) continue;
      ret = add( ret ,
                 mul( DP( i , r , 0 ) ,
                      DP( l , i , 1 ) ) );
    }
  }else{
    ret = DP( l + n - 1 , r , 0 );
    for( int i = r + 1 ; ; i ++ ){
      if( i % n == l ) break;
      if( !a[ l % n ][ i % n ] ) continue;
      ret = add( ret ,
                 mul( DP( l , i , 1 ) ,
                      DP2( r , i ) ) );
    }
  }
  g[ l ][ r ][ bt ] = true;
  //printf( "%d %d %d : %d\n" , l , r , bt , ret );
  return dp[ l ][ r ][ bt ] = ret;
}
void solve(){
  printf( "%d\n" , DP( 0 , 1 , 0 ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
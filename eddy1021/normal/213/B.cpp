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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 111
int C[ N ][ N ];
void build(){
  for( int i = 0 ; i < N ; i ++ )
    C[ i ][ 0 ] = C[ i ][ i ] = 1;
  for( int i = 2 ; i < N ; i ++ )
    for( int j = 1 ; j < i ; j ++ )
      C[ i ][ j ] = add( C[ i - 1 ][ j - 1 ] , C[ i - 1 ][ j ] );
}
int n , a[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < 10 ; i ++ )
    a[ i ] = getint();
}
int dp[ N ][ N ];
int cal( int len ){
  for( int i = 0 ; i <= 10 ; i ++ )
    for( int j = 0 ; j <= len ; j ++ )
      dp[ i ][ j ] = 0;
  dp[ 10 ][ 0 ] = 1;
  for( int i = 9 ; i >= 0 ; i -- )
    for( int j = 0 ; j <= len ; j ++ ){
      int pre = dp[ i + 1 ][ j ];
      if( pre == 0 ) continue;
      for( int jj = a[ i ] ; j + jj <= len ; jj ++ ){
        if( i or jj == 0 ){
          int tdp = mul( pre , C[ j + jj ][ jj ] );
          dp[ i ][ j + jj ] = add( dp[ i ][ j + jj ] , tdp );
        }else{
          int tdp = mul( pre , C[ j + jj - 1 ][ jj ] );
          dp[ i ][ j + jj ] = add( dp[ i ][ j + jj ] , tdp );
        }
      }
    }
  return dp[ 0 ][ len ];
}
void solve(){
  int tot = accumulate( a , a + 10 , 0 );
  if( tot > n ){
    puts( "0" );
    exit(0);
  }
  int ans = 0;
  for( int l = max( tot , 1 ) ; l <= n ; l ++ )
    ans = add( ans , cal( l ) );
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
#define N 1021
int t , k , ten[ N ];
int dp[ N ][ N ][ 2 ] , ok[ N ];
// bt, pre, got
bool lucky( int d ){
  return d == 4 or d == 7;
}
void build(){
  ten[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    ten[ i ] = mul( ten[ i - 1 ] , 10 );
  dp[ 0 ][ 0 ][ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ ){
    for( int j = 0 ; j < i ; j ++ )
      for( int g = 0 ; g < 2 ; g ++ ){
        if( dp[ i - 1 ][ j ][ g ] == 0 ) continue;
        for( int cur = 0 ; cur < 10 ; cur ++ ){
          int nj = j;
          int ng = g;
          if( j and lucky( cur ) and i - j <= k )
            ng = 1;
          if( lucky( cur ) ) nj = i;
          dp[ i ][ nj ][ ng ] = add( dp[ i ][ nj ][ ng ] ,
                                     dp[ i - 1 ][ j ][ g ] );
        }
      }
    for( int j = 0 ; j <= i ; j ++ )
      ok[ i ] = add( ok[ i ] , dp[ i ][ j ][ 1 ] );
  }
  for( int i = 1 ; i < N ; i ++ )
    for( int j = i ; j >= 0 ; j -- )
      dp[ i ][ j ][ 0 ] = add( dp[ i ][ j ][ 0 ] , dp[ i ][ j + 1 ][ 0 ] );
}
void init(){
  t = getint();
  k = getint();
}
char c[ N ];
bool good(){
  int len = strlen( c );
  int pre = -1;
  for( int i = 0 ; i < len ; i ++ )
    if( lucky( c[ i ] - '0' ) ){
      if( pre != -1 and i - pre <= k )
        return true;
      pre = i;
    }
  return false;
}
int tans;
void go( int now , int pre , int gt ){
  if( now < 1 ){
    if( gt )
      tans = add( tans , 1 );
    return;
  }
  int vl = c[ now - 1 ] - '0';
  for( int i = 0 ; i < vl ; i ++ ){
    if( gt )
      tans = add( tans , ten[ now - 1 ] );
    else if( lucky( i ) ){
      if( pre != -1 and pre - now <= k )
        tans = add( tans , ten[ now - 1 ] );
      else{
        tans = add( tans , ok[ now - 1 ] );
        int mst = now - k;
        tans = add( tans , dp[ now - 1 ][ max( 1 , mst ) ][ 0 ] );
      }
    }else{
      // + gt
      tans = add( tans , ok[ now - 1 ] );
      // <= k - pre
      if( pre != -1 ){
        int mst = pre - k;
        tans = add( tans , dp[ now - 1 ][ max( 1 , mst ) ][ 0 ] );
      }
    }
  }
  if( lucky( vl ) ){
    if( pre != -1 and pre - now <= k )
      gt = 1;
    pre = now;
  }
  go( now - 1 , pre , gt );
}
int cal(){
  int bt = strlen( c );
  for( int i = 0 , j = bt - 1 ; i < j ; i ++ , j -- )
    swap( c[ i ] , c[ j ] );
  tans = 0;
  go( bt , -1 , 0 );
  //printf( "   %d\n" , tans );
  return tans;
}
void solve(){
  build();
  while( t -- ){
    scanf( "%s" , c );
    int ans = sub( 0 , cal() );
    if( good() ) ans = add( ans , 1 );
    scanf( "%s" , c );
    ans = add( ans , cal() );
    printf( "%d\n" , ans );
  }
}
int main(){
  //build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
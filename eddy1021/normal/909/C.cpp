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
void build(){

}
#define N 5050
int dp[ 2 ][ N ][ 2 ];
int n;
char c[ N ][ 3 ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] );
}
int bns[ N ][ 2 ];
void solve(){
  dp[ 0 ][ 0 ][ 1 ] = 1;
  for( int i = 0 ; i < n ; i ++ ){
    int now = i & 1 , nxt = 1 - now;
    for( int j = 0 ; j <= n ; j ++ )
      for( int k = 0 ; k < 2 ; k ++ ){
        dp[ nxt ][ j ][ k ] = 0;
        bns[ j ][ k ] = 0;
      }
    for( int j = 0 ; j <= n ; j ++ )
      for( int k = 0 ; k < 2 ; k ++ ){
        if( dp[ now ][ j ][ k ] == 0 ) continue;
        if( c[ i + 1 ][ 0 ] == 's' ){
          if( k == 0 ){
            dp[ nxt ][ j ][ 1 ] = add( dp[ nxt ][ j ][ 1 ] ,
                                       dp[ now ][ j ][ k ] );
          }else{
            bns[ j ][ 1 ] = add( bns[ j ][ 1 ] , dp[ now ][ j ][ k ] );
            //dp[ nxt ][ j ][ 1 ] = add( dp[ nxt ][ j ][ 1 ] ,
                                       //dp[ now ][ j ][ k ] );
          }
        }else{
          if( k == 0 ){
            dp[ nxt ][ j + 1 ][ 0 ] = add( dp[ nxt ][ j + 1 ][ 0 ] ,
                                           dp[ now ][ j ][ k ] );
          }else{
            bns[ j + 1 ][ 0 ] = add( bns[ j + 1 ][ 0 ] , dp[ now ][ j ][ k ] );
          }
        }
      }
    for( int k = 0 ; k < 2 ; k ++ )
      for( int j = n , ps = 0 ; j >= 0 ; j -- ){
        ps = add( ps , bns[ j ][ k ] );
        if( j == 0 and k == 0 ) continue;
        dp[ nxt ][ j ][ k ] = add( dp[ nxt ][ j ][ k ] , ps );
      }
  }
  int ans = 0;
  for( int i = 0 ; i <= n ; i ++ )
    ans = add( ans , dp[ n & 1 ][ i ][ 1 ] );
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
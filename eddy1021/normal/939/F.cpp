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
const int inf = 1e9;
void build(){

}
int n , k;
void init(){
  n = getint();
  k = getint();
}
int dp[ N ][ 2 ] , lst;
int pdp[ N ][ 2 ];
int dq[ N ] , df , dt;
void solve(){
  for( int i = 0 ; i <= n ; i ++ )
    dp[ i ][ 0 ] = dp[ i ][ 1 ] = inf;
  dp[ 0 ][ 0 ] = 0;
  while( k -- ){
    int li = getint();
    int ri = getint();
    for( int i = 0 ; i <= n ; i ++ )
      for( int j = 0 ; j < 2 ; j ++ ){
        pdp[ i ][ j ] = dp[ i ][ j ];
        dp[ i ][ j ] = inf;
      }
    for( int i = 0 ; i <= n ; i ++ ){
      if( i + li - lst <= n )
        dp[ i + li - lst ][ 0 ] = pdp[ i ][ 0 ];
      dp[ i ][ 1 ] = pdp[ i ][ 1 ];
    }
    for( int i = 0 ; i <= n ; i ++ )
      for( int j = 0 ; j < 2 ; j ++ ){
        pdp[ i ][ j ] = dp[ i ][ j ];
        dp[ i ][ j ] = inf;
      }
    int dlt = ri - li;
    for( int i = 0 ; i <= n ; i ++ ){
      if( i + dlt <= n )
        dp[ i + dlt ][ 0 ] = pdp[ i ][ 0 ];
      dp[ i ][ 1 ] = pdp[ i ][ 1 ];
    }
    //for( int i = 0 ; i <= n ; i ++ )
      //for( int j = 0 ; j < 2 ; j ++ )
        //if( dp[ i ][ j ] < inf )
          //printf( "%d %d %d\n" , i , j , dp[ i ][ j ] );
    for( int j = 0 ; j < 2 ; j ++ ){
      df = dt = 0;
      for( int i = 0 ; i <= n ; i ++ ){
        while( df != dt and pdp[ dq[ dt - 1 ] ][ j ] >= pdp[ i ][ j ] )
          dt --;
        while( df != dt and dq[ df ] < i - dlt )
          df ++;
        dq[ dt ++ ] = i;
        dp[ i ][ j ] = min( dp[ i ][ j ] ,
                            pdp[ dq[ df ] ][ j ] + 2 );
        dp[ i ][ 1 - j ] = min( dp[ i ][ 1 - j ] ,
                                pdp[ dq[ df ] ][ j ] + 1 );
      }
    }
    // i, 0  +0  i + dlt, 0
    //       +1  i, 1 ... i + dlt, 1
    //       +2  i, 0 ... i + dlt, 0
    // i, 1  +0  i, 1
    //       +1  i, 0 ... i + dlt, 0
    //       +2  i, 1 ... i + dlt, 1
    lst = ri;
    //for( int i = 0 ; i <= n ; i ++ )
      //for( int j = 0 ; j < 2 ; j ++ )
        //if( dp[ i ][ j ] < inf )
          //printf( "%d %d %d\n" , i , j , dp[ i ][ j ] );
  }
  int ans = dp[ n ][ 1 ];
  if( n + n - lst <= n )
    ans = min( ans , dp[ n - (n + n - lst) ][ 0 ] );
  if( ans >= inf )
    puts( "Hungry" ); 
  else{
    puts( "Full" ); 
    cout << ans << endl;
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
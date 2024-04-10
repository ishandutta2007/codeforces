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
#define N 101010
void build(){

}
vector< int > v[ N ];
int n , m , k , x;
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  k = getint();
  x = getint();
}
int dp[ N ][ 11 ][ 3 ] , tdp[ 11 ][ 3 ];
inline bool okay( int t1 , int t2 ){
  if( t1 == 1 and t2 == 1 ) return false;
  if( t1 == 1 and t2 == 2 ) return false;
  if( t1 == 2 and t2 == 1 ) return false;
  return true;
}
void DP( int now , int prt ){
  dp[ now ][ 0 ][ 0 ] = k - 1;
  if( x >= 1 )
    dp[ now ][ 1 ][ 1 ] = 1;
  dp[ now ][ 0 ][ 2 ] = m - k;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    DP( son , now );
    for( int i = 0 ; i <= x ; i ++ )
      for( int j = 0 ; j < 3 ; j ++ ){
        tdp[ i ][ j ] = dp[ now ][ i ][ j ];
        dp[ now ][ i ][ j ] = 0;
      }
    for( int i = 0 ; i <= x ; i ++ )
      for( int j = 0 ; j < 3 ; j ++ ){
        if( tdp[ i ][ j ] == 0 ) continue;
        for( int ii = 0 ; i + ii <= x ; ii ++ )
          for( int jj = 0 ; jj < 3 ; jj ++ ){
            if( dp[ son ][ ii ][ jj ] == 0 ) continue;
            if( not okay( j , jj ) ) continue;
            //printf( "%d : %d %d %d *\n" , now , i , j , tdp[ i ][ j ] );
            //printf( "%d : %d %d %d = \n" , son , ii , jj , dp[ son ][ ii ][ jj ] );
            //printf( "%d : %d %d  \n" , now , i + ii , j );
            dp[ now ][ i + ii ][ j ] = add( dp[ now ][ i + ii ][ j ] ,
                                            mul( tdp[ i ][ j ] ,
                                                 dp[ son ][ ii ][ jj ] ) );
          }
      }
  }
  //printf( "%d\n" , now );
  //for( int i = 0 ; i <= x ; i ++ )
    //for( int j = 0 ; j < 3 ; j ++ )
      //printf( "%d %d : %d\n" , i , j , dp[ now ][ i ][ j ] );
}
void solve(){
  DP( 1 , 1 );
  int ans = 0;
  for( int i = 0 ; i <= x ; i ++ )
    for( int j = 0 ; j < 3 ; j ++ )
      ans = add( ans , dp[ 1 ][ i ][ j ] );
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
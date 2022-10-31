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
#define N 333
void build(){

}
int n , a[ N ][ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      a[ i ][ j ] = getint();
}
int dp[ 2 ][ N ][ N ];
int di[]={0,1};
int dj[]={1,0};
bool out( int ni , int nj ){
  return ni < 0 or ni >= n or nj < 0 or nj >= n;
}
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = i ; j < n ; j ++ )
      dp[ 0 ][ i ][ j ] = -INF;
  dp[ 0 ][ 0 ][ 0 ] = a[ 0 ][ 0 ];
  for( int i = 1 ; i <= n - 1 + n - 1 ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    for( int j = 0 ; j < n ; j ++ )
      for( int k = j ; k < n ; k ++ )
        dp[ now ][ j ][ k ] = -INF;
    for( int j = 0 ; j < n ; j ++ )
      for( int k = j ; k < n ; k ++ ){
        if( dp[ pre ][ j ][ k ] == -INF ) continue;
        int jj = i - 1 - j;
        int kk = i - 1 - k;
        for( int dirj = 0 ; dirj < 2 ; dirj ++ )
          for( int dirk = 0 ; dirk < 2 ; dirk ++ ){
            int nxtj = j + di[ dirj ];
            int nxtjj = jj + dj[ dirj ];
            int nxtk = k + di[ dirk ];
            int nxtkk = kk + dj[ dirk ];
            //printf( "(%d,%d) -> (%d,%d) ; (%d,%d) -> (%d,%d) \n" , 
                    //j , jj , nxtj , nxtjj , k , kk , nxtk , nxtkk );
            if( out( nxtj , nxtjj ) ) continue;
            if( out( nxtk , nxtkk ) ) continue;
            if( nxtj > nxtk ){
              swap( nxtj , nxtk );
              swap( nxtjj , nxtkk );
            }
            int tdp = dp[ pre ][ j ][ k ] + a[ nxtj ][ nxtjj ];
            if( nxtj != nxtk ) tdp += a[ nxtk ][ nxtkk ];
            dp[ now ][ nxtj ][ nxtk ] = max( dp[ now ][ nxtj ][ nxtk ] ,
                                             tdp );
            //printf( "%d->%d (%d,%d)->(%d,%d) : %d\n" , i - 1 , i ,
                    //j , k , nxtj , nxtk , tdp );
          }
      }
  }
  printf( "%d\n" , dp[ ( n + n - 2 ) & 1 ][ n - 1 ][ n - 1 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
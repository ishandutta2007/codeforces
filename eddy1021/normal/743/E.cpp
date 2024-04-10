// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
#define N 1021
void build(){

}
int n , a[ N ] , nxt[ N ][ 9 ][ 10 ] , lst[ 9 ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i < 9 ; i ++ ){
    lst[ i ] = n + 1;
    nxt[ n + 1 ][ i ][ 0 ] = n + 1;
  }
  for( int i = n ; i >= 1 ; i -- ){
    for( int j = 1 ; j < 9 ; j ++ )
      nxt[ i ][ j ][ 0 ] = lst[ j ];
    lst[ a[ i ] ] = i;
  }
  for( int i = 1 ; i < 9 ; i ++ )
    nxt[ 0 ][ i ][ 0 ] = lst[ i ];
  for( int k = 1 ; k < 10 ; k ++ )
    for( int i = 0 ; i <= n + 1 ; i ++ )
      for( int j = 1 ; j < 9 ; j ++ )
        nxt[ i ][ j ][ k ] = 
          nxt[ nxt[ i ][ j ][ k - 1 ] ][ j ][ k - 1 ];
}
inline int next( int ii , int jj , int dd ){
  for( int i = 0 ; i < 10 ; i ++ )
    if( ( dd >> i ) & 1 )
      ii = nxt[ ii ][ jj ][ i ];
  return ii;
}
int ans , nd[ 9 ];
int dp[ 1 << 9 ];
int st[ 1 << 9 ] , stmp;
int DP( int msk ){
  if( msk == 0 ) return 0;
  if( st[ msk ] == stmp ) return dp[ msk ];
  st[ msk ] = stmp;
  dp[ msk ] = n + 1;
  int tmsk = msk;
  while( tmsk ){
    int id = __lg( tmsk & (-tmsk) );
    tmsk -= ( 1 << id );
    int tdp = next( DP( msk ^ ( 1 << id ) ) , id + 1 , nd[ id + 1 ] );
    dp[ msk ] = min( dp[ msk ] , tdp );
  }
  return dp[ msk ];
}
bool go( int num , int msk ){
  int tot = 0;
  for( int i = 1 ; i < 9 ; i ++ ){
    nd[ i ] = num;
    if( ( msk >> ( i - 1 ) ) & 1 )
      nd[ i ] ++;
    tot += nd[ i ];
  }
  //for( int i = 1 ; i < 9 ; i ++ )
    //printf( "%d%c" , nd[ i ] , " \n"[ i == 8 ] );
  ++ stmp;
  int tdp = DP( ( 1 << 8 ) - 1 );
  if( tdp <= n )
    ans = max( ans , tot );
  return tdp <= n;
}
inline bool okay( int len ){
  bool ok = false;
  for( int j = 0 ; j < ( 1 << 8 ) ; j ++ )
    if( go( len , j ) )
      ok = true;
  return ok;
}
void solve(){
  int bl = 0 , br = n / 8;
  while( bl <= br ){
    int mid = ( bl + br ) >> 1;
    if( okay( mid ) ) bl = mid + 1;
    else br = mid - 1;
  }
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
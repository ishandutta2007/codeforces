// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
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
#define N 1010101
void build(){

}
LL n , k , a[ N ];
void init(){
  n = getint();
  k = getint();
  for( LL i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  sort( a , a + n );
  reverse( a , a + n );
}
inline LL highbit( LL x ){
  LL res = 1;
  if( x & (LL)0xFFFF0000 ) x >>= 16, res <<= 16;
  if( x & (LL)0x0000FF00 ) x >>=  8, res <<=  8;
  if( x & (LL)0x000000F0 ) x >>=  4, res <<=  4;
  if( x & (LL)0x0000000C ) x >>=  2, res <<=  2;
  if( x & (LL)0x00000002 ) x >>=  1, res <<=  1;
  return res;
}
LL _tar;
int tag[ 10101010 ] , stmp;
int dp[ 10101010 ];
int DP( int x ){
  if( tag[ x ] == stmp ) return dp[ x ];
  tag[ x ] = stmp;
  if( x / 2 >= _tar )
    return dp[ x ] = DP( x / 2 ) + DP( x - x / 2 );
  return dp[ x ] = 1;
}
bool okay( LL tar ){
  ++ stmp;
  _tar = tar;
  LL got = 0;
  for( int i = 0 ; i < n && got < k ; i ++ ){
    if( a[ i ] < tar ) break;
    //printf( "tar = %lld %lld : %lld\n" , tar , a[ i ] , DP( a[ i ] ) );
    got += DP( a[ i ] );
    //LL x = a[ i ] / tar;
    //x = highbit( x );
    //LL tbst = 0;
    //for( int _ = 0 ; _ < 2 ; _ ++ ){
      //LL vl = a[ i ] / x;
      //if( vl >= tar ){
        //tbst = max( tbst , x );
        //continue;
      //}
      //if( vl + 1 >= tar && x * vl < a[ i ] )
        //tbst = max( tbst , x - ( a[ i ] - x * vl ) );
      //x <<= 1;
    //}
    //got += tbst;
  }
  return got >= k;
}
void solve(){
  LL sum = 0;
  for( LL i = 0 ; i < n ; i ++ )
    sum += a[ i ];
  if( sum < k ){
    puts( "-1" );
    Bye;
  }
  LL bl = 1 , br = *max_element( a , a + n ) , ans = bl;
  while( bl <= br ){
    LL mid = ( bl + br ) >> 1;
    if( okay( mid ) )
      ans = mid , bl = mid + 1;
    else
      br = mid - 1;
  }
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
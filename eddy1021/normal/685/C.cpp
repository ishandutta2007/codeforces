// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
// typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
// #define get<0> FI
// #define get<1> SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
typedef tuple<LL,LL,LL> Pt;
inline void scan( Pt& tp ){
  get<0>( tp ) = getint();
  get<1>( tp ) = getint();
  get<2>( tp ) = getint();
}
int n;
Pt p[ N ];
LL mx[ 4 ] , mn[ 4 ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    scan( p[ i ] );
  for( int i = 0 ; i < n ; i ++ ){
    int iter = 0;
    for( LL my = 1 ; my >= -1 ; my -= 2 )
      for( LL mz = 1 ; mz >= -1 ; mz -= 2 ){
        LL vl =  1 * get<0>( p[ i ] ) +
                my * get<1>( p[ i ] ) +
                mz * get<2>( p[ i ] );
        if( i == 0 )
          mx[ iter ] = mn[ iter ] = vl;
        else{
          mx[ iter ] = max( mx[ iter ] , vl );
          mn[ iter ] = min( mn[ iter ] , vl );
        }
        iter ++;
      }
  }
}
LL ans[ 4 ] , tans[ 4 ];
inline bool okay( LL r , LL par ){
  for( int i = 0 ; i < 4 ; i ++ ){
    ans[ i ] = mx[ i ] - r;
    if( ( ans[ i ] & 1 ) ^ par ) ans[ i ] ++;
    if( ans[ i ] > mn[ i ] + r ) return false;
    tans[ i ] = mn[ i ] + r;
    if( ( tans[ i ] & 1 ) ^ par ) tans[ i ] --;
    tans[ i ] -= ans[ i ];
  }
  LL chk = ans[ 0 ] - ans[ 2 ] + ans[ 3 ]; // = ans[ 1 ]
  if( chk < ans[ 1 ] ){
    LL dlt = ans[ 1 ] - chk;
    if( dlt <= tans[ 0 ] + tans[ 3 ] ){
      LL tmp = min( dlt , tans[ 0 ] );
      ans[ 0 ] += tmp;
      ans[ 3 ] += dlt - tmp;
      return true;
    }
    return false;
  }
  if( chk > ans[ 1 ] + tans[ 1 ] ){
    LL dlt = chk - ( ans[ 1 ] + tans[ 1 ] );
    if( dlt <= tans[ 2 ] ){
      ans[ 2 ] += dlt;
      return true;
    }
    return false;
  }
  return true;
}
void solve(){
  if( n == 1 ){
    printf( "%lld %lld %lld\n" , get<0>( p[ 0 ] ) , get<1>( p[ 0 ] ) , get<2>( p[ 0 ] ) );
    return;
  }
  LL bl = 0 , br = 3e18 , mid , ba = 0;
  while( bl <= br ){
    mid = ( bl + br ) >> 1;
    if( okay( mid , 0 ) || okay( mid , 1 ) ) ba = mid , br = mid - 1;
    else bl = mid + 1;
  }
  if( okay( ba , 0 ) || okay( ba , 1 ) ){
    printf( "%lld %lld %lld\n" , ( ans[ 0 ] + ans[ 3 ] ) >> 1 ,
                                 ( ans[ 0 ] - ans[ 2 ] ) >> 1 ,
                                 ( ans[ 2 ] - ans[ 3 ] ) >> 1 );
  }else assert( false );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
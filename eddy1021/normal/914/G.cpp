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
#define N (1 << 17)
/* xor convolution:
 * x = (x0,x1) , y = (y0,y1)
 * z = ( x0y0 + x1y1 , x0y1 + x1y0 )
 * =>
 * x' = ( x0+x1 , x0-x1 ) , y' = ( y0+y1 , y0-y1 )
 * z' = ( ( x0+x1 )( y0+y1 ) , ( x0-x1 )( y0-y1 ) )
 * z = (1/2) * z''
 * or convolution:
 * x = (x0, x0+x1), inv = (x0, x1-x0) w/o final div
 * and convolution:
 * x = (x0+x1, x1), inv = (x0-x1, x1) w/o final div */
typedef long long LL;
const int MAXN = N;
const LL MOD = mod7;
inline LL pw( LL x , LL k ) {
  LL res = 1;
  for( LL bs = x ; k ; k >>= 1, bs = mul(bs , bs) ){
    if( k&1 ) res = mul( res , bs );
  }
  return res;
}
inline LL Inv( LL x ) {
  return pw( x , MOD-2 );
}
inline void modit( LL& x ){
  if( x < 0 ) x += MOD;
  if( x >= MOD ) x -= MOD;
}

inline void fwt_and( LL x[ MAXN ] , bool inv=0 ) {
  for( int d = 1 ; d < N ; d <<= 1 ) {
    int d2 = d<<1;
    for( int s = 0 ; s < N ; s += d2 ) {
      for( int i = s , j = s+d ; i < s+d ; i++, j++ ){
        LL ta = x[ i ] , tb = x[ j ];
        if( !inv ){
          x[ i ] = ta+tb;
          x[ j ] = tb;
        }else{
          x[ i ] = ta-tb;
          x[ j ] = tb;
        }
        modit( x[ i ] );
        modit( x[ j ] );
      }
    }
  }
  //if( inv ){
    //for( int i = 0 ; i < N ; i++ ) {
      //x[ i ] *= Inv( N );
      //x[ i ] %= MOD;
    //}
  //}
}

inline void fwt_xor( LL x[ MAXN ] , bool inv=0 ) {
  for( int d = 1 ; d < N ; d <<= 1 ) {
    int d2 = d<<1;
    for( int s = 0 ; s < N ; s += d2 ) {
      for( int i = s , j = s+d ; i < s+d ; i++, j++ ){
        LL ta = x[ i ] , tb = x[ j ];
        x[ i ] = ta+tb;
        x[ j ] = ta-tb;
        modit( x[ i ] );
        modit( x[ j ] );
      }
    }
  }
  if( inv )
    for( int i = 0 ; i < N ; i++ ) {
      x[ i ] *= Inv( N );
      x[ i ] %= MOD;
    }
}



int fib[ N ];
void build(){
  fib[ 1 ] = 1;
  for( int i = 2 ; i < N ; i ++ )
    fib[ i ] = add( fib[ i - 1 ] , fib[ i - 2 ] );
}
int n;
LL s[ N ] , a[ N ] , b[ N ];
void init(){
  n = getint();
  //n = 1000000;
  for( int i = 0 ; i < n ; i ++ ){
    //s[ rand() % N ] ++;
    s[ getint() ] ++;
  }
  for( int i = 0 ; i < N ; i ++ ){
    for( int j = i ; j ; j = (j - 1) & i )
      a[ i ] = add( a[ i ] , mul( s[ j ] , s[ i ^ j ] ) );
    a[ i ] = add( a[ i ] , mul( s[ 0 ] , s[ i ] ) );
    a[ i ] = mul( fib[ i ] , a[ i ] );
  }

  for( int i = 0 ; i < N ; i ++ )
    b[ i ] = s[ i ];
  fwt_xor( b );
  for( int i = 0 ; i < N ; i ++ )
    b[ i ] = mul( b[ i ] , b[ i ] );
  fwt_xor( b , 1 );

  for( int i = 0 ; i < N ; i ++ ){
    b[ i ] = mul( fib[ i ] , b[ i ] );
    s[ i ] = mul( fib[ i ] , s[ i ] );
  }
}
void solve(){
  fwt_and( s );
  fwt_and( a );
  fwt_and( b );
  for( int i = 0 ; i < N ; i ++ )
    s[ i ] = mul( mul( s[ i ] , a[ i ] ) , b[ i ] );
  fwt_and( s , 1 );
  int ans = 0;
  for( int i = 0 ; i < 17 ; i ++ )
    ans = add( ans , s[ (1 << i) ] );
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
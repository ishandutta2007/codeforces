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
#define K 5
int mods[ K ]={1001010013, 1000512343, 987654361, 999991231};
struct Int{
  int v[ K ];
  Int( int x = 0 ){
    for( int i = 0 ; i < K ; i ++ )
      v[ i ] = x % mods[ i ];
  }
  Int operator+( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.v[ i ] = add( v[ i ] , he.v[ i ] , mods[ i ] );
    return ret;
  }
  Int operator-( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.v[ i ] = sub( v[ i ] , he.v[ i ] , mods[ i ] );
    return ret;
  }
  Int operator*( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.v[ i ] = mul( v[ i ] , he.v[ i ] , mods[ i ] );
    return ret;
  }
  bool operator==( const Int& he ) const{
    for( int i = 0 ; i < K ; i ++ )
      if( v[ i ] != he.v[ i ] )
        return false;
    return true;
  }
};
#define N 1000010
Int ten[ N ];
inline int randint( int lb , int rb ){
  return (LL)rand() * rand() % (rb - lb + 1) + lb;
}
void build(){
  while( true ){
    int cand = randint( 900000000 , 1000000000 );
    bool ok = true;
    for( LL i = 2 ; i * i <= cand and ok ; i ++ )
      if( cand % i == 0 ){
        ok = false;
        break;
      }
    if( not ok ) continue;
    mods[ 4 ] = cand;
    break;
  }
  ten[ 0 ] = Int( 1 );
  ten[ 1 ] = Int( 10 );
  for( int i = 2 ; i < N ; i ++ )
    ten[ i ] = ten[ i - 1 ] * ten[ 1 ];
}
char c[ N ];
Int vv[ N ];
int n;
void init(){
  scanf( "%s" , c + 1 );
  n = strlen( c + 1 );
  vv[ 0 ] = Int( 0 );
  for( int i = 1 ; i <= n ; i ++ )
    vv[ i ] = vv[ i - 1 ] * 10 + Int( c[ i ] - '0' );
}
Int value( int l , int r ){
  return vv[ r ] - vv[ l - 1 ] * ten[ r - l + 1 ];
}
void check( int len1 , int len2 ){
  if( len1 > 1 and c[ 1 ] == '0' ) return;
  if( len2 > 1 and c[ len1 + 1 ] == '0' ) return;
  if( n - len1 - len2 > 1 and c[ len1 + len2 + 1 ] == '0' ) return;
  if( value( 1 , len1 ) + value( len1 + 1 , len1 + len2 ) ==
      value( len1 + len2 + 1 , n ) ){
    for( int i = 1 ; i <= len1 ; i ++ ) putchar( c[ i ] );
    putchar( '+' );
    for( int i = len1 + 1 ; i <= len1 + len2 ; i ++ ) putchar( c[ i ] );
    putchar( '=' );
    for( int i = len1 + len2 + 1 ; i <= n ; i ++ ) putchar( c[ i ] );
    putchar( '\n' );
    Bye;
  }
}
void solve(){
  for( int i = n ; i >= 3 ; i -- ){
    int len = n - i + 1;
    if( len + len < i - 1 ) continue;
    if( len < i - 1 ){
      check( len , i - 1 - len );
      check( i - 1 - len , len );
    }
    if( len - 1 < i - 1 ){
      check( len - 1 , i - len );
      check( i - len , len - 1 );
    }
  }
  assert( false );
}
int main(){
  srand( time( 0 ) );
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
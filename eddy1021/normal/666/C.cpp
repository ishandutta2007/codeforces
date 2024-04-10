// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
// #define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
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
#define X 333
#define N 101010
int fac[ N ] , ifac[ N ] , ans[ X + 1 ][ N ] , pp[ N ] , pp2[ N ];
inline int C( int a , int b ){
  if( a < b ) return 0;
  return mul( fac[ a ] , mul( ifac[ b ] , ifac[ a - b ] ) );
}
void build(){
  pp2[ 0 ] = pp[ 0 ] = fac[ 0 ] = ifac[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ ){
    pp[ i ] = mul( pp[ i - 1 ] , 25 );
    pp2[ i ] = mul( pp2[ i - 1 ] , 26 );
    fac[ i ] = mul( fac[ i - 1 ] , i );
    ifac[ i ] = mypow( fac[ i ] , mod7 - 2 , mod7 );
  }
// ans[ N ][ M ] = sigma i = [0,M-1] C(N,i) * 25 ^ (N-i)
  for( int i = 0 ; i < X ; i ++ )
    for( int j = i ; j < N ; j ++ ){
      ans[ i ][ j ] = mul( C( j , i ) , pp[ j - i ] );
      if( i ) ans[ i ][ j ] = add( ans[ i ][ j ] , ans[ i - 1 ][ j ] );
    }
}
void go( int l ){
  if( l < X ) return;
  for( int i = l ; i < N ; i ++ ){
    ans[ X ][ i ] = mul( C( i - 1 , l - 1 ) , pp[ i - l ] );
    if( i > l ) ans[ X ][ i ] = add( ans[ X ][ i ] , mul( ans[ X ][ i - 1 ] , 26 ) );
  }
}
int cal( int xn , int xm ){
  if( xn < xm ) return 0;
  if( xm < X ) return sub( pp2[ xn ] , ans[ xm - 1 ][ xn ] );
  return ans[ X ][ xn ];
}
int m , l;
char c[ N ];
void init(){
  m = getint();
  scanf( "%s" , c );
  go( l = strlen( c ) );
}
void solve(){
  while( m -- ){
    int cmd = getint();
    if( cmd == 1 ){
      scanf( "%s" , c );
      go( l = strlen( c ) );
    }else{
      int n = getint();
      printf( "%d\n" , cal( n , l ) );
    }
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
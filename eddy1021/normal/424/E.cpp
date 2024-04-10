// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef unsigned long long ll;
typedef unsigned long long LL;
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
#define X FI
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
#define N 6
#define K 168
void build(){

}
int n;
char c[ N ][ N ];
typedef bitset<K> state;
inline int chg( char ctmp ){
  if( ctmp == 'R' ) return 1;
  if( ctmp == 'G' ) return 2;
  if( ctmp == 'B' ) return 3;
  return 0;
}
int er[ 3 ] = { 60 , 51 , 15 };
int s[ 1021 ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%s" , c[ i ] );
}
#define BS 5147
int vv[ 1021 ];
inline LL hsh( int lst ){
  for( int i = 0 ; i <= lst ; i ++ ){
    int i1 = s[ i ] & 3;
    int i2 = ( s[ i ] >> 2 ) & 3;
    int i3 = ( s[ i ] >> 4 ) & 3;
    if( i1 > i3 ) swap( i1 , i3 );
    vv[ i ] = ( i1 << 4 ) + ( i2 << 2 ) + i3;
  }
  sort( vv , vv + lst );
  LL thsh = 0;
  for( int i = 0 ; i <= lst ; i ++ )
    thsh = thsh * BS + vv[ i ];
  return thsh;
  return thsh * BS + lst;
}
const int P = 10215001;
struct Hash{
  int from[ P ] , nxt[ P ] , stmp;
  LL vl[ P ]; D res[ P ];
  Hash(){ stmp = 0; }
  D value( LL x ){
    for( int i = from[ x % P ] ; i ; i = nxt[ i ] )
      if( vl[ i ] == x )
        return res[ i ];
    return -1;
  }
  void add( LL x , D r ){
    if( value( x ) > -0.5 ) return;
    vl[ ++ stmp ] = x;
    res[ stmp ] = r;
    nxt[ stmp ] = from[ x % P ];
    from[ x % P ] = stmp;
  }
} dp;
const D pr[ 4 ] = { 1. / 6. , 1. / 6. , 2. / 6. , 2. / 6. };
D DP( int lst ){
  LL hsvl = hsh( lst );
  D tvl = dp.value( hsvl );
  if( tvl > -0.5 ) return tvl;
  D bst[ 4 ];
  for( int i = 0 ; i < 4 ; i ++ )
    bst[ i ] = 1e9;
  int xc[ 3 ] = {} , nxt = lst;
  for( int i = 0 ; i < 3 ; i ++ )
    xc[ i ] = ( s[ nxt ] >> ( i << 1 ) ) & 3;
  if( xc[ 0 ] > 0 && xc[ 1 ] > 0 && xc[ 2 ] > 0 ){
    nxt ++; xc[ 0 ] = xc[ 1 ] = xc[ 2 ] = 0;
  }
  for( int i = 0 ; i < lst ; i ++ ){
    int wc[ 3 ] = {} , sum = 0;
    for( int j = 0 ; j < 3 ; j ++ ){
      wc[ j ] = ( s[ i ] >> ( j << 1 ) ) & 3;
      if( wc[ j ] > 0 ) sum ++;
    }
    if( sum <= 1 ) continue;
    for( int j = 0 ; j < 3 ; j ++ ){
      int tc = wc[ j ];
      if( tc == 0 ) continue;
      if( sum == 2 && ( j == 1 || !wc[ 1 ] ) ) continue;
      int si = s[ i ];
      s[ i ] &= er[ j ];
      wc[ j ] = 0;
      if( sum == 2 || !wc[ 1 ] ) s[ i ] = 0;
      for( int k = 0 ; k < 3 ; k ++ )
        if( xc[ k ] == 0 ){
          s[ nxt ] |= tc << ( k << 1 );
          bst[ tc ] = min( bst[ tc ] , DP( nxt ) );      
          s[ nxt ] &= er[ k ];
        }
      s[ i ] = si;
      wc[ j ] = tc;
    }
  }
  D ans = 1.0 , kp = pr[ 0 ];
  for( int i = 1 ; i <= 3 ; i ++ )
    if( bst[ i ] < 1e9 ) 
      ans += bst[ i ] * pr[ i ];
    else kp += pr[ i ];
  if( kp > .99 ) ans = 0.0;
  else ans /= ( 1. - kp );
  dp.add( hsvl , ans );
  return ans;
}
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    int c1 = chg( c[ i ][ 0 ] );
    int c2 = chg( c[ i ][ 1 ] );
    int c3 = chg( c[ i ][ 2 ] );
    if( c1 > c3 ) swap( c1 , c3 );
    s[ i ] = ( c3 << 4 ) + ( c2 << 2 ) + c1;
  }
  printf( "%.12f\n" , DP( n - 1 ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
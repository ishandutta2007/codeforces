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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 222222
void build(){

}
ll n , x[ N ] , ps[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    x[ i ] = getint();
  sort( x , x + n );
  ps[ 0 ] = x[ 0 ];
  for( int i = 1 ; i < n ; i ++ )
    ps[ i ] = ps[ i - 1 ] + x[ i ];
}
inline ll sum( ll tl , ll tr ){
  if( tl == 0 ) return ps[ tr ];
  return ps[ tr ] - ps[ tl - 1 ];
}
void solve(){
  if( n < 3 ){
    printf( "%lld\n" , n );
    for( int i = 0 ; i < n ; i ++ )
      printf( "%lld%c" , x[ i ] , " \n"[ i == n - 1 ] );
    return;
  }
  ll ans = 0 , bst = -1 , bsts = -1 , an = 1;
  for( int i = 1 ; i < n - 1 ; i ++ ){
    ll l = 1 , r = min( i , (int)n - 1 - i ) , mid1 , mid2;
    while( l <= r - 4 ){
      mid1 = l + ( r - l ) / 3;
      mid2 = r - ( r - l ) / 3;
      ll ave = sum( i - mid1 , i - 1 ) + x[ i ] + sum( n - mid1 , n - 1 );
      ll all = mid1 + mid1 + 1;
      ll lans = ave - all * x[ i ];
      ll lansn = all;
      if( ave * an - an * all * x[ i ] > ans * all ){
        ans = ave - all * x[ i ];
        an = all;
        bst = i;
        bsts = mid1;
      }
      ave = sum( i - mid2 , i - 1 ) + x[ i ] + sum( n - mid2 , n - 1 );
      all = mid2 + mid2 + 1;
      ll rans = ave - all * x[ i ];
      ll ransn = all;
      if( ave * an - an * all * x[ i ] > ans * all ){
        ans = ave - all * x[ i ];
        an = all;
        bst = i;
        bsts = mid2;
      }
      if( lans * ransn > rans * lansn ) r = mid2;
      else l = mid1;
    }
    for( int j = l ; j <= r ; j ++ ){
      ll ave = sum( i - j , i - 1 ) + x[ i ] + sum( n - j , n - 1 );
      ll all = j + j + 1;
      if( ave * an - an * all * x[ i ] > ans * all ){
        ans = ave - all * x[ i ];
        an = all;
        bst = i;
        bsts = j;
      }
    }
  }
  if( bst == -1 )
    printf( "1\n%lld\n" , x[ 0 ] );
  else{
    printf( "%lld\n" , an );
    for( int i = 1 ; i <= bsts ; i ++ )
      printf( "%lld " , x[ bst - i ] );
    printf( "%lld " , x[ bst ] );
    for( int i = 1 ; i <= bsts ; i ++ )
      printf( "%lld " , x[ n - i ] );
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
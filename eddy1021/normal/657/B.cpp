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
#define N 404040
ll n , k , c[ N ] , a[ N ] , mx;
void build(){

}
inline void go( ll i , ll ai ){
  int sgn = 1;
  if( ai < 0 ) sgn = -1;
  ai = abs( ai );
  while( ai ){
    if( ai % 2 ) c[ i ] += sgn;
    ai /= 2;
    mx = max( mx , i );
    i ++;
  }
}
void init(){
  n = getint();
  k = getint();
  for( ll i = 0 ; i <= n ; i ++ ){
    a[ i ] = getint();
    go( i , a[ i ] );
  }
}
void solve(){
  for( int i = 0 ; i < mx ; i ++ )
    if( abs( c[ i ] ) > 1 ){
      ll sign = 1;
      if( c[ i ] < 0 ) sign = -1;
      c[ i + 1 ] += abs( c[ i ] ) / 2 * sign;
      c[ i ] = abs( c[ i ] ) % 2;
      c[ i ] *= sign;
    }
  while( abs( c[ mx ] ) > 1 ){
    ll sign = 1;
    if( c[ mx ] < 0 ) sign = -1;
    c[ mx + 1 ] += abs( c[ mx ] ) / 2 * sign;
    c[ mx ] = abs( c[ mx ] ) % 2;
    c[ mx ] *= sign;
    mx ++;
  }
  ll lft = mx , rgt = 0;
  for( ll i = 0 ; i <= mx ; i ++ )
    if( c[ i ] != 0 ){
      lft = min( lft , i );
      rgt = max( rgt , i );
    }
  int ans = 0;
  ll dif = 0;
  for( int i = rgt ; i > min( lft , n ) ; i -- ){
    dif *= 2;
    dif -= c[ i ];
    if( abs( dif ) >= k * 10 ){
      puts( "0" );
      exit( 0 );
    }
  }
  // cout << dif << endl;
  for( int i = min( lft , n ) ; i >= 0 ; i -- ){
    dif *= 2;
    dif -= c[ i ];
    if( abs( dif ) >= k * 10 ) break;
    // printf( "%d %lld %lld\n" , i , a[ i ] , dif );
    if( abs( a[ i ] + dif ) > k ) continue;
    if( i == n && a[ i ] + dif == 0 ) continue;
    // printf( "%d : %lld\n" , i , a[ i ] + dif );
    ans ++;
  }
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
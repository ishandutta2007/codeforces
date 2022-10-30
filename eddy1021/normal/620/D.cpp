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
#define N 2222
void build(){

}
ll n[ 2 ] , a[ 2 ][ N ] , sum[ 2 ];
void init(){
  for( int i = 0 ; i < 2 ; i ++ ){
    n[ i ] = getint();
    for( int j = 1 ; j <= n[ i ] ; j ++ ){
      a[ i ][ j ] = getint();
      sum[ i ] += a[ i ][ j ];
    }
  }
}
ll ans , sw , swa[ 9 ] , swb[ 9 ];
map<ll,int> M;
typedef map<ll,int>::iterator mi;
void solve(){
  ans = abs( sum[ 0 ] - sum[ 1 ] );
  for( int i = 1 ; i <= n[ 0 ] ; i ++ )
    for( int j = 1 ; j <= n[ 1 ] ; j ++ ){
      ll tans = abs( sum[ 0 ] - sum[ 1 ] + 2ll * ( a[ 1 ][ j ] - a[ 0 ][ i ] ) );
      if( tans < ans ){
        ans = tans; sw = 1;
        swa[ 0 ] = i;
        swb[ 0 ] = j;
      }
    }
  for( int i = 1 ; i <= n[ 0 ] ; i ++ )
    for( int j = i + 1 ; j <= n[ 0 ] ; j ++ )
      M[ 2ll * ( a[ 0 ][ i ] + a[ 0 ][ j ] ) ] = i * N + j;
  for( int i = 1 ; i <= n[ 1 ] ; i ++ )
    for( int j = i + 1 ; j <= n[ 1 ] ; j ++ ){
      ll tmp = sum[ 0 ] - sum[ 1 ] + 2ll * ( a[ 1 ][ i ] + a[ 1 ][ j ] );
      mi it = M.lower_bound( tmp );
      if( it != M.end() ){
        ll tans = abs( tmp - it->FI );
        if( tans < ans ){
          ans = tans; sw = 2;
          swa[ 0 ] = it->SE / N;
          swa[ 1 ] = it->SE % N;
          swb[ 0 ] = i;
          swb[ 1 ] = j;
        }
      }
      if( it != M.begin() ){
        it --;
        ll tans = abs( tmp - it->FI );
        if( tans < ans ){
          ans = tans; sw = 2;
          swa[ 0 ] = it->SE / N;
          swa[ 1 ] = it->SE % N;
          swb[ 0 ] = i;
          swb[ 1 ] = j;
        }
      }
    }
  printf( "%lld\n%lld\n" , ans , sw );
  for( int i = 0 ; i < sw ; i ++ )
    printf( "%lld %lld\n" , swa[ i ] , swb[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
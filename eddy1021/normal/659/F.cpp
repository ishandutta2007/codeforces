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
#define N 1021
ll n , m , k , a[ N ][ N ];
vector<ll> v;
void build(){

}
void init(){
  n = getint();
  m = getint();
  k = getint();
  for( ll i = 1 ; i <= n ; i ++ )
    for( ll j = 1 ; j <= m ; j ++ ){
      a[ i ][ j ] = getint();
      v.PB( a[ i ][ j ] );
    }
  sort( ALL( v ) );
}
bool got[ N ][ N ];
bool mk[ N ][ N ];
int dn[]={0,0,1,-1};
int dm[]={1,-1,0,0};
int cnt , bdr , nd;
inline bool in( int xi , int xj ){
  return 1 <= xi && xi <= n &&
         1 <= xj && xj <= m;
}
void DFS( int ni , int nj ){
  got[ ni ][ nj ] = true;
  cnt ++;
  for( int i = 0 ; i < 4 ; i ++ ){
    int nxti = ni + dn[ i ];
    int nxtj = nj + dm[ i ];
    if( in( nxti , nxtj ) &&
        !got[ nxti ][ nxtj ] &&
        a[ nxti ][ nxtj ] >= bdr )
      DFS( nxti , nxtj );
  }
}
void Mark( int ni , int nj ){
  if( nd <= 0 ) return;
  mk[ ni ][ nj ] = true;
  nd --;
  for( int i = 0 ; i < 4 ; i ++ ){
    int nxti = ni + dn[ i ];
    int nxtj = nj + dm[ i ];
    if( in( nxti , nxtj ) &&
        !mk[ nxti ][ nxtj ] &&
        a[ nxti ][ nxtj ] >= bdr )
      Mark( nxti , nxtj );
  }
}
void output(){
  puts( "YES" );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      if( mk[ i ][ j ] )
        printf( "%d%c" , bdr , " \n"[ j == m ] );
      else
        printf( "0%c" , " \n"[ j == m ] );
}
void test( ll xx ){
  if( k % xx ) return;
  if( upper_bound( ALL( v ) , k / xx ) ==
      lower_bound( ALL( v ) , k / xx ) ) return;
  if( ( v.end() - lower_bound( ALL( v ) , k / xx ) ) < xx ) return;
  bdr = k / xx;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      got[ i ][ j ] = false;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      if( !got[ i ][ j ] && a[ i ][ j ] == bdr ){
        cnt = 0;
        DFS( i , j );
        if( cnt >= xx ){
          nd = xx;
          Mark( i , j );
          output();
          exit( 0 );
        }
      }
}
void solve(){
  for( ll i = n * m ; i >= 1 ; i -- )
    test( i );
  puts( "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
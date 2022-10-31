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
ll n , m , alive , r[ N ] , c[ N ];
ll psuml[ N ][ N ] , psumu[ N ][ N ];
inline ll suml( int i , int j ){
  if( j < 0 ) return 0;
  return psuml[ i ][ j ];
}
inline ll sumr( int i , int j ){
  if( j > m ) return 0;
  return psuml[ i ][ m ] - psuml[ i ][ j - 1 ];
}
inline ll sumu( int i , int j ){
  if( i < 0 ) return 0;
  return psumu[ i ][ j ];
}
inline ll sumd( int i , int j ){
  if( i > n ) return 0;
  return psumu[ n ][ j ] - psumu[ i - 1 ][ j ];
}
char ch[ N ][ N ];
void build(){

}
ll total , rr[ N ] , cc[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , ch[ i ] + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      if( ch[ i ][ j ] == '.' ){
        alive ++;
        r[ i ] ++;
        c[ j ] ++;
        psuml[ i ][ j ] ++;
        psumu[ i ][ j ] ++;
      }else{
        rr[ i ] = j;
        cc[ j ] = i;
      }
      psuml[ i ][ j ] += psuml[ i ][ j - 1 ];
      psumu[ i ][ j ] += psumu[ i - 1 ][ j ];
    }
  for( ll i = 1 ; i <= m ; i ++ )
    for( ll j = 1 ; j <= m ; j ++ )
      total += c[ i ] * c[ j ] * abs( i - j );
  for( ll i = 1 ; i <= n ; i ++ )
    for( ll j = 1 ; j <= n ; j ++ )
      total += r[ i ] * r[ j ] * abs( i - j );
}
void solve(){
  for( ll i = 1 ; i <= n ; i ++ ){
    if( rr[ i ] == 0 ) continue;
    total += 4ll * ( rr[ i ] - 1 ) * ( m - rr[ i ] );
    for( ll j = i + 1 ; j <= n ; j ++ ){
      if( rr[ j ] == 0 || rr[ j ] < rr[ j - 1 ] ) break;
      total += 4ll * ( rr[ i ] - 1 ) * ( m - rr[ j ] );
    }
    for( ll j = i + 1 ; j <= n ; j ++ ){
      if( rr[ j ] == 0 || rr[ j ] > rr[ j - 1 ] ) break;
      total += 4ll * ( rr[ j ] - 1 ) * ( m - rr[ i ] );
    }
  }
  for( ll i = 1 ; i <= m ; i ++ ){
    if( cc[ i ] == 0 ) continue;
    total += 4ll * ( cc[ i ] - 1 ) * ( n - cc[ i ] );
    for( ll j = i + 1 ; j <= m ; j ++ ){
      if( cc[ j ] == 0 || cc[ j ] < cc[ j - 1 ] ) break;
      total += 4ll * ( cc[ i ] - 1 ) * ( n - cc[ j ] );
    }
    for( ll j = i + 1 ; j <= m ; j ++ ){
      if( cc[ j ] == 0 || cc[ j ] > cc[ j - 1 ] ) break;
      total += 4ll * ( cc[ j ] - 1 ) * ( n - cc[ i ] );
    }
  }
  D ans = (D)total / (D)alive / (D)alive;
  printf( "%.12f\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
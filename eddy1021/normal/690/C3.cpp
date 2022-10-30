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
#define N 202020
#define K 20
void build(){

}
int n , p[ N ][ K ] , dst[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < K ; i ++ )
    p[ 1 ][ i ] = 1;
  for( int i = 2 ; i <= n ; i ++ )
    p[ i ][ 0 ] = getint();
}
inline int lca( int a , int b ){
  if( dst[ a ] > dst[ b ] ) swap( a , b );
  int dlt = dst[ b ] - dst[ a ];
  for( int i = 0 ; i < K ; i ++ )
    if( ( dlt >> i ) & 1 )
      b = p[ b ][ i ];
  if( a == b ) return a;
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( p[ a ][ i ] != p[ b ][ i ] ){
      a = p[ a ][ i ];
      b = p[ b ][ i ];
    }
  return p[ a ][ 0 ];
}
inline int dist( int a , int b ){
  return dst[ a ] + dst[ b ] - 2 * dst[ lca( a , b ) ];
}
void solve(){
  int u = 1 , v = 1 , ans = 0;
  for( int i = 2 ; i <= n ; i ++ ){
    dst[ i ] = dst[ p[ i ][ 0 ] ] + 1;
    for( int j = 1 ; j < K ; j ++ )
      p[ i ][ j ] = p[ p[ i ][ j - 1 ] ][ j - 1 ];
    int tans1 = dist( u , i );
    int tans2 = dist( v , i );
    if( max( tans1 , tans2 ) > ans ){
      if( tans1 < tans2 ){
        swap( tans1 , tans2 );
        swap( u , v );
      }
      ans = tans1; v = i;
    }
    printf( "%d%c" , ans , " \n"[ i == n ] );
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
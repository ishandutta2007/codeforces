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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
#define K 20
void build(){

}
int n , q , p[ N ][ K ] , dep[ N ];
vector<int> v[ N ];
void init(){
  n = getint();
  q = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int pi = getint();
    v[ i + 1 ].push_back( pi );
    v[ pi ].push_back( i + 1 );
  }
}
void go( int now , int prt , int ndep ){
  p[ now ][ 0 ] = prt;
  dep[ now ] = ndep;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now , ndep + 1 );
  }
}
int lca( int ai , int bi ){
  if( dep[ ai ] > dep[ bi ] )
    swap( ai , bi );
  int dlt = dep[ bi ] - dep[ ai ];
  for( int i = 0 ; i < K ; i ++ )
    if( ( dlt >> i ) & 1 )
      bi = p[ bi ][ i ];
  if( ai == bi ) return ai;
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( p[ ai ][ i ] != p[ bi ][ i ] ){
      ai = p[ ai ][ i ];
      bi = p[ bi ][ i ];
    }
  return p[ ai ][ 0 ];
}
int dist( int a , int b , int c ){
  int lac = lca( a , c );
  int lab = lca( a , b );
  int lbc = lca( b , c );
  if( dep[ lab ] == dep[ lbc ] and dep[ lac ] > dep[ lab ] )
    return dep[ b ] - dep[ lab ] + dep[ lac ] - dep[ lab ] + 1;
  if( dep[ lab ] < dep[ lbc ] )
    return dep[ b ] - dep[ lbc ] + 1;
  return dep[ b ] - dep[ lab ] + 1;
}
void solve(){
  go( 1 , 1 , 0 );
  for( int j = 1 ; j < K ; j ++ )
    for( int i = 1 ; i <= n ; i ++ )
      p[ i ][ j ] = p[ p[ i ][ j - 1 ] ][ j - 1 ];
  while( q -- ){
    int ai = getint();
    int bi = getint();
    int ci = getint();
    int ans = max( dist( ai , bi , ci ) ,
                   max( dist( bi , ai , ci ) ,
                        dist( ai , ci , bi ) ) );
    printf( "%d\n" , ans );
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
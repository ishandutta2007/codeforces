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
void build(){

}
int p[ N ] , sz[ N ];
int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
void uni( int x , int y ){
  x = f( x );
  y = f( y );
  if( x == y ) return;
  p[ x ] = y;
  sz[ y ] += sz[ x ];
}
int n , m;
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    p[ i ] = i;
    sz[ i ] = 1;
  }
  while( m -- )
    uni( getint() , getint() );
}
int dp[ N ];
bool lucky( int x ){
  while( x ){
    if( x % 10 != 4 and
        x % 10 != 7 )
      return false;
    x /= 10;
  }
  return true;
}
void solve(){
  map<int,int> M;
  for( int i = 1 ; i <= n ; i ++ )
    if( i == f( i ) )
      M[ sz[ i ] ] ++;
  vector< pair<int,int> > vv;
  for( auto i : M ){
    int nsz = i.first;
    int nc = i.second;
    for( int j = 1 ; j <= nc ; j <<= 1 ){
      vv.push_back( { nsz * j , j } );
      nc -= j;
    }
    if( nc )
      vv.push_back( { nsz * nc , nc } );
  }
  for( int i = 1 ; i <= n ; i ++ )
    dp[ i ] = INF;
  for( auto j : vv ){
    int s = j.first , c = j.second;
    for( int k = n ; k >= s ; k -- )
      if( dp[ k - s ] < INF )
        dp[ k ] = min( dp[ k ] , dp[ k - s ] + c );
  }
  int ans = INF;
  for( int i = 1 ; i <= n ; i ++ )
    if( lucky( i ) )
      ans = min( ans , dp[ i ] );
  if( ans > n ) ans = 0;
  cout << ans - 1 << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
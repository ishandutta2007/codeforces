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
#define N 1021
void build(){

}
vector<int> v[ N ];
int n , p[ N ];
LL x[ N ] , y[ N ] , r[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
    r[ i ] = getint();
  }
}
inline LL sqr( LL _ ){ return _ * _; }
bool in( int i , int j ){
  if( r[ i ] >= r[ j ] ) return false;
  return sqr( x[ i ] - x[ j ] ) + sqr( y[ i ] - y[ j ] ) <=
         sqr( r[ j ] - r[ i ] );
}
LL ans;
void go( int now , int dep ){
  if( dep == 0 or dep % 2 )
    ans += r[ now ] * r[ now ];
  else
    ans -= r[ now ] * r[ now ];
  for( int son : v[ now ] )
    go( son , dep + 1 );
}
const double PI = acos( -1.0 );
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    for( int j = 1 ; j <= n ; j ++ ){
      if( i == j ) continue;
      if( in( i , j ) ){
        if( p[ i ] == 0 ) p[ i ] = j;
        else if( r[ j ] < r[ p[ i ] ] )
          p[ i ] = j;
      }
    }
    v[ p[ i ] ].push_back( i );
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( p[ i ] == 0 )
      go( i , 0 );
  printf( "%.12f\n" , ans * PI );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
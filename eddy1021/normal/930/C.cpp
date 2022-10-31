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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
int BIT[ N ];
int lb( int x ){ return x & (-x); }
void reset(){
  for( int i = 0 ; i < N ; i ++ )
    BIT[ i ] = 0;
}
void modify( int x , int v ){
  for( int i = x ; i < N ; i += lb( i ) )
    BIT[ i ] = max( BIT[ i ] , v );
}
int query( int x ){
  int ret = 0;
  for( int i = x ; i ; i -= lb( i ) )
    ret = max( ret , BIT[ i ] );
  return ret;
}
int n , m , a[ N ];
void init(){
  n = getint();
  m = getint();
  while( n -- ){
    int li = getint();
    int ri = getint();
    a[ li     ] ++;
    a[ ri + 1 ] --;
  }
  n = m;
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] += a[ i - 1 ];
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] ++;
}
int dpl[ N ] , ans;
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    int ret = query( a[ i ] );
    dpl[ i ] = ret + 1;
    modify( a[ i ] , ret + 1 );
  }
  reset();
  ans = dpl[ n ];
  for( int i = n ; i >= 1 ; i -- ){
    int ret = query( a[ i ] );
    int dpr = ret + 1;
    ans = max( ans , dpr + dpl[ i - 1 ] );
    modify( a[ i ] , ret + 1 );
  }
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
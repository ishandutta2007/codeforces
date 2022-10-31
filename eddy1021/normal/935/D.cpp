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
int inv[ N ];
void build(){
  inv[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    inv[ i ] = mypow( i , mod7 - 2 , mod7 );
}
int n , m , a[ 2 ][ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < 2 ; i ++ ){
    for( int j = 0 ; j < n ; j ++ )
      a[ i ][ j ] = getint();
  }
}
int inv2 = (mod7 + 1) / 2;
void solve(){
  int ans = 0 , same = 1;
  for( int i = 0 ; i < n ; i ++ ){
    if( a[ 0 ][ i ] and a[ 1 ][ i ] ){
      if( a[ 0 ][ i ] < a[ 1 ][ i ] ) break;
      if( a[ 0 ][ i ] > a[ 1 ][ i ] ){
        ans = add( ans , same );
        break;
      }
      continue;
    }
    if( a[ 0 ][ i ] ){
      int smaller = mul( a[ 0 ][ i ] - 1 , inv[ m ] );
      ans = add( ans , mul( smaller , same ) );
      same = mul( same , inv[ m ] );
      continue;
    }
    if( a[ 1 ][ i ] ){
      int larger = mul( m - a[ 1 ][ i ] , inv[ m ] );
      ans = add( ans , mul( larger , same ) );
      same = mul( same , inv[ m ] );
      continue;
    }
    // 0 + ... + m - 1
    // (m - 1) * m / 2
    ans = add( ans , mul( same ,
                          mul( mul( mul( m - 1 , m ) , inv2 ) , mul( inv[ m ] , inv[ m ] ) ) ) );
    same = mul( same , inv[ m ] );
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
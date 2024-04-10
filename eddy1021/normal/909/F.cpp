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
void build(){

}
#define N 101010
int n;
clock_t s;
void init(){
  s = clock();
  n = getint();
}
int p[ N ] , q[ N ];
bool build_p( int _n ){
  if( _n & 1 ) return false;
  if( _n == 0 ) return true;
  int two = 1;
  while( two < _n ) two <<= 1;
  if( two == _n ){
    p[ _n ] = _n - 1;
    p[ _n - 1 ] = _n;
    return build_p( _n - 2 );
  }
  int nd = two - 1 - _n;
  for( int i = nd ; i <= _n ; i ++ ){
    p[ i ] = two - 1 - i;
    assert( p[ i ] != i );
  }
  return build_p( nd - 1 );
}
bool check_p(){
  for( int i = 1 ; i <= n ; i ++ )
    if( (p[ i ] & i) or p[ i ] == i )
      return false;
  return true;
}
bool check_q(){
  for( int i = 1 ; i <= n ; i ++ )
    if( (!(q[ i ] & i )) or q[ i ] == i )
      return false;
  return true;
}
bool find_p(){
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i;
  //clock_t s = clock();
  //while( (clock() - s) < 0.9 * CLOCKS_PER_SEC ){
    //random_shuffle( p + 1 , p + n + 1 );
  do{
    if( check_p() )
      return true;
  }while( next_permutation( p + 1 , p + n + 1 ) );
  //}
  return false;
}
bool find_q(){
  for( int i = 1 ; i <= n ; i ++ )
    q[ i ] = i;
  //while( (clock() - s) < 1.9 * CLOCKS_PER_SEC ){
    //random_shuffle( q + 1 , q + n + 1 );
  do{
    if( check_q() )
      return true;
  }while( next_permutation( q + 1 , q + n + 1 ) );
  //}
  return false;
}
bool build_q(){
  if( n <= 9 ) return find_q();
  for( int i = 1 ; i <= n ; i ++ )
    q[ i ] = i;
  if( n & 1 ){
    q[ 1 ] = 3;
    q[ 2 ] = 6;
    q[ 3 ] = 1;
    q[ 4 ] = 5;
    q[ 5 ] = 4;
    q[ 6 ] = 2;
    bool ok = false;
    for( int i = 8 ; i <= n ; i += 2 ){
      if( not ok and (7 & i) ){
        q[ 7 ] = i;
        q[ i ] = i + 1;
        q[ i + 1 ] = 7;
        ok = true;
        continue;
      }
      q[ i ] = i + 1;
      q[ i + 1 ] = i;
    }
    return ok;
  }else{
    for( int i = 1 ; i <= n ; i += 6 ){
      int l = i , r = min( i + 6 , n + 1 );
      bool nice = false;
      do{
        bool ok = true;
        for( int j = l ; j < r ; j ++ )
          if( q[ j ] == j or (q[ j ] & j) == 0 )
            ok = false;
        if( ok ){
          nice = true;
          break;
        }
      }while( next_permutation( q + l , q + r ) );
      if( not nice ) return false;
    }
    return true;
  }
  return find_q();
}
void solve(){
  if( build_p( n ) ){
    assert( check_p() );
    puts( "YES" );
    for( int i = 1 ; i <= n ; i ++ )
      printf( "%d%c" , p[ i ] , " \n"[ i == n ] );
  }else
    puts( "NO" );
  if( build_q() ){
    assert( check_q() );
    puts( "YES" );
    for( int i = 1 ; i <= n ; i ++ )
      printf( "%d%c" , q[ i ] , " \n"[ i == n ] );
  }else
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
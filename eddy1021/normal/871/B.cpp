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
#define N 5050
void build(){

}
int n;
inline int ask( int i , int j ){
  printf( "? %d %d\n" , i , j );
  fflush( stdout );
  int ret; scanf( "%d" , &ret );
  return ret;
}
void init(){
  n = getint();
}
int pb[ N ] , pp[ N ];
int ans , p[ N ] , gt[ N ] , stmp , b[ N ];
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    pb[ i ] = ask( i , i );
    pp[ i ] = pb[ i ] ^ ask( ( i + 1 ) % n , i );
  }
  int ai = 0;
  for( int i = 0 ; i < n ; i ++ ){
    p[ 0 ] = i;
    for( int j = 0 ; j + 1 < n ; j ++ )
      p[ j + 1 ] = p[ j ] ^ pp[ j ];
    for( int j = 0 ; j < n ; j ++ )
      b[ j ] = p[ j ] ^ pb[ j ];
    bool ok = true;
    ++ stmp;
    for( int j = 0 ; j < n and ok ; j ++ )
      if( gt[ p[ j ] ] == stmp )
        ok = false;
      else
        gt[ p[ j ] ] = stmp;
    if( not ok ) continue;
    ++ stmp;
    for( int j = 0 ; j < n and ok ; j ++ )
      if( gt[ b[ j ] ] == stmp )
        ok = false;
      else
        gt[ b[ j ] ] = stmp;
    if( not ok ) continue;
    for( int j = 0 ; j < n and ok ; j ++ )
      if( p[ b[ j ] ] != j )
        ok = false;
    if( not ok ) continue;
    ans ++;
    ai = i;
  }
  p[ 0 ] = ai;
  for( int j = 0 ; j + 1 < n ; j ++ )
    p[ j + 1 ] = p[ j ] ^ pp[ j ];
  puts( "!" );
  printf( "%d\n" , ans );
  for( int i = 0 ; i < n ; i ++ )
    printf( "%d%c" , p[ i ] , " \n"[ i + 1 == n ] );
  fflush( stdout );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
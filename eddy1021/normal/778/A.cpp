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
#define N 202020
void build(){

}
char p[ N ] , t[ N ];
int a[ N ] , n , m;
bool bye[ N ];
void init(){
  scanf( "%s" , p + 1 );
  scanf( "%s" , t + 1 );
  n = strlen( p + 1 );
  m = strlen( t + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
}
bool okay( int xx ){
  for( int i = 1 ; i <= n ; i ++ )
    bye[ i ] = false;
  for( int i = 1 ; i <= xx ; i ++ )
    bye[ a[ i ] ] = true;
  int nxt = 1 , got = 0;
  while( got < m ){
    while( nxt <= n and ( bye[ nxt ] or p[ nxt ] != t[ got + 1 ] ) )
      nxt ++;
    if( nxt > n ) break;
    nxt ++;
    got ++;
  }
  return got >= m;
}
void solve(){
  int bl = 0 , br = n , ba = 0;
  while( bl <= br ){
    int mid = ( bl + br ) >> 1;
    if( okay( mid ) ) ba = mid , bl = mid + 1;
    else br = mid - 1;
  }
  printf( "%d\n" , ba );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
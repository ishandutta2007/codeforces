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
int k[ 3 ];
void init(){
  for( int i = 0 ; i < 3 ; i ++ )
    k[ i ] = getint();
}
int ind[ 3 ];
int lcm( int ai , int bi ){
  return ai / __gcd( ai , bi ) * bi;
}
bitset<5000000> tg;
void yes(){
  puts( "YES" );
  Bye;
}
void check(){
  int til = lcm( k[ 0 ] , k[ 1 ] ) * 2;
  tg.reset();
  for( int i = 0 ; i < til ; i += k[ 0 ] )
    tg[ i ] = true;
  int st = 0;
  while( st < til and tg[ st ] ) st ++;
  if( st == til ) yes();
  for( int i = st ; i < til ; i += k[ 1 ] )
    tg[ i ] = true;
  st = 0;
  while( st < til and tg[ st ] ) st ++;
  if( st == til ) yes();
  if( ( til / 2 ) % k[ 2 ] ) return;
  for( int i = st ; i < til ; i ++ ){
    if( tg[ i ] ) continue;
    if( (i - st) % k[ 2 ] )
      return;
  }
  yes();
}
void solve(){
  sort( k , k + 3 );
  do check();  
  while( next_permutation( k , k + 3 ) );
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
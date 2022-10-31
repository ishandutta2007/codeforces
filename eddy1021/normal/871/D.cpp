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
#define N 10000001
int BIT[ N ] , lb[ N ];
void build(){
  for( int i = 1 ; i < N ; i ++ )
    lb[ i ] = i & (-i);
}
inline void modify( int x ){
  for( int i = x ; i < N ; i += lb[ i ] )
    BIT[ i ] ++;
}
inline int query( int x ){
  int ret = 0;
  for( int i = x ; i ; i -= lb[ i ] )
    ret += BIT[ i ];
  return ret;
}
int n , mnp[ N ] , res , phi[ N ];
LL ans , tans[ N ];
LL C2( LL x ){
  return x * ( x - 1 ) / 2;
}
int can;
void init(){
  res = n = getint();
  for( int i = 2 ; i <= n ; i ++ ) phi[ i ] = i;
  for( int i = 2 ; i <= n ; i ++ ) if( !mnp[ i ] )
    for( int j = i ; j <= n ; j += i ){
      if( !mnp[ j ] )
        mnp[ j ] = i;
      phi[ j ] = ( phi[ j ] / i ) * ( i - 1 );
    }
  for( int i = 2 ; i <= n ; i ++ )
    if( mnp[ i ] * 2 <= n )
      can ++;
  for( int i = 2 ; i <= n ; i ++ )
    ans += ( i - phi[ i ] - 1 );
}
inline int cost( int i , int j ){
  if( __gcd( i , j ) > 1 ) return 1;
  else if( (LL)mnp[ i ] * (LL)mnp[ j ] <= n )
    return 2;
  return 0;
}
void solve(){
  LL all = C2( can );
  LL tmp = 0;
  for( int i = 2 ; i <= n ; i ++ ){
    tmp += query( n / mnp[ i ] );
    modify( mnp[ i ] );
  }
  ans = all * 3 - tmp - ans;
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
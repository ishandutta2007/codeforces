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
#define N 201010
int fac[ N ] , ifac[ N ];
void build(){
  fac[ 0 ] = ifac[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    ifac[ i ] = mypow( fac[ i ] , mod7 - 2 , mod7 );
  }
}
inline int C( int a , int b ){
  return mul( fac[ a ] , mul( ifac[ b ] , ifac[ a - b ] ) );
}
int n , x[ N ] , y[ N ] , ix , iy;
map<int,int> mx , my;
vector<int> vx[ N ] , vy[ N ];
inline int id( map<int,int>& mm , int vl , int& ii ){
  auto it = mm.find( vl );
  if( it != mm.end() ) return it->second;
  return mm[ vl ] = ii ++;
}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
    int idx = id( mx , x[ i ] , ix );
    int idy = id( my , y[ i ] , iy );
    vx[ idx ].push_back( i );
    vy[ idy ].push_back( i );
  }
}
int ans , got;
bool tg[ N ];
set<int> sx , sy;
void go( int now ){
  sx.clear();
  sy.clear();
  got = 0;
  queue<int> Q;
  Q.push( now );
  tg[ now ] = true;
  sx.insert( x[ now ] );
  sy.insert( y[ now ] );
  got ++;
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    int idx = id( mx , x[ tn ] , ix );
    int idy = id( my , y[ tn ] , iy );
    for( auto nxt : vx[ idx ] ){
      if( tg[ nxt ] ) continue;
      Q.push( nxt );
      tg[ nxt ] = true;
      sx.insert( x[ nxt ] );
      sy.insert( y[ nxt ] );
      got ++;
    }
    vx[ idx ].clear();
    for( auto nxt : vy[ idy ] ){
      if( tg[ nxt ] ) continue;
      Q.push( nxt );
      tg[ nxt ] = true;
      sx.insert( x[ nxt ] );
      sy.insert( y[ nxt ] );
      got ++;
    }
    vy[ idy ].clear();
  }
}
void solve(){
  ans = 1;
  for( int i = 0 ; i < n ; i ++ ){
    if( tg[ i ] ) continue;
    go( i );
    int line = (int)sx.size() + (int)sy.size();
    int tans = 0;
    for( int j = 0 ; j <= min( got , line ) ; j ++ )
      tans = add( tans , C( line , j ) );
    ans = mul( ans , tans );
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
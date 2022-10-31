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
#define N 1000001
vector<int> pd[ N ];
int bt[ 1024 ] , ii[ 1024 ];
void build(){
  for( int i = 2 ; i < N ; i ++ ) if( pd[ i ].empty() )
    for( int j = i ; j < N ; j += i )
      pd[ j ].push_back( i );
  for( int i = 1 ; i < (1 << 10) ; i ++ ){
    bt[ i ] = bt[ i >> 1 ] + (i & 1);
    ii[ i ] = __lg( i & (-i) );
  }
}
LL x , p , k;
void init(){
  x = getint();
  p = getint();
  k = getint();
}
LL vl[ 1024 ];
inline LL count( LL v ){
  int sz = (int)pd[ p ].size();
  LL ret = v;
  vl[ 0 ] = 1;
  for( int i = 1 ; i < (1 << sz) ; i ++ ){
    int now = ii[ i ];
    vl[ i ] = vl[ i ^ (1 << now) ] * pd[ p ][ now ];
    if( bt[ i ] & 1 )
      ret -= (v / vl[ i ]);
    else
      ret += (v / vl[ i ]);
  }
  return ret;
}
void solve(){
  if( p == 1 ){
    printf( "%lld\n" , x + k );
    return;
  }
  LL bl = x + 1 , br = INF16 , ba = bl;
  LL dlt = count( x );
  while( bl <= br ){
    LL bmid = (bl + br) >> 1;
    if( count( bmid ) - dlt >= k )
      ba = bmid , br = bmid - 1;
    else
      bl = bmid + 1;
  }
  printf( "%lld\n" , ba );

}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
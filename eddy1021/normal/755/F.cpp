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
#define N 1010101
void build(){
}
int n , k , p[ N ];
void init(){
  n = getint();
  k = getint();
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = getint();
}
vector<int> v;
bool g[ N ];
int go( int now ){
  int sz = 0;
  while( !g[ now ] ){
    g[ now ] = true;
    sz ++;
    now = p[ now ];
  }
  return sz;
}
bool ok[ N ];
int cnt[ N ];
int q[ N ] , qt;
inline void upd( int sz ){
  int sqt = qt;
  for( int i = 0 ; i < sqt ; i ++ )
    if( !ok[ q[ i ] + sz ] ){
      ok[ q[ i ] + sz ] = true;
      if( q[ i ] + sz > k ) continue;
      q[ qt ++ ] = q[ i ] + sz;
    }
}
inline int find_min(){
  int sk = k;
  if( n - k < k ) k = n - k;
  for( int x : v )
    cnt[ x ] ++;
  ok[ 0 ] = true;
  q[ qt ++ ] = 0;
  for( int i = 2 ; i <= k ; i ++ ){
    if( cnt[ i ] == 0 ) continue;
    int num = cnt[ i ];
    cnt[ i ] = 0;
    for( int j = 1 ; j <= num ; j = j + j ){
      cnt[ i * j ] ++;
      num -= j;
    }
    if( num ) cnt[ i * num ] ++;
    while( cnt[ i ] -- ) upd( i );
    if( ok[ k ] ) return sk;
  }
  if( ok[ k ] ) return sk;
  return sk + 1;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( !g[ i ] )
      v.push_back( go( i ) );
  //sort( v.begin() , v.end() );
  int mx = 0 , tk = k;
  for( auto i : v ){
    if( tk == 0 ) break;
    int nd = min( tk , i / 2 );
    tk -= nd; mx += nd + nd;
  }
  for( auto i : v ){
    if( tk == 0 ) break;
    if( i % 2 ){
      tk --;
      mx ++;
    }
  }
  printf( "%d %d\n" , find_min() , mx );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
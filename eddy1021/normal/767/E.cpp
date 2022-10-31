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
void build(){

}
#define N 101010
LL n , m , c[ N ] , w[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ )
    c[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    w[ i ] = getint();
}
bool got[ N ];
void solve(){
  priority_queue< pair<LL,int> ,
    vector< pair<LL,int> > ,
    greater< pair<LL,int> > > heap;
  for( int i = 0 ; i < n ; i ++ ){
    LL nd = c[ i ] % 100;
    LL res = ( 100 - nd ) % 100 * w[ i ];
    if( nd <= m ){
      m -= nd;
      if( nd )
        heap.push( { res , i } );
    }else{
      if( heap.size() and res > heap.top().first ){
        heap.pop();
        m = m + 100 - nd;
        heap.push( { res , i } );
      }else{
        m += ( 100 - nd ) % 100;
      }
    }
  }
  while( heap.size() ){
    got[ heap.top().second ] = true;
    heap.pop();
  }
  LL cst = 0;
  for( int i = 0 ; i < n ; i ++ )
    if( !got[ i ] )
      cst += ( 100 - c[ i ] % 100 ) % 100 * w[ i ];
  printf( "%lld\n" , cst );
  for( int i = 0 ; i < n ; i ++ )
    if( got[ i ] )
      printf( "%lld %lld\n" , c[ i ] / 100 , c[ i ] % 100 );
    else
      printf( "%lld 0\n" , c[ i ] / 100 + ( c[ i ] % 100 != 0 ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
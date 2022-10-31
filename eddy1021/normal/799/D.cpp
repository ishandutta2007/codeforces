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
#define INF16 10000000000000LL
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
#define N 101010
void build(){

}
LL a , b , h , w , n;
vector<LL> v;
void init(){
  a = getint();
  b = getint();
  h = getint();
  w = getint();
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    v.push_back( getint() );
  sort( v.begin() , v.end() );
  reverse( v.begin() , v.end() );
  v.resize( min( n , 40LL ) );
}
int ans = -1;
LL bst[ N ];
#define BDR 10000000000000000LL
int cal(){
  if( a <= h and b <= w ) return 0;
  LL tar1 = a / h;
  while( h * tar1 < a ) tar1 ++;
  LL tar2 = b / w;
  while( w * tar2 < b ) tar2 ++;
  for( int i = 1 ; i < N ; i ++ )
    bst[ i ] = INF16;
  bst[ 1 ] = 1;
  LL pr = 1;
  bool out = false;
  for( size_t j = 0 ; j < v.size() ; j ++ ){
    if( v[ j ] > BDR / pr ) out = true;
    pr *= v[ j ];
    for( LL i = N - 1 ; i >= 1 ; i -- ){
      if( bst[ i ] == INF16 ) continue;
      LL tmp = i * v[ j ];
      int at = min( tmp , (LL)N - 1 );
      bst[ at ] = min( bst[ at ] , tmp );
    }
    for( int i = tar1 ; i < N ; i ++ ){
      if( bst[ i ] == INF16 ) continue;
      LL res = pr / bst[ i ];
      if( out or res >= tar2 )
        return j + 1;
    }
  }
  return -1;
}
void solve(){
  for( int _ = 0 ; _ < 2 ; _ ++ ){
    int ret = cal();
    if( ret != -1 ){
      if( ans == -1 or ret < ans )
        ans = ret;
    }
    swap( a , b );
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
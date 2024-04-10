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
#define N 505050
void build(){

}
int n , nxt[ N ][ 26 ];
void init(){
  n = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int pi = getint();
    int ni = getint();
    char ci[ 9 ]; scanf( "%s" , ci );
    nxt[ pi ][ ci[ 0 ] - 'a' ] = ni;
  }
}
int bst , ba , cnt[ N ] , sz[ N ];
int go2( const vector<int>& v ){
  if( v.empty() ) return 0;
  if( v.size() == 1u ) return sz[ v[ 0 ] ];
  int tcnt = 1;
  for( int i = 0 ; i < 26 ; i ++ ){
    vector<int> son;
    for( auto id : v )
      if( nxt[ id ][ i ] )
        son.push_back( nxt[ id ][ i ] );
    tcnt += go2( son );
  }
  return tcnt;
}
int mxdep;
int go( int now , int dep ){
  vector<int> son;
  int tcnt = 1;
  for( int i = 0 ; i < 26 ; i ++ )
    if( nxt[ now ][ i ] ){
      tcnt += go( nxt[ now ][ i ] , dep + 1 );
      son.push_back( nxt[ now ][ i ] );
    }
  cnt[ dep ] += tcnt - go2( son );
  if( son.empty() ) cnt[ dep ] --;
  else mxdep = max( mxdep , dep );
  sz[ now ] = tcnt;
  return tcnt;
}
void solve(){
  bst = N; ba = -1;
  assert( go( 1 , 1 ) == n );
  for( int i = 1 ; i <= mxdep ; i ++ )
    if( cnt[ i ] > ba )
      ba = cnt[ i ] , bst = i;
  assert( 1 <= n - ba and n - ba < n );
  printf( "%d\n%d\n" , n - ba , bst );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
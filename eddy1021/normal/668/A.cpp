// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 11111
void build(){

}
int a[ 111 ][ 111 ] , n , m , q;
int cmd[ N ] , x[ N ][ 3 ];
void init(){
  n = getint(); m = getint(); q = getint();
  for( int i = 1 ; i <= q ; i ++ ){
    cmd[ i ] = getint();
    x[ i ][ 0 ] = getint();
    if( cmd[ i ] == 3 ){
      for( int j = 1 ; j <= 2 ; j ++ )
        x[ i ][ j ] = getint();
    }
    x[ i ][ 0 ] --;
    x[ i ][ 1 ] --;
  }
}
void solve(){
  for( int i = q ; i >= 1 ; i -- )
    if( cmd[ i ] == 3 )
      a[ x[ i ][ 0 ] ][ x[ i ][ 1 ] ] = x[ i ][ 2 ];
    else if( cmd[ i ] == 2 ){  
      int tmp = a[ n - 1 ][ x[ i ][ 0 ] ];
      for( int k = n - 1 ; k > 0 ; k -- )
        a[ k ][ x[ i ][ 0 ] ] = a[ k - 1 ][ x[ i ][ 0 ] ];
      a[ 0 ][ x[ i ][ 0 ] ] = tmp;
    }else{
      int tmp = a[ x[ i ][ 0 ] ][ m - 1 ];
      for( int k = m - 1 ; k > 0 ; k -- )
        a[ x[ i ][ 0 ] ][ k ] = a[ x[ i ][ 0 ] ][ k - 1 ];
      a[ x[ i ][ 0 ] ][ 0 ] = tmp;
    }
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      printf( "%d%c" , a[ i ][ j ] , " \n"[ j + 1 == m ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
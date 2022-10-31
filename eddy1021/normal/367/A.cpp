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
#define N 101010
char c[ N ];
int q , l , r , len;
int sx[ N ] , sy[ N ] , sz[ N ];
void build(){

}
void init(){
  scanf( "%s" , c + 1 );
  len = strlen( c + 1 );
  for( int i = 1 ; i <= len ; i ++ ){
    sx[ i ] = sx[ i - 1 ] + ( c[ i ] == 'x' );
    sy[ i ] = sy[ i - 1 ] + ( c[ i ] == 'y' );
    sz[ i ] = sz[ i - 1 ] + ( c[ i ] == 'z' );
  }
}
void solve(){
  scanf( "%d" , &q ); while( q -- ){
    scanf( "%d%d" , &l , &r );
    int x = sx[ r ] - sx[ l - 1 ];
    int y = sy[ r ] - sy[ l - 1 ];
    int z = sz[ r ] - sz[ l - 1 ];
    if( ( x == y && y == z ) ||
        ( x == z && z == y + 1 ) ||
        ( x == z + 1 && z == y ) ||
        ( z == y && y == x + 1 ) ||
        ( z == y + 1 && y == x ) ||
        ( y == x && x == z + 1 ) ||
        ( y == x + 1 && x == z ) ||
        r - l <= 1 )
      puts( "YES" );
    else
      puts( "NO" );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
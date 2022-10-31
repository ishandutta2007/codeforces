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
#define N 514
int n , k , p[ N * N ] , sz[ N * N ];
char c[ N ][ N ];
inline int h( int xi , int yi ){
  return xi * n + yi;
}
inline void init_p(){
  for( int i = 0 ; i < n * n ; i ++ )
    p[ i ] = i , sz[ i ] = 1;
}
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
inline void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x == y ) return;
  p[ x ] = y;
  sz[ y ] += sz[ x ];
}
void build(){

}
void init(){
  n = getint(); k = getint();
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%s" , c[ i ] );
  init_p();
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ ){
      if( c[ i ][ j ] == 'X' ) continue;
      if( c[ i + 1 ][ j ] == '.' )
        Union( h( i , j ) , h( i + 1 , j ) );
      if( c[ i ][ j + 1 ] == '.' )
        Union( h( i , j ) , h( i , j + 1 ) );
    }
}
int ans , tans;
bool tag[ N * N ];
inline bool in( int xi , int yi ){
  return 0 <= xi && xi < n &&
         0 <= yi && yi < n;
}
inline void add( int xi , int yi ){
  if( !in( xi , yi ) || c[ xi ][ yi ] == 'X' ) return;
  if( !tag[ find_p( h( xi , yi ) ) ] ){
    tans += sz[ find_p( h( xi , yi ) ) ];
    tag[ find_p( h( xi , yi ) ) ] = true;
  }
}
inline void clr( int xi , int yi ){
  if( !in( xi , yi ) || c[ xi ][ yi ] == 'X' ) return;
  tag[ find_p( h( xi , yi ) ) ] = false;
}
inline void cal( int ux , int dx , int ly , int ry ){
  tans = 0;
  for( int i = ux ; i <= dx ; i ++ ){
    add( i , ly - 1 );
    add( i , ry + 1 );
  }
  for( int j = ly ; j <= ry ; j ++ ){
    add( ux - 1 , j );
    add( dx + 1 , j );
  }
  ans = max( ans , tans + k * k );
  for( int i = ux ; i <= dx ; i ++ ){
    clr( i , ly - 1 );
    clr( i , ry + 1 );
  }
  for( int j = ly ; j <= ry ; j ++ ){
    clr( ux - 1 , j );
    clr( dx + 1 , j );
  }
}
inline void go( int ux , int dx ){
  for( int i = ux ; i <= dx ; i ++ )
    for( int j = 0 ; j < k ; j ++ )
      sz[ find_p( h( i , j ) ) ] --;
  cal( ux , dx , 0 , k - 1 );
  for( int j = k ; j < n ; j ++ ){
    for( int i = ux ; i <= dx ; i ++ ){
      sz[ find_p( h( i , j - k ) ) ] ++;
      sz[ find_p( h( i , j     ) ) ] --;
    }
    cal( ux , dx , j - k + 1 , j );
  }
  for( int i = ux ; i <= dx ; i ++ )
    for( int j = n - k ; j < n ; j ++ )
      sz[ find_p( h( i , j ) ) ] ++;
}
void solve(){
  ans = k * k;
  for( int u = 0 ; u + k - 1 < n ; u ++ )
    go( u , u + k - 1 );
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
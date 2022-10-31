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
#define N 50
int n , m;
char c[ N ][ N ];
void build(){
  
}
bool got[ N ][ N ][ N ][ N ];
int gd[ N ][ N ][ N ][ N ];
void init(){
  n = getint(); m = getint();
  for( int i = 0 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] );
}
inline PII trans( int mi , int su ){
  if( ( mi + su ) % 2 ) return MP( -1 , -1 );
  if( ( su - mi ) % 2 ) return MP( -1 , -1 );
  return MP( ( mi + su ) / 2 , ( su - mi ) / 2 );
}
int DP( int u , int d , int l , int r , int pt ){
  if( got[ u + m ][ d ][ l ][ r ] )
    return gd[ u + m ][ d ][ l ][ r ];
  got[ u + m ][ d ][ l ][ r ] = true;
  set<int> S;
  for( int i = u ; i <= d ; i ++ )
    for( int j = l ; j <= r ; j ++ ){
      if( j % 2 != pt % 2 ) continue;
      PII tp = trans( i , j );
      int xn = tp.FI , xm = tp.SE;
      if( xn < 0 || xn >= n || xm < 0 || xm >= m ) continue;
      if( c[ xn ][ xm ] == 'L' )
        S.insert( DP( u , d , l , j - 1 , pt ) ^ DP( u , d , j + 1 , r , pt ) );
      else if( c[ xn ][ xm ] == 'R' )
        S.insert( DP( u , i - 1 , l , r , pt ) ^ DP( i + 1 , d , l , r , pt ) );
      else
        S.insert( DP( u , i - 1 , l , j - 1 , pt ) ^ DP( u , i - 1 , j + 1 , r , pt ) ^
                  DP( i + 1 , d , l , j - 1 , pt ) ^ DP( i + 1 , d , j + 1 , r , pt ) );
    }
  int xx = 0;
  while( S.count( xx ) ) xx ++;
  return gd[ u + m ][ d ][ l ][ r ] = xx;
}
int SG( int pt ){
  for( int i = 0 ; i < N ; i ++ )
    for( int j = 0 ; j < N ; j ++ )
      for( int i2 = 0 ; i2 < N ; i2 ++ )
        for( int j2 = 0 ; j2 < N ; j2 ++ )
          got[ i ][ j ][ i2 ][ j2 ] = false;
  return DP( - m + 1 , n - 1 , 0 , n + m - 2 , pt );
}
void solve(){
  puts( SG( 0 ) == SG( 1 ) ? "LOSE" : "WIN" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
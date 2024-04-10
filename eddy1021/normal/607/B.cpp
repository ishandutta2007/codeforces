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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 514
int n , a[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
}
int dp[ N ][ N ];
bool got[ N ][ N ];
int DP( int l , int r ){
  int len = r - l + 1;
  if( len <= 0 ) return 0;
  if( got[ l ][ r ] ) return dp[ l ][ r ];
  got[ l ][ r ] = true;
  if( l == r ) return dp[ l ][ r ] = 1;
  int tdp = min( 1 + DP( l + 1 , r ) , 1 + DP( l , r - 1 ) );
  if( len == 2 ) tdp = min( tdp , 1 + ( a[ l ] != a[ r ] ) );
  else{
    for( int i = l + 1 ; i <= r ; i ++ )
      if( a[ l ] == a[ i ] )
        tdp = min( tdp , DP( l + 1 , i - 1 ) + DP( i + 1 , r ) + ( i - 1 - l <= 0 ) );
  }
  debug( "%d %d : %d\n" , l , r , tdp );
  return dp[ l ][ r ] = tdp;
}
void solve(){
  printf( "%d\n" , DP( 1 , n ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
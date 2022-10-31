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
#define N 55
int n , m;
char c[ N ][ N ];
bool in( int xn , int xm ){
  return 0 <= xn && xn < n &&
         0 <= xm && xm < m;
}
inline int trans( int ii , int jj ){
  return ii * m + jj;
}
void build(){

}
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%s" , c[ i ] );
}
int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};
int dst[ N * N ][ N * N ];
bool got[ N * N ][ N * N ];
deque<PII> dq;
void BFS( int ni , int nj ){
  dst[ trans( ni , nj ) ][ trans( ni , nj ) ] = 0;
  got[ trans( ni , nj ) ][ trans( ni , nj ) ] = true;
  dq.push_back( MP( ni , nj ) );
  while( dq.size() ){
    PII tp = dq.front(); dq.pop_front();
    int xi = tp.FI , xj = tp.SE;
    for( int dir = 0 ; dir < 4 ; dir ++ ){
      int nxti = xi + di[ dir ];
      int nxtj = xj + dj[ dir ];
      if( in( nxti , nxtj ) && !got[ trans( ni , nj ) ][ trans( nxti , nxtj ) ] ){
        got[ trans( ni , nj ) ][ trans( nxti , nxtj ) ] = true;
        if( c[ xi ][ xj ] == c[ nxti ][ nxtj ] ){
          dst[ trans( ni , nj ) ][ trans( nxti , nxtj ) ] =
            dst[ trans( ni , nj ) ][ trans( xi , xj ) ];
          dq.push_front( MP( nxti , nxtj ) );
        }else{
          dst[ trans( ni , nj ) ][ trans( nxti , nxtj ) ] =
            dst[ trans( ni , nj ) ][ trans( xi , xj ) ] + 1;
          dq.push_back( MP( nxti , nxtj ) );
        }
      }
    }
  }
}
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      BFS( i , j );
  int ans = n * m;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ ){
      int tans = -1;
      for( int ii = 0 ; ii < n ; ii ++ )
        for( int jj = 0 ; jj < m ; jj ++ )
          if( c[ ii ][ jj ] == 'B' )
            tans = max( tans , dst[ trans( i , j ) ][ trans( ii , jj ) ] );
      ans = min( ans , tans + 1 );
    }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
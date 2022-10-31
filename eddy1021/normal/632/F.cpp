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
#define N 2525
int n , a[ N ][ N ] , b[ N ][ N ] , p[ N ] , sz;
inline int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
inline bool Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x == y ) return false;
  p[ x ] = y; sz --;
  return true;
}
void build(){

}
vector<PII> v[ N ];
vector< pair<int,PII> > e;
void init(){
  sz = n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      a[ i ][ j ] = getint();
      e.PB( MP( a[ i ][ j ] , MP( i , j ) ) );
    }
  sort( ALL( e ) );
  for( size_t i = 0 ; i < e.size() && sz > 1 ; i ++ )
    if( Union( e[ i ].SE.FI , e[ i ].SE.SE ) ){
      v[ e[ i ].SE.FI ].PB( MP( e[ i ].SE.SE , e[ i ].FI ) );
      v[ e[ i ].SE.SE ].PB( MP( e[ i ].SE.FI , e[ i ].FI ) );
    }
}
bool got[ N ];
queue<int> Q;
void BFS( int st ){
  for( int i = 1 ; i <= n ; i ++ )
    got[ i ] = false;
  Q.push( st );
  got[ st ] = true;
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( size_t i = 0 ; i < v[ tn ].size() ; i ++ )
      if( !got[ v[ tn ][ i ].FI ] ){
        got[ v[ tn ][ i ].FI ] = true;
        b[ st ][ v[ tn ][ i ].FI ] = max( b[ st ][ tn ] , v[ tn ][ i ].SE );
        Q.push( v[ tn ][ i ].FI );
      }
  }
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    BFS( i );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      if( a[ i ][ j ] != b[ i ][ j ] ){
        // printf( "%d%c" , b[ i ][ j ] , " \n"[ j == n ] );
        puts( "NOT MAGIC" );
        return;
      }
  puts( "MAGIC" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
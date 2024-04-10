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
  ll _x=0,_typ=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _typ = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_typ;
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
  ll _typ = mypow( _a , _x / 2 , _mod );
  _typ = mul( _typ , _typ , _mod );
  if( _x & 1 ) _typ = mul( _typ , _a , _mod );
  return _typ;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _typ = mymul( _a , _x / 2 , _mod );
  _typ = add( _typ , _typ , _mod );
  if( _x & 1 ) _typ = add( _typ , _a , _mod );
  return _typ;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 1021
int n , m;
int sx , sy;
int tx , ty;
char c[ N ][ N ];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool rd[ N ][ N ][ 4 ];
inline bool in( int xx , int yy ){
  return 1 <= xx && xx <= n &&
         1 <= yy && yy <= m;
}
inline bool okay( int xx , int yy , int tdir ){
  return rd[ xx ][ yy ][ tdir ];
}
inline void assign( int xx , int yy , char cdir ){
  if( cdir == '+' )
    rd[ xx ][ yy ][ 0 ] =
    rd[ xx ][ yy ][ 1 ] =
    rd[ xx ][ yy ][ 2 ] =
    rd[ xx ][ yy ][ 3 ] = true;
  if( cdir == '-' )
    rd[ xx ][ yy ][ 1 ] =
    rd[ xx ][ yy ][ 3 ] = true;
  if( cdir == '|' )
    rd[ xx ][ yy ][ 0 ] =
    rd[ xx ][ yy ][ 2 ] = true;
  if( cdir == '^' )
    rd[ xx ][ yy ][ 0 ] = true;
  if( cdir == '>' )
    rd[ xx ][ yy ][ 1 ] = true;
  if( cdir == 'v' )
    rd[ xx ][ yy ][ 2 ] = true;
  if( cdir == '<' )
    rd[ xx ][ yy ][ 3 ] = true;
  if( cdir == 'U' )
    rd[ xx ][ yy ][ 1 ] =
    rd[ xx ][ yy ][ 2 ] =
    rd[ xx ][ yy ][ 3 ] = true;
  if( cdir == 'R' )
    rd[ xx ][ yy ][ 0 ] =
    rd[ xx ][ yy ][ 2 ] =
    rd[ xx ][ yy ][ 3 ] = true;
  if( cdir == 'D' )
    rd[ xx ][ yy ][ 0 ] =
    rd[ xx ][ yy ][ 1 ] =
    rd[ xx ][ yy ][ 3 ] = true;
  if( cdir == 'L' )
    rd[ xx ][ yy ][ 0 ] =
    rd[ xx ][ yy ][ 1 ] =
    rd[ xx ][ yy ][ 2 ] = true;
}
void build(){

}
void init(){
  n = getint(); m = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%s" , c[ i ] + 1 );
    for( int j = 1 ; j <= m ; j ++ )
      assign( i , j , c[ i ][ j ] );
  }
  sx = getint();
  sy = getint();
  tx = getint();
  ty = getint();
}
int dst[ 4 ][ N ][ N ];
bool got[ 4 ][ N ][ N ];
queue< tuple<int,int,int> > Q;
inline void bfs(){
  Q.push( MT( 0 , sx , sy ) );
  got[ 0 ][ sx ][ sy ] = true;
  while( Q.size() ){
    tuple<int,int,int> tp = Q.front(); Q.pop();
    int lyr = get<0>( tp );
    int nx  = get<1>( tp );
    int ny  = get<2>( tp );
    int nd  = dst[ lyr ][ nx ][ ny ];
    if( !got[ ( lyr + 1 ) % 4 ][ nx ][ ny ] ){
      got[ ( lyr + 1 ) % 4 ][ nx ][ ny ] = true;
      dst[ ( lyr + 1 ) % 4 ][ nx ][ ny ] = nd + 1;
      Q.push( MT( ( lyr + 1 ) % 4 , nx , ny ) );
    }
    for( int i = 0 ; i < 4 ; i ++ ){
      int dir = ( 4 + i - lyr ) % 4;
      int rdir = ( dir + 2 ) % 4;
      int nxtx = nx + dx[ i ];
      int nxty = ny + dy[ i ];
      if( in( nxtx , nxty ) &&
          okay( nx , ny , dir ) &&
          okay( nxtx , nxty , rdir ) &&
          !got[ lyr ][ nxtx ][ nxty ] ){
        got[ lyr ][ nxtx ][ nxty ] = true;
        dst[ lyr ][ nxtx ][ nxty ] = nd + 1;
        Q.push( MT( lyr , nxtx , nxty ) );
      }
    }
  }
}
void solve(){
  bfs();
  int ans = -1;
  for( int i = 0 ; i < 4 ; i ++ )
    if( got[ i ][ tx ][ ty ] ){
      if( ans == -1 || dst[ i ][ tx ][ ty ] < ans )
        ans = dst[ i ][ tx ][ ty ];
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
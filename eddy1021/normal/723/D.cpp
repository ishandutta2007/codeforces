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
int __ = 1 , _cs;
/*********default*********/
#define N 55
void build(){

}
int n , m , k;
char c[ N ][ N ];
bool got[ N ][ N ];
bool in( int xn , int xm ){
  return 1 <= xn && xn <= n &&
         1 <= xm && xm <= m;
}
int dn[]={0,0,1,-1};
int dm[]={1,-1,0,0};
void init(){
  scanf( "%d%d%d" , &n , &m , &k );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
}
vector< pair< int , pair<int,int> > > lakes;
int ml , mr , mu , md , sz;
void go( int xn , int xm ){
  sz ++;
  got[ xn ][ xm ] = true;
  ml = min( ml  , xm );
  mr = max( mr  , xm );
  mu = min( mu  , xn );
  md = max( md  , xn );
  for( int i = 0 ; i < 4 ; i ++ ){
    int nxtn = xn + dn[ i ];
    int nxtm = xm + dm[ i ];
    if( in( nxtn , nxtm ) &&
        !got[ nxtn ][ nxtm ] &&
        c[ nxtn ][ nxtm ] == '.' )
      go( nxtn , nxtm );
  }
}
bool got2[ N ][ N ];
void bye( int xn , int xm ){
  got2[ xn ][ xm ] = true;
  c[ xn ][ xm ] = '*';
  for( int i = 0 ; i < 4 ; i ++ ){
    int nxtn = xn + dn[ i ];
    int nxtm = xm + dm[ i ];
    if( in( nxtn , nxtm ) &&
        !got2[ nxtn ][ nxtm ] &&
        c[ nxtn ][ nxtm ] == '.' )
      bye( nxtn , nxtm );
  }
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ i ][ j ] == '.' && !got[ i ][ j ] ){
        mu = md = i; ml = mr = j; sz = 0;
        go( i , j );
        if( mu == 1 || ml == 1 || md == n || mr == m )
          continue;
        lakes.push_back( { sz , { i , j } } );
      }
  sort( lakes.begin() , lakes.end() );
  int rm = (int)lakes.size() - k;
  int ans = 0;
  for( int i = 0 ; i < rm ; i ++ ){
    bye( lakes[ i ].second.first ,
         lakes[ i ].second.second );
    ans += lakes[ i ].first;
  }
  printf( "%d\n" , ans );
  for( int i = 1 ; i <= n ; i ++ )
    puts( c[ i ] + 1 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
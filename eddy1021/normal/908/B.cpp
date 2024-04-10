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
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
void build(){

}
#define N 55
int dn[]={0,0,1,-1};
int dm[]={1,-1,0,0};
int dir[ 4 ];
int n , m;
char c[ N ][ N ];
char cmd[ 111 ];
int sn , sm;
int en , em;
bool ok( int xn , int xm ){
  return 1 <= xn and xn <= n and
         1 <= xm and xm <= m and
         c[ xn ][ xm ] != '#';
}
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%s" , c[ i ] + 1 );
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ i ][ j ] == 'S' )
        sn = i , sm = j;
      else if( c[ i ][ j ] == 'E' )
        en = i , em = j;
  }
  scanf( "%s" , cmd );
}
bool good(){
  int xn = sn , xm = sm;
  for( int i = 0 ; cmd[ i ] ; i ++ ){
    int nxtn = xn + dn[ dir[ cmd[ i ] - '0' ] ];
    int nxtm = xm + dm[ dir[ cmd[ i ] - '0' ] ];
    if( not ok( nxtn , nxtm ) )
      return false;
    xn = nxtn;
    xm = nxtm;
    if( xn == en and xm == em )
      return true;
  }
  return false;
}
void solve(){
  for( int i = 0 ; i < 4 ; i ++ ) dir[ i ] = i;
  int ans = 0;
  do{
    if( good() )
      ans ++;
  }while( next_permutation( dir , dir + 4 ) );
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
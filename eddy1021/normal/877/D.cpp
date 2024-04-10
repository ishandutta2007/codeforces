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
#define N 1021
void build(){

}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n , m , k;
int vst[ N ][ N ] , dst[ N ][ N ];
char c[ N ][ N ];
bool ok( int xn , int xm ){
  return 1 <= xn and xn <= n and
         1 <= xm and xm <= m and c[ xn ][ xm ] == '.';
}
int sn , sm , tn , Tm;
void init(){
  n = getint();
  m = getint();
  k = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
  sn = getint();
  sm = getint();
  tn = getint();
  Tm = getint();
}
void go(){
  vst[ sn ][ sm ] = (1 << 4) - 1;
  queue< pair<int,int> > Q;
  Q.push( { sn , sm } );
  while( Q.size() ){
    int cn , cm; tie( cn , cm ) = Q.front(); Q.pop();
    for( int dir = 0 ; dir < 4 ; dir ++ ){
      for( int kk = 1 ; kk <= k ; kk ++ ){
        int nxtn = cn + dx[ dir ] * kk;
        int nxtm = cm + dy[ dir ] * kk;
        if( not ok( nxtn , nxtm ) ) break;
        if( (vst[ nxtn ][ nxtm ] >> dir) & 1 ) break;
        bool add = false;
        if( !vst[ nxtn ][ nxtm ] ) add = true;
        vst[ nxtn ][ nxtm ] |= (1 << dir);
        if( add ){
          dst[ nxtn ][ nxtm ] = dst[ cn ][ cm ] + 1;
          Q.push( { nxtn , nxtm } );
          if( nxtn == tn and nxtm == Tm )
            return;
        }
      }
    }
  }
}
void solve(){
  go();
  printf( "%d\n" , vst[ tn ][ Tm ] ? dst[ tn ][ Tm ] : -1 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
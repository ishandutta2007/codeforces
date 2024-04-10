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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 202020
struct Nd{
  int cnt , lc , rc;
  Nd(){
    lc = rc = cnt = 0;
  }
} nd[ 4040404 ];
int nc;
inline int copy( int prev ){
  int nxt = ++ nc;
  nd[ nxt ] = nd[ prev ];
  return nxt;
}
#define mid ((l+r)>>1)
inline void modify( int cur , int l , int r , int p ){
  nd[ cur ].cnt ++;
  if( l == r ) return;
  if( p <= mid ){
    nd[ cur ].lc = copy( nd[ cur ].lc );
    modify( nd[ cur ].lc , l , mid , p );
  }else{
    nd[ cur ].rc = copy( nd[ cur ].rc );
    modify( nd[ cur ].rc , mid + 1 , r , p );
  }
}
inline int query( int cur , int l , int r , int ql , int qr ){
  if( !cur or r < ql or l > qr or ql > qr or nd[ cur ].cnt == 0 )
    return 0;
  if( ql <= l and r <= qr ) return nd[ cur ].cnt;
  return query( nd[ cur ].lc , l , mid , ql , qr ) +
         query( nd[ cur ].rc , mid + 1 , r , ql , qr );
}
int n , m , per[ N ] , rt[ N ];
int pos[ N ] , ppos[ N ];
void build(){

}
int cand[ N ] , ct , tag[ N ] , stmp;
void rebuild(){
  ct = nc = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    rt[ i ] = copy( rt[ i - 1 ] );
    modify( rt[ i ] , 1 , n , per[ i ] );
    ppos[ per[ i ] ] = i;
  }
}
inline int le( int qpos , int ci ){
  int qq = query( rt[ qpos ] , 1 , n , 1 , ci );
  ++ stmp;
  for( int i = 0 ; i < ct ; i ++ ){
    if( cand[ i ] > ci ) continue;
    int now = cand[ i ];
    if( tag[ now ] == stmp ) continue;
    tag[ now ] = stmp;
    if( ppos[ now ] <= qpos and pos[ now ] > qpos ) qq --;
    if( ppos[ now ] > qpos and pos[ now ] <= qpos ) qq ++;
  }
  //for( int i = 1 ; i <= n ; i ++ )
    //printf( "%d%c" , per[ i ] , " \n"[ i == n ] );
  //printf( "less %d %d : %d\n" , qpos , ci , qq );
  return qq;
}
void init(){
  n = getint(); m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    pos[ i ] = per[ i ] = i;
}
#define Z 2017
LL ans;
void solve(){
  for( int i = 0 ; i < m ; i ++ ){
    if( i % Z == 0 ) rebuild();
    int cl = getint();
    int cr = getint();
    if( cl > cr ) swap( cl , cr );
    if( cl != cr ){
      cand[ ct ++ ] = per[cl];
      cand[ ct ++ ] = per[cr];
      int fuck1 = le( cr     , per[cl] - 1 );
      int fuck2 = le( cl     , per[cl] - 1 );
      ans -= fuck1 - fuck2;
      ans += ( cr - cl ) - ( fuck1 - fuck2 );
      if( per[cr] > per[cl] ) ans --;
      int shit1 = le( cr - 1 , per[cr] - 1 );
      int shit2 = le( cl - 1 , per[cr] - 1 );
      ans += shit1 - shit2;
      ans -= ( cr - cl ) - ( shit1 - shit2 );
      if( per[cl] > per[cr] ) ans ++;
      {
        int il = per[cl];
        int ir = per[cr];
        swap( per[cl] , per[cr] );
        pos[il] = cr;
        pos[ir] = cl;
      }
    }
    printf( "%lld\n" , ans );
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
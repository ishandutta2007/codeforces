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
//#define INF  1023456789LL
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
struct ST{
  int cnt;
  LL sum;
  ST *lc , *rc;
  ST(){
    cnt = sum = 0;
    lc = rc = NULL;
  }
};
#define mid ((l+r)>>1) 
int Cnt( ST* now ){
  return now ? now->cnt : 0;
}
LL Sum( ST* now ){
  return now ? now->sum : 0;
}
void modify( ST* now , int l , int r , int p ){
  if( l == r ){
    now->cnt ++;
    now->sum += p;
    return;
  }
  if( p <= mid ){
    if( not now->lc ) now->lc = new ST();
    modify( now->lc , l , mid , p );
  }else{
    if( not now->rc ) now->rc = new ST();
    modify( now->rc , mid + 1 , r , p );
  }
  now->cnt = Cnt( now->lc ) + Cnt( now->rc );
  now->sum = Sum( now->lc ) + Sum( now->rc );
}
LL query( ST* now , int l , int r , int nd ){
  if( nd == 0 ) return 0;
  if( !now or now->cnt < nd ) return -1;
  if( now->cnt == nd ) return now->sum;
  if( l == r ) return (LL)l * nd;
  if( now->lc and now->lc->cnt ){
    LL lret = query( now->lc , l , mid , min( nd , now->lc->cnt ) );
    LL rret = query( now->rc , mid + 1 , r , nd - min( nd , now->lc->cnt ) );
    if( lret == -1 or rret == -1 ) return -1;
    return lret + rret;
  }
  return query( now->rc , mid + 1 , r , nd );
}
void build(){

}
LL n , m , k , c[ N ];
int like[ N ];
void init(){
  n = getint();
  m = getint();
  k = getint();
  for( int i = 1 ; i <= n ; i ++ )
    c[ i ] = getint();
  for( int i = 0 ; i < 2 ; i ++ ){
    int ki = getint(); while( ki -- )
      like[ getint() ] |= ( 1 << i );
  }
}
const int inf = 1000000000;
vector< LL > cst[ 4 ];
LL sz[ 4 ];
LL psum[ 4 ][ N ] , ans = -1;
ST *root;
void solve(){
  root = new ST();
  for( int i = 1 ; i <= n ; i ++ )
    cst[ like[ i ] ].push_back( c[ i ] );
  for( int i = 0 ; i < 4 ; i ++ ){
    if( cst[ i ].empty() ) continue;
    sz[ i ] = cst[ i ].size();
    sort( cst[ i ].begin() , cst[ i ].end() );
    psum[ i ][ 0 ] = cst[ i ][ 0 ];
    for( int j = 1 ; j < sz[ i ] ; j ++ )
      psum[ i ][ j ] = psum[ i ][ j - 1 ] + cst[ i ][ j ];
  }
  for( int i = 0 ; i < sz[ 0 ] ; i ++ )
    modify( root , 1 , inf , cst[ 0 ][ i ] );
  for( int i = 1 ; i < 3 ; i ++ )
    for( int j = k + 1 ; j < sz[ i ] ; j ++ )
      modify( root , 1 , inf , cst[ i ][ j ] );
  for( int i = 0 ; i <= min( m , sz[ 3 ] ) ; i ++ ){
    int each = k - i;
    for( int j = 1 ; j < 3 ; j ++ )
      if( each < sz[ j ] and each >= 0 )
        modify( root , 1 , inf , cst[ j ][ each ] );
    LL tans = i ? psum[ 3 ][ i - 1 ] : 0;
    bool ok = true;
    if( each > 0 ){
      for( int j = 1 ; j < 3 ; j ++ ){
        if( each > sz[ j ] ){
          ok = false;
          break;
        }
        tans += psum[ j ][ each - 1 ];
      }
    }
    if( not ok ) continue;
    each = max( each , 0 );
    if( i + each + each > m ) continue;
    LL mr = max( 0LL , m - i - each - each );
    LL ret = query( root , 1 , inf , mr );
    if( ret == -1 ) continue;
    tans += ret;
    if( ans == -1 or tans < ans )
      ans = tans;
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
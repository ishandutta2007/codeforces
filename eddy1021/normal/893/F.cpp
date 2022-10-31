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
#define N 131073
#define mid ((l+r)>>1)
struct Nd{
  Nd *tl , *tr;
  int v;
  Nd(){
    tl = tr = NULL;
    v = INF;
  }
};
inline Nd* copy( Nd* x ){
  Nd* ret = new Nd();
  if( x ){
    ret->tl = x->tl;
    ret->tr = x->tr;
    ret->v = x->v;
  }
  return ret;
}
inline int V( Nd* now ){
  return now ? now->v : INF;
}
void modify( Nd* now , int l , int r , int p , int vv ){
  if( l == r ){
    now->v = vv;
    return;
  }
  if( p <= mid ){
    now->tl = copy( now->tl );
    modify( now->tl , l , mid , p , vv );
  }else{
    now->tr = copy( now->tr );
    modify( now->tr , mid + 1 , r , p , vv );
  }
  now->v = min( V( now->tl ) , V( now->tr ) );
}
int query( Nd* now , int l , int r , int ql , int qr ){
  if( !now or r < ql or l > qr or ql > qr ) return INF;
  if( ql <= l and r <= qr ) return now->v;
  return min( query( now->tl , l , mid , ql , qr ) ,
              query( now->tr , mid + 1 , r , ql , qr ) );
}
void build(){
}
int n , r , a[ N ];
vector<int> v[ N ];
void init(){
  n = getint();
  r = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
Nd *root[ N ];
int dep[ N ] , in[ N ] , out[ N ] , stmp , maxh;
vector<int> wt[ N ];
void go( int now , int prt , int tdep ){
  dep[ now ] = tdep;
  in[ now ] = ++ stmp;
  maxh = max( maxh , tdep );
  wt[ tdep ].push_back( now );
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now , tdep + 1 );
  }
  out[ now ] = stmp;
}
void solve(){
  go( r , r , 1 );
  for( int i = 1 ; i <= maxh ; i ++ ){
    root[ i ] = copy( root[ i - 1 ] );
    for( int id : wt[ i ] )
      modify( root[ i ] , 1 , n , in[ id ] , a[ id ] );
  }
  int q = getint() , lst = 0; while( q -- ){
    int pi = getint();
    int qi = getint();
    int xi = ((pi + lst) % n) + 1;
    int ki = (qi + lst) % n;
    lst = query( root[ min( maxh , dep[ xi ] + ki ) ] , 1 , n , in[ xi ] , out[ xi ] );
    printf( "%d\n" , lst );
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
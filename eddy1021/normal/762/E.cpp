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
#define N 101010
struct Nd{
  int sum , tl , tr;
  Nd(){
    sum = tl = tr = 0;
  }
} nd[ N * 30 * 4 ];
int nid;
int new_node(){ return ++ nid; }
inline int Sum( int x ){
  return x ? nd[ x ].sum : 0;
}
#define mid ((l+r)>>1)
void modify( int now , int l , int r , int p ){
  if( l == r ){
    nd[ now ].sum ++;
    return;
  }
  if( p <= mid ){
    if( !nd[ now ].tl )
      nd[ now ].tl = new_node();
    modify( nd[ now ].tl , l , mid , p );
  }else{
    if( !nd[ now ].tr )
      nd[ now ].tr = new_node();
    modify( nd[ now ].tr , mid + 1 , r , p );
  }
  nd[ now ].sum = Sum( nd[ now ].tl ) + Sum( nd[ now ].tr );
}
int query( int now , int l , int r , int ql , int qr ){
  if( !now || r < ql || l > qr ) return 0;
  if( ql <= l && r <= qr ) return nd[ now ].sum;
  return query( nd[ now ].tl , l , mid , ql , qr ) +
         query( nd[ now ].tr , mid + 1 , r , ql , qr );
}
int rt[ 10101 ];
void build(){

}
int n , k , maxx , maxf;
vector< pair<int,pair<int,int> > > v;
void init(){
  n = getint();
  k = getint();
  for( int i = 0 ; i < n ; i ++ ){
    int xi = getint();
    int ri = getint();
    int fi = getint();
    maxx = max( maxx , xi );
    maxf = max( maxf , fi );
    v.push_back( { ri , { xi , fi } } );
  }
}
void solve(){
  sort( v.begin() , v.end() );
  reverse( v.begin() , v.end() );
  LL ans = 0;
  for( auto i : v ){
    int nr = i.first;
    int nx = i.second.first;
    int nf = i.second.second;
    int lx = max( 1 , nx - nr ) , rx = min( maxx , nx + nr );
    int lf = max( 1 , nf - k ) , rf = min( maxf , nf + k );
    for( int j = lf ; j <= rf ; j ++ )
      ans += query( rt[ j ] , 1 , maxx , lx , rx );
    if( !rt[ nf ] ) rt[ nf ] = new_node();
    modify( rt[ nf ] , 1 , maxx , nx );
    //printf( "r=%d x=%d f=%d : ans=%lld\n" , nr , nx , nf , ans );
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
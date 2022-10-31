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
#define N 505050
int n , nl[ N ] , nr[ N ] , st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void modify( int no , int l , int r , int p ){
  if( l == r ){
    st[ no ] ++;
    return;
  }
  if( p <= mid ) modify( L( no ) , l , mid , p );
  else modify( R( no ) , mid + 1 , r , p );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
int query( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql ) return 0;
  if( ql <= l && r <= qr ) return st[ no ];
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
void build(){

}
vector<PII> vv;
vector<int> li;
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    nl[ i ] = getint();
    nr[ i ] = getint();
    vv.PB( MP( nr[ i ] , i ) );
    li.PB( nl[ i ] );
    li.PB( nr[ i ] );
  }
  sort( ALL( vv ) );
  sort( ALL( li ) );
  li.resize( unique( ALL( li ) ) - li.begin() );
  for( int i = 0 ; i < n ; i ++ ){
    nl[ i ] = lower_bound( ALL( li ) , nl[ i ] ) - li.begin() + 1;
    nr[ i ] = lower_bound( ALL( li ) , nr[ i ] ) - li.begin() + 1;
  }
}
int ans[ N ] , n2;
void solve(){
  n2 = n << 1;
  for( int _ = 0 ; _ < n ; _ ++ ){
    int i = vv[ _ ].SE;
    ans[ i ] = query( 1 , 1 , n2 , nl[ i ] , nr[ i ] );
    // printf( "%d %d\n" , nl[ i ] , nr[ i ] );
    modify( 1 , 1 , n2 , nl[ i ] );
  }
  for( int i = 0 ; i < n ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
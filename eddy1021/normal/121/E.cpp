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
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
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
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 404040
vector<int> lucky;
bool islucky[ N ];
int nxtl[ N ];
void go( int now ){
  lucky.push_back( now );
  if( now > 10000 ) return;
  go( now * 10 + 4 );
  go( now * 10 + 7 );
}
void build(){
  go( 0 );
  sort( ALL( lucky ) );
  for( int luck : lucky )
    islucky[ luck ] = true;
  int nxt = N;
  for( int i = 10000 ; i >= 1 ; i -- ){
    nxtl[ i ] = nxt;
    if( islucky[ i ] ) nxt = i;
  }
}
int n , m , st[ N ] , nxt[ N ] , a[ N ] , mn[ N ] , tag[ N ] , aa[ N ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
inline void pull( int no ){
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
  mn[ no ] = min( mn[ L( no ) ] , mn[ R( no ) ] );
}
inline void push( int no , int l , int r ){
  if( tag[ no ] ){
    st[ L( no ) ] =
    st[ R( no ) ] = 0;
    mn[ L( no ) ] -= tag[ no ];
    mn[ R( no ) ] -= tag[ no ];
    aa[ L( no ) ] += tag[ no ];
    aa[ R( no ) ] += tag[ no ];
    tag[ L( no ) ] += tag[ no ];
    tag[ R( no ) ] += tag[ no ];
  }
  tag[ no ] = 0;
}
void build_st( int no , int l , int r ){
  tag[ no ] = 0;
  if( l == r ){
    aa[ no ] = a[ l ];
    st[ no ] = islucky[ a[ l ] ];
    mn[ no ] = nxtl[ a[ l ] ] - a[ l ];
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  pull( no );
}
void modify( int no , int l , int r , int ql , int qr , int dlt ){
  if( l > qr || r < ql ) return;
  if( ql <= l && r <= qr && dlt < mn[ no ] ){
    st[ no ] = 0;
    mn[ no ] -= dlt;
    tag[ no ] += dlt;
    if( l == r ){
      aa[ no ] += dlt;
      st[ no ] = islucky[ aa[ no ] ];
      mn[ no ] = nxtl[ aa[ no ] ] - aa[ no ];
    }
    return;
  }
  if( l == r ){
    aa[ no ] += dlt;
    st[ no ] = islucky[ aa[ no ] ];
    mn[ no ] = nxtl[ aa[ no ] ] - aa[ no ];
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr , dlt );
  modify( R( no ) , mid + 1 , r , ql , qr , dlt );
  pull( no );
}
inline void modify( int ql , int qr , int dlt ){
  while( dlt ){
    int add = min( dlt , mn[ 1 ] );
    dlt -= add;
    modify( 1 , 1 , n , ql , qr , add );
  }
}
int query( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql ) return 0;
  if( ql <= l && r <= qr ) return st[ no ];
  push( no , l , r );
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  build_st( 1 , 1 , n );
}
char cmd[ 100 ];
void solve(){
  while( m -- ){
    scanf( "%s" , cmd );
    int ql = getint();
    int qr = getint();
    if( cmd[ 0 ] == 'c' )
      printf( "%d\n" , query( 1 , 1 , n , ql , qr ) );
    else modify( ql , qr , getint() );
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
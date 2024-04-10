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
#define N 101010
void build(){

}
typedef pair< pair<int,int> , pair<int,int> > el;
#define A00(X) X.FI.FI
#define A01(X) X.FI.SE
#define A10(X) X.SE.FI
#define A11(X) X.SE.SE
el I = { { 1 , 0 } , { 0 , 1 } };
el A = { { 0 , 1 } , { 1 , 1 } };
inline el operator+( const el& e1 , const el& e2 ){
  return { { add( A00( e1 ) , A00( e2 ) ) , add( A01( e1 ) , A01( e2 ) ) } ,
           { add( A10( e1 ) , A10( e2 ) ) , add( A11( e1 ) , A11( e2 ) ) } };
}
inline el operator*( const el& e1 , const el& e2 ){
  return { { add( mul( A00( e1 ) , A00( e2 ) ) , mul( A01( e1 ) , A10( e2 ) ) ) ,
             add( mul( A00( e1 ) , A01( e2 ) ) , mul( A01( e1 ) , A11( e2 ) ) ) },
           { add( mul( A10( e1 ) , A00( e2 ) ) , mul( A11( e1 ) , A10( e2 ) ) ) ,
             add( mul( A10( e1 ) , A01( e2 ) ) , mul( A11( e1 ) , A11( e2 ) ) ) } };
}
inline el operator^( const el& e1 , LL tk ){
  el i = I , a = A;
  while( tk ){
    if( tk & 1 ) i = i * a;
    a = a * a;
    tk >>= 1;
  }
  return i;
}
int n , m , a[ N ];
el tag[ N << 2 ] , seg[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  tag[ no ] = I;
  if( l == r ){
    seg[ no ] = A ^ ( a[ l ] - 1 );
    // printf( "%d %d %d %d\n" , A00( seg[ no ] ) , A01( seg[ no ] ) ,
                              // A10( seg[ no ] ) , A11( seg[ no ] ) );
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  seg[ no ] = seg[ L( no ) ] + seg[ R( no ) ];
}
void push( int no , int l , int r ){
  if( tag[ no ] == I ) return;
  seg[ L( no ) ] = seg[ L( no ) ] * tag[ no ];
  seg[ R( no ) ] = seg[ R( no ) ] * tag[ no ];
  tag[ L( no ) ] = tag[ L( no ) ] * tag[ no ];
  tag[ R( no ) ] = tag[ R( no ) ] * tag[ no ];
  tag[ no ] = I;
}
el mod;
void modify( int no , int l , int r , int ql , int qr ){
  if( r < ql || l > qr ) return;
  if( ql <= l && r <= qr ){
    seg[ no ] = seg[ no ] * mod;
    tag[ no ] = tag[ no ] * mod;
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr );
  modify( R( no ) , mid + 1 , r , ql , qr );
  seg[ no ] = seg[ L( no ) ] + seg[ R( no ) ];
}
el query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return seg[ no ];
  push( no , l , r );
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid <  ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  return query( L( no ) , l , mid , ql , mid ) +
         query( R( no ) , mid + 1 , r , mid + 1 , qr );
}
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  build_st( 1 , 1 , n );
}
void solve(){
  while( m -- ){
    int cmd = getint();
    int ql = getint();
    int qr = getint();
    if( cmd == 1 ){
      mod = A ^ getint();
      modify( 1 , 1 , n , ql , qr );
    }else{
      el ret = query( 1 , 1 , n , ql , qr );
      printf( "%d\n" , A11( ret ) );
    }
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
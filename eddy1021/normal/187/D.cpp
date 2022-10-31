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
ll n , G , R , d[ N ] , t[ N ] , GR , s[ N ];
void build(){

}
struct Nd{
  Nd *l , *r;
  int mn;
  Nd(){
    l = r = NULL;
    mn = N;
  }
}*root;
#define mid ((l+r)>>1)
void modify( Nd* now , int l , int r , int p , int x ){
  now->mn = x;
  if( l == r ) return;
  if( p <= mid ){
    if( !now->l ) now->l = new Nd();
    modify( now->l , l , mid , p , x );
  }else{
    if( !now->r ) now->r = new Nd();
    modify( now->r , mid + 1 , r , p , x );
  }
}
int query( Nd* now , int l , int r , int ql , int qr ){
  if( !now || qr < l || r < ql ) return N;
  if( ql <= l && r <= qr ) return now->mn;
  return min( query( now->l , l , mid , ql , qr ) ,
              query( now->r , mid + 1 , r , ql , qr ) );
}
int query( int lpos , int rpos ){
  if( lpos <= rpos )
    return query( root , 0 , GR - 1 , lpos , rpos );
  return min( query( root , 0 , GR - 1 , 0 , rpos ) ,
              query( root , 0 , GR - 1 , lpos , GR - 1 ) );
}
void pre_solve(){
  root = new Nd();
  for( int i = n ; i >= 0 ; i -- ){
    int lpos = ( ( G - s[ i ] ) % GR + GR ) % GR;
    int rpos = ( ( GR - 1 - s[ i ] ) % GR + GR ) % GR;
    int bst = query( lpos , rpos );
    if( bst == N ) t[ i ] = s[ i ];
    else{
      t[ i ] = s[ i ] - s[ bst ] + t[ bst ];
      t[ i ] += GR - ( s[ i ] - s[ bst ] ) % GR;
    }
    if( i )
      modify( root , 0 , GR - 1 , ( ( - s[ i ] ) % GR + GR ) % GR , i );
  }
}
inline ll cal( ll ti ){
  int lpos = ( ( G - s[ 0 ] - ti ) % GR + GR ) % GR;
  int rpos = ( ( GR - 1 - s[ 0 ] - ti ) % GR + GR ) % GR;
  int bst = query( lpos , rpos );
  if( bst == N ) return ti + s[ 0 ];
  ll ans = ti + s[ 0 ] - s[ bst ] + t[ bst ];
  ans += GR - ( ti + s[ 0 ] - s[ bst ] ) % GR;
  return ans;
}
void init(){
  n = getint();
  G = getint();
  R = getint();
  GR = G + R;
  for( int i = 0 ; i <= n ; i ++ )
    d[ i ] = getint();
  for( int i = n ; i >= 0 ; i -- )
    s[ i ] = s[ i + 1 ] + d[ i ];
}
void solve(){
  pre_solve();
  int q = getint(); while( q -- ){
    ll ti = getint();
    printf( "%lld\n" , cal( ti ) );
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
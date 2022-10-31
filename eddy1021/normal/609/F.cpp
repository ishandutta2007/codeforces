// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
int __ = 1 , cs;
/*********default*********/
#define N 222222
struct ST{
  ST *l , *r;
  int mx , tag;
  ST(){ tag = mx = INF; l = r = NULL; }
}*root;
void push( ST* now , int l , int r ){
  if( now->tag == INF ) return;
  now->mx = min( now->mx , now->tag );
  if( l != r ){
    if( !now->l ) now->l = new ST();
    if( !now->r ) now->r = new ST();
    if( now->tag < now->l->tag )
      now->l->tag = now->tag;
    if( now->tag < now->r->tag )
      now->r->tag = now->tag;
  }
  now->tag = INF;
}
int MX( ST *now ){ return now ? now->mx : INF; }
void pull( ST* now ){
  now->mx = min( now->mx , min( MX( now->l ) , MX( now->r ) ) );
}
void modify( ST* now , int l , int r , int ql , int qr , int tx ){
  if( l == ql && r == qr ){
    if( tx < now->tag ) now->tag = tx;
    now->mx = min( now->mx , tx );
    return;
  }
  push( now , l , r );
  int mid = ( l + r ) >> 1;
  if( qr <= mid ){
    if( !now->l ) now->l = new ST();
    modify( now->l , l , mid , ql , qr , tx );
  }else if( mid < ql ){
    if( !now->r ) now->r = new ST();
    modify( now->r , mid + 1 , r , ql , qr , tx );
  }else{
    if( !now->l ) now->l = new ST();
    if( !now->r ) now->r = new ST();
    modify( now->l , l , mid , ql , mid , tx );
    modify( now->r , mid + 1 , r , mid + 1 , qr , tx );
  }
  pull( now );
}
int query( ST* now , int l , int r , int pos ){
  if( !now ) return INF;
  push( now , l , r );
  if( l == r ) return now->mx;
  int mid = ( l + r ) >> 1;
  if( pos <= mid ) return query( now->l , l , mid , pos );
  return query( now->r , mid + 1 , r , pos );
}
int n , m;
map<int,int> frog;
ll x[ N ] , t[ N ] , eat[ N ];
void build(){

}
#define LL 0ll
#define RR 1000000000ll
void init(){
  n = getint(); m = getint();
  root = new ST();
  for( int i = 1 ; i <= n ; i ++ ){
    x[ i ] = getint();
    t[ i ] = getint();
    frog[ x[ i ] ] = i;
    modify( root , LL , RR , x[ i ] , min( x[ i ] + t[ i ] , RR ) , x[ i ] );
  }
}
multiset< PII > mos;
typedef multiset< PII >::iterator mi;
void grow( int i ){
  while( true ){
    mi it = mos.lower_bound( MP( x[ i ] , -1 ) );
    if( it == mos.end() ) break;
    PII tp = *it;
    if( tp.FI > x[ i ] + t[ i ] ) break;
    eat[ i ] ++; t[ i ] += tp.SE;
    mos.erase( it );
  }
  modify( root , LL , RR , x[ i ] , min( x[ i ] + t[ i ] , RR ) , x[ i ] );
}
void solve(){
  while( m -- ){
    int pi = getint();
    int bi = getint();
    int ff = query( root , LL , RR , pi );
    debug( "%d %d -> %d\n" , pi , bi , ff );
    if( ff == INF ) mos.insert( MP( pi , bi ) );
    else{
      int i = frog[ ff ];
      eat[ i ] ++; t[ i ] += bi;
      grow( i );
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld %lld\n" , eat[ i ] , t[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
#define N 1010101
int n , a[ N ] , t[ N ] , x[ N ];
struct Node{
  Node *l , *r;
  int cnt;
  Node(){ cnt = 0; l = r = NULL; }
};
Node *root[ N ];
inline int Cnt( Node* now ){
  return now ? now->cnt : 0;
}
void modify( Node* now , int l , int r , int p , int dlt ){
  if( l == r ){
    now->cnt += dlt;
    return;
  }
  int mid = ( l + r ) >> 1;
  if( p <= mid ){
    if( !now->l ) now->l = new Node();
    modify( now->l , l , mid , p , dlt );
  }else{
    if( !now->r ) now->r = new Node();
    modify( now->r , mid + 1 , r , p , dlt );
  }
  now->cnt = Cnt( now->l ) + Cnt( now->r );
}
int query( Node* now , int l , int r , int ql , int qr ){
  if( !now ) return 0;
  if( l == ql && r == qr ) return now->cnt;
  int mid = ( l + r ) >> 1;
  if( qr <= mid ) return query( now->l , l , mid , ql , qr );
  if( mid <  ql ) return query( now->r , mid + 1 , r , ql , qr );
  return query( now->l , l , mid , ql , mid ) +
         query( now->r , mid + 1 , r , mid + 1 , qr );
}
void build(){

}
vector<int> li , lit;
int lsz , tsz;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    t[ i ] = getint();
    x[ i ] = getint();
    lit.PB( t[ i ] );
    li.PB( x[ i ] );
  }
  sort( ALL( li ) );
  li.resize( unique( ALL( li ) ) - li.begin() );
  sort( ALL( lit ) );
  lit.resize( unique( ALL( lit ) ) - lit.begin() );
  for( int i = 1 ; i <= n ; i ++ ){
    t[ i ] = lower_bound( ALL( lit ) , t[ i ] ) - lit.begin() + 1;
    x[ i ] = lower_bound( ALL( li ) , x[ i ] ) - li.begin();
  }
  lsz = (int)li.size();
  tsz = (int)lit.size();
  for( int i = 0 ; i < lsz ; i ++ )
    root[ i ] = new Node();
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( a[ i ] == 1 )
      modify( root[ x[ i ] ] , 1 , tsz , t[ i ] , +1 );
    else if( a[ i ] == 2 )
      modify( root[ x[ i ] ] , 1 , tsz , t[ i ] , -1 );
    else
      printf( "%d\n" , query( root[ x[ i ] ] , 1 , tsz , 1 , t[ i ] ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
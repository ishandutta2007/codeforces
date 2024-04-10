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
#define N 202020
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
ll st[ 2 ][ N << 2 ];
void modify( int kd , int no , int l , int r , int pos , int dlt ){
  if( l == r ){
    st[ kd ][ no ] += dlt;
    return;
  }
  if( pos <= mid ) modify( kd , L( no ) , l , mid , pos , dlt );
  else modify( kd , R( no ) , mid + 1 , r , pos , dlt );
  st[ kd ][ no ] = st[ kd ][ L( no ) ] +
                   st[ kd ][ R( no ) ];
}
ll query( int kd , int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql || ql > qr ) return 0;
  if( ql <= l && r <= qr ) return st[ kd ][ no ];
  return query( kd , L( no ) , l , mid , ql , qr ) +
         query( kd , R( no ) , mid + 1 , r , ql , qr );
}
void build(){

}
ll n , k , a , b , q;
void init(){
  n = getint();
  k = getint();
  a = getint();
  b = getint();
  q = getint();
}
ll v[ N ];
void solve(){
  while( q -- ){
    int cmd = getint();
    if( cmd == 1 ){
      ll di = getint();
      ll ai = getint();
      ll dlta = max( 0ll , min( ai , a - v[ di ] ) );
      ll dltb = max( 0ll , min( ai , b - v[ di ] ) );
      v[ di ] += ai;
      // printf( "%lld %lld %lld %lld\n" , di , ai , dlta , dltb );
      if( dlta ) modify( 0 , 1 , 1 , n , di , dlta );
      if( dltb ) modify( 1 , 1 , 1 , n , di , dltb );
    }else{
      ll di = getint();
      ll lans = query( 1 , 1 , 1 , n , 1 , di - 1 );
      ll rans = query( 0 , 1 , 1 , n , di + k , n );
      ll ans = lans + rans;
      // printf( "%lld %lld " , lans , rans );
      printf( "%lld\n" , ans );
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
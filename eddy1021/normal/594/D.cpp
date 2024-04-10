// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 200010
#define P 1000010
bool p[ P ];
ll dv[ P ] , ml[ P ];
vector<int> fac[ P ];
void build(){
  for( ll i = 2 ; i < P ; i ++ ) if( !p[ i ] )
    for( ll j = i ; j < P ; j += i ){
      fac[ j ].PB( i );
      if( j > i ) p[ j ] = true;
    }
  for( int i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
    dv[ i ] = ( (ll)( i - 1 ) * mypow( i , mod7 - 2 , mod7 ) ) % mod7;
    ml[ i ] = ( (ll)( i ) * mypow( i - 1 , mod7 - 2 , mod7 ) ) % mod7;
  }
}
ll st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
void build_st( int no , int l , int r ){
  st[ no ] = 1;
  if( l == r ) return;
  int mid = ( l + r ) >> 1;
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
}
void modify( int no , int l , int r , int pos , ll dlt ){
  if( l == r ){
    st[ no ] = ( st[ no ] * dlt ) % mod7;
    return;
  }
  int mid = ( l + r ) >> 1;
  if( pos <= mid ) modify( L( no ) , l , mid , pos , dlt );
  else modify( R( no ) , mid + 1 , r , pos , dlt );
  st[ no ] = ( st[ L( no ) ] * st[ R( no ) ] ) % mod7;
}
ll query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return st[ no ];
  int mid = ( l + r ) >> 1;
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid <  ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  return ( query( L( no ) , l , mid , ql , mid ) *
           query( R( no ) , mid + 1 , r , mid + 1 , qr ) ) % mod7;
}
int n, q;
ll prep[ P ];
ll a[ N ] , pp[ N ];
void add( int npos ){
  ll num = a[ npos ];
  // printf( "%d %lld\n" , npos , num );
  for( int i = 0 ; i < (int)fac[ num ].size() ; i ++ ){
    int tfac = fac[ num ][ i ];
    if( prep[ tfac ] ){
      modify( 1 , 1 , n , prep[ tfac ] , ml[ tfac ] );
      // printf( "-%lld %d %lld\n" , prep[ tfac ] , tfac , ml[ tfac ] );
    }
    modify( 1 , 1 , n , npos , dv[ tfac ] );
    // printf( "+%lld %d %lld\n" , prep[ tfac ] , tfac , dv[ tfac ] );
    prep[ tfac ] = npos;
  }
}
ll l[ N ] , r[ N ] , ans[ N ];
vector< PII > Q;
void init(){
  n = getint(); pp[ 0 ] = 1;
  build_st( 1 , 1 , n );
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    pp[ i ] = ( pp[ i - 1 ] * a[ i ] ) % mod7;
  }
  q = getint();
  for( int i = 0 ; i < q ; i ++ ){
    l[ i ] = getint();
    r[ i ] = getint();
    Q.PB( MP( r[ i ] , i ) );
  }
  sort( ALL( Q ) );
}
void solve(){
  int ptr = 0;
  for( int _ = 0 ; _ < q ; _ ++ ){
    int i = Q[ _ ].SE;
    while( ptr < r[ i ] ) add( ++ ptr );
    ll tans = ( pp[ r[ i ] ] * mypow( pp[ l[ i ] - 1 ] , mod7 - 2 , mod7 ) ) % mod7;
    tans = ( tans * query( 1 , 1 , n , l[ i ] , r[ i ] ) ) % mod7;
    ans[ i ] = tans;
  }
  for( int i = 0 ; i < q ; i ++ )
    printf( "%I64d\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
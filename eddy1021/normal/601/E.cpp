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
#define N 77777
#define Q 10000019ll
vector<int> St[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
void modify( int no , int l , int r , int ql , int qr , int x ){
  if( ql <= l && qr >= r ){
    St[ no ].PB( x );
    return;
  }
  int mid = ( l + r ) >> 1;
  if( qr <= mid ) modify( L( no ) , l , mid , ql , qr , x );
  else if( mid < ql ) modify( R( no ) , mid + 1 , r , ql , qr , x );
  else{
    modify( L( no ) , l , mid , ql , qr , x );
    modify( R( no ) , mid + 1 , r , ql , qr , x );
  }
}
int n , k , v[ N ] , w[ N ];
int q , tp[ N ] , st[ N ] , et[ N ];
void build(){

}
void init(){
  n = getint(); k = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    v[ i ] = getint();
    w[ i ] = getint();
    st[ i ] = 1;
  }
  q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    et[ i ] = q;
  for( int i = 1 ; i <= q ; i ++ ){
    tp[ i ] = getint();
    if( tp[ i ] == 1 ){
      v[ ++ n ] = getint();
      w[ n ] = getint();
      st[ n ] = i;
      et[ n ] = q;
    }else if( tp[ i ] == 2 ){
      int x = getint();
      et[ x ] = i;
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    modify( 1 , 1 , q , st[ i ] , et[ i ] , i );
}
void cal( int no , int l , int r , vector<ll> dp ){
  for( int i = 0 ; i < (int)St[ no ].size() ; i ++ ){
    int idx = St[ no ][ i ];
    for( int j = k ; j >= w[ idx ] ; j -- )
      dp[ j ] = max( dp[ j ] , dp[ j - w[ idx ] ] + (ll)v[ idx ] );
  }
  if( l == r ){
    if( tp[ l ] == 3 ){
      ll ans = 0;
      for( int i = k ; i >= 1 ; i -- )
        ans = ( ans * Q + dp[ i ] ) % mod7;
      printf( "%lld\n" , ans );
    }
    return;
  }
  int mid = ( l + r ) >> 1;
  cal( L( no ) , l , mid , dp );
  cal( R( no ) , mid + 1 , r , dp );
}
void solve(){
  vector<ll> dp( k + 1 , 0 );
  cal( 1 , 1 , q , dp );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
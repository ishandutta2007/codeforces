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
#define N 22
class matrix{
public:
  int _n;
  ll a[ N ][ N ];
  matrix(){}
  void reset(){
    for( int i = 0 ; i < _n ; i ++ )
      for( int j = 0 ; j < _n ; j ++ )
        a[ i ][ j ] = 0;
  }
  matrix( int __n , bool _i = false ){
    _n = __n;
    for( int i = 0 ; i < _n ; i ++ )
      for( int j = 0 ; j < _n ; j ++ ){
        a[ i ][ j ] = 0;
        if( _i && i == j )
          a[ i ][ j ] = 1;
      }
  }
  matrix operator*( const matrix& _m ){
    assert( _n == _m._n );
    matrix _tmp( _n );
    for( int i = 0 ; i < _n ; i ++ )
      for( int j = 0 ; j < _n ; j ++ )
        for( int k = 0 ; k < _n ; k ++ ){
          _tmp.a[ i ][ j ] +=
            ( a[ i ][ k ] * _m.a[ k ][ j ] ) % mod7;
          _tmp.a[ i ][ j ] %= mod7;
        }
    return _tmp;
  }
  matrix operator^( int tk ){
    matrix ta = (*this), ti( _n , true );
    while( tk ){
      if( tk & 1 ) ti = ti * ta;
      ta = ta * ta; tk >>= 1;
    }
    return ti;
  }
};
int n , m , q;
int trans( int tx , int ty ){
  return ( tx - 1 ) * m + ty - 1;
}
void build(){

}
void init(){
  n = getint(); m = getint(); q = getint();
}
bool in( int xn , int xm ){
  return 1 <= xn && xn <= n &&
         1 <= xm && xm <= m;
}
int dn[]={0,0,1,-1,0};
int dm[]={1,-1,0,0,0};
bool block[ N ][ N ];
void reset( matrix& x ){
  x.reset();
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      for( int k = 0 ; k < 5 ; k ++ ){
        int nxtn = i + dn[ k ];
        int nxtm = j + dm[ k ];
        if( in( nxtn , nxtm ) && !block[ nxtn ][ nxtm ] )
          x.a[ trans( nxtn , nxtm ) ][ trans( i , j ) ] = 1;
      }
}
vector<ll> dp;
vector<ll> operator*( const matrix& tx , const vector<ll>& ty ){
  assert( tx._n == (int)ty.size() );
  vector<ll> tmp;
  tmp.resize( tx._n );
  for( int i = 0 ; i < tx._n ; i ++ )
    tmp[ i ] = 0;
  for( int i = 0 ; i < tx._n ; i ++ )
    for( int j = 0 ; j < tx._n ; j ++ ){
      tmp[ i ] += ( tx.a[ i ][ j ] * ty[ j ] ) % mod7;
      tmp[ i ] %= mod7;
    }
  return tmp;
}
void solve(){
  matrix x( n * m );
  reset( x );
  dp.resize( n * m );
  for( int i = 0 ; i < n * m ; i ++ )
    dp[ i ] = 0;
  dp[ 0 ] = 1;
  int pret = 1;
  while( q -- ){
    int ty = getint();
    int xi = getint();
    int yi = getint();
    int ti = getint();
    if( ty == 1 ){
      matrix y = x ^ (ti - pret);
      dp = y * dp;
      printf( "%lld\n" , dp[ trans( xi , yi ) ] );
    }else if( ty == 2 ){
      int dlt = ti - pret - 1;
      if( dlt > 0 ){
        matrix y = x ^ dlt;
        dp = y * dp;
      }
      block[ xi ][ yi ] = true;
      reset( x );
      dp = x * dp;
    }else{
      int dlt = ti - pret;
      if( dlt > 0 ){
        matrix y = x ^ dlt;
        dp = y * dp;
      }
      block[ xi ][ yi ] = false;
      reset( x );
    }
    // for( int i = 0 ; i < n * m ; i ++ )
      // printf( "%lld%c" , dp[ i ] , " \n"[ i == n * m - 1 ] );
    pret = ti;
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
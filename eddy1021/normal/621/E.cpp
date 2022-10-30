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
#define N 111
struct Mat{
  int mat[ N ][ N ] , nn;
  Mat(){}
  Mat( int _nn ) : nn( _nn ) {
    for( int i = 0 ; i < _nn ; i ++ )
      for( int j = 0 ; j < _nn ; j ++ )
        mat[ i ][ j ] = 0;
  }
  Mat operator*( const Mat& mm ) const{
    assert( nn == mm.nn );
    Mat tmat( nn );
    for( int i = 0 ; i < nn ; i ++ )
      for( int j = 0 ; j < nn ; j ++ )
        for( int k = 0 ; k < nn ; k ++ )
          tmat.mat[ i ][ j ] = add( tmat.mat[ i ][ j ] , 
                                    mul( mat[ i ][ k ] , mm.mat[ k ][ j ] ) );
    return tmat;
  }
  Mat operator^( int tk ) const{
    Mat I( nn ) , A( nn );
    for( int i = 0 ; i < nn ; i ++ )
      I.mat[ i ][ i ] = 1;
    for( int i = 0 ; i < nn ; i ++ )
      for( int j = 0 ; j < nn ; j ++ )
        A.mat[ i ][ j ] = mat[ i ][ j ];
    while( tk ){
      if( tk & 1 ) I = I * A;
      A = A * A; tk >>= 1;
    }
    return I;
  }
};
int n , b , k , x;
int cnt[ 10 ];
void build(){

}
void init(){
  n = getint();
  b = getint();
  k = getint();
  x = getint();
  while( n -- )
    cnt[ getint() ] ++;
}
Mat a;
void solve(){
  a = Mat( x );
  for( int i = 0 ; i < x ; i ++ )
    for( int j = 0 ; j < 10 ; j ++ ){
      int tmp = ( i * 10 + j ) % x;
      a.mat[ tmp ][ i ] += cnt[ j ];
    }
  a = a ^ b;
  cout << a.mat[ k ][ 0 ] << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
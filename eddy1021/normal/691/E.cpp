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
#define N 111
struct Mat{
  int n , a[ N ][ N ];
  Mat(){
    n = 0;
  }
  Mat( int _n ){
    n = _n;
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        a[ i ][ j ] = 0;
  }
  Mat operator*( const Mat& tmp ){
    Mat res( n );
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        for( int k = 0 ; k < n ; k ++ )
          res.a[ i ][ j ] = add( res.a[ i ][ j ],
                                 mul( a[ i ][ k ] , tmp.a[ k ][ j ] ) );
    return res;
  }
  Mat operator^( LL k ){
    Mat A( n ) , I( n );
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ ){
        A.a[ i ][ j ] = a[ i ][ j ];
        I.a[ i ][ j ] = ( i == j ? 1 : 0 );
      }
    while( k ){
      if( k & 1 ) I = I * A;
      A = A * A; k >>= 1;
    }
    return I;
  }
};
void build(){

}
LL n , k , v[ N ];
void init(){
  n = getint(); k = getint();
  for( int i = 0 ; i < n ; i ++ )
    v[ i ] = getint();
}
Mat a;
void solve(){
  a = Mat( n );
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      if( __builtin_popcountll( v[ i ] ^ v[ j ] ) % 3 == 0 )
        a.a[ i ][ j ] = 1;
  a = a ^ ( k - 1 );
  int ans = 0;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      ans = add( ans , a.a[ i ][ j ] );
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
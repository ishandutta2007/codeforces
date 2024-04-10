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
void build(){

}
class Mat{
public:
  LL a[ 2 ][ 2 ];
  Mat(){
    for( int i = 0 ; i < 2 ; i ++ )
      for( int j = 0 ; j < 2 ; j ++ )
        a[ i ][ j ] = 0;
  }
  inline Mat operator*( const Mat& m1 ){
    Mat r;
    for( int i = 0 ; i < 2 ; i ++ )
      for( int j = 0 ; j < 2 ; j ++ )
        for( int k = 0 ; k < 2 ; k ++ )
          r.a[ i ][ j ] = add( r.a[ i ][ j ] , mul( a[ i ][ k ] , m1.a[ k ][ j ] ) );
    return r;
  }
  inline Mat operator^( LL tk ){
    Mat A , I;
    I.a[ 0 ][ 0 ] = I.a[ 1 ][ 1 ] = 1;
    for( int i = 0 ; i < 2 ; i ++ )
      for( int j = 0 ; j < 2 ; j ++ )
        A.a[ i ][ j ] = a[ i ][ j ];
    while( tk ){
      if( tk & 1 ) I = I * A;
      A = A * A; tk >>= 1;
    }
    return I;
  }
};
LL a , b , n , x;
void init(){
  a = getint();
  b = getint();
  n = getint();
  x = getint();
}
void solve(){
  Mat m;
  m.a[ 0 ][ 0 ] = a; m.a[ 0 ][ 1 ] = b;
  m.a[ 1 ][ 0 ] = 0; m.a[ 1 ][ 1 ] = 1;
  m = m ^ n;
  cout << add( mul( m.a[ 0 ][ 0 ] , x ) , m.a[ 0 ][ 1 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
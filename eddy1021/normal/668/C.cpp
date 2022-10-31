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
void build(){

}
int n;
LD p[ N ] , q[ N ] , sp , sq;
LD mx[ N ] , mn[ N ];
void scan( LD& f ){
  D tmp; scanf( "%lf" , &tmp );
  f = tmp;
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scan( mx[ i ] );
  for( int i = 1 ; i <= n ; i ++ )
    scan( mn[ i ] );
}
LD cal( LD kb , LD kc ){
  // printf( "%.6f %.6f\n" , (D)kb , (D)kc );
  if( kb * kb - 4.0 * kc < 0 ) return 0.0;
  LD r1 = ( -kb + sqrt( kb * kb - 4.0 * kc ) ) * 0.5;
  LD r2 = ( -kb - sqrt( kb * kb - 4.0 * kc ) ) * 0.5;
  if( r1 > -eps && r1 < 1.0 + eps ) return r1;
  if( r2 > -eps && r2 < 1.0 + eps ) return r2;
  return 0.0;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    if( i == n ){
      p[ i ] = 1.0 - sp;
      q[ i ] = 1.0 - sq;
      break;
    }
    q[ i ] = cal( -( mn[ i ] + mx[ i ] + sp - sq ) , mx[ i ] - sq * ( mn[ i ] + mx[ i ] ) );
    if( q[ i ] < 0.0 || q[ i ] > 1.0 ) q[ i ] = 0.0;
    p[ i ] = mn[ i ] + mx[ i ] - q[ i ];
    sp += p[ i ]; sq += q[ i ];
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%.12f%c" , (D)p[ i ] , " \n"[ i == n ] );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%.12f%c" , (D)q[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
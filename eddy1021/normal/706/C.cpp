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
#define N 101010
char c[ N << 2 ];
int n , s[ N ] , len[ N ] , t[ N ] , ptr;
LL v[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    v[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ ){
    s[ i ] = ptr;
    scanf( "%s" , c + ptr );
    len[ i ] = strlen( c + ptr );
    ptr += len[ i ] + 2;
    t[ i ] = s[ i ] + len[ i ] - 1;
  }
}
bool le( int ii , int jj , bool revi , bool revj ){
  int leni = len[ ii ] , lenj = len[ jj ];
  int sti = revi ? t[ ii ] : s[ ii ];
  int dli = revi ? -1 : 1;
  int stj = revj ? t[ jj ] : s[ jj ];
  int dlj = revj ? -1 : 1;
  for( int i = 0 ; i < min( leni , lenj ) ; i ++ ){
    if( c[ sti ] != c[ stj ] )
      return c[ sti ] < c[ stj ];
    sti += dli; stj += dlj;
  }
  return leni <= lenj;
}
LL dp[ N ][ 2 ];
void solve(){
  for( int i = 1 ; i < n ; i ++ )
    dp[ i ][ 0 ] = dp[ i ][ 1 ] = -1;
  dp[ 0 ][ 0 ] = 0;
  dp[ 0 ][ 1 ] = v[ 0 ];
  for( int i = 0 ; i + 1 < n ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ ){
      if( dp[ i ][ j ] < 0 ) continue;
      if( le( i , i + 1 , j , 0 ) ){
        LL tdp = dp[ i ][ j ];
        if( dp[ i + 1 ][ 0 ] == -1 || tdp < dp[ i + 1 ][ 0 ] )
          dp[ i + 1 ][ 0 ] = tdp;
      }
      if( le( i , i + 1 , j , 1 ) ){
        LL tdp = dp[ i ][ j ] + v[ i + 1 ];
        if( dp[ i + 1 ][ 1 ] == -1 || tdp < dp[ i + 1 ][ 1 ] )
          dp[ i + 1 ][ 1 ] = tdp;
      }
    }
  LL ans = -1;
  if( dp[ n - 1 ][ 0 ] >= 0 ) ans = dp[ n - 1 ][ 0 ];
  if( dp[ n - 1 ][ 1 ] >= 0 ){
    if( ans == -1 || dp[ n - 1 ][ 1 ] < ans )
      ans = dp[ n - 1 ][ 1 ];
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
#define N 222222
#define K 55
void build(){

}
int n , m , t[ N ];
LD dp[ N ][ K ];
LD k[ N ] , v[ N ] , sum[ N ] , a[ N ];
void init(){
  n = getint(); m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    t[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    sum[ i ] = sum[ i - 1 ] + t[ i ];
    k[ i ] = k[ i - 1 ] + sum[ i ] / (LD)t[ i ];
    v[ i ] = v[ i - 1 ] + 1.0 / (LD)t[ i ];
  }
}
pair<LD,LD> vv[ N + N ];
int ft , rr;
inline LD cal( LD xx ){
  if( rr - ft == 0 ) return 0;
  while( rr - ft > 1 &&
         ( vv[ ft + 1 ].Y - vv[ ft ].Y ) / ( vv[ ft ].X - vv[ ft + 1 ].X ) < xx )
    ft ++;
  return vv[ ft ].X * xx + vv[ ft ].Y;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    dp[ i ][ 1 ] = k[ i ];
  for( int j = 2 ; j <= m ; j ++ ){
    ft = rr = 0;
    for( int i = j - 1 ; i <= n ; i ++ ){
      if( i >= j )
        dp[ i ][ j ] = cal( v[ i ] ) + k[ i ];
      LD ak = -sum[ i ];
      LD bk = dp[ i ][ j - 1 ] - k[ i ] + v[ i ] * sum[ i ];
      while( rr - ft > 1 ){
        LD tx = ( vv[ rr - 2 ].Y - vv[ rr - 1 ].Y ) /
                ( vv[ rr - 1 ].X - vv[ rr - 2 ].X );
        LD nx = ( vv[ rr - 2 ].Y - bk ) /
                ( ak - vv[ rr - 2 ].X );
        if( nx < tx ) rr --;
        else break;
      }
      vv[ rr ++ ] = MP( ak , bk );
    }
  }
  printf( "%.12f\n" , (D)dp[ n ][ m ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
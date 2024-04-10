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
#define N 222
struct Mat{
  LL n , a[ N ][ N ];
  Mat(){
    n = 0;
    for( int i = 0 ; i < N ; i ++ )
      for( int j = 0 ; j < N ; j ++ )
        a[ i ][ j ] = -INF16;
  }
  Mat( int _n ){
    n = _n;
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        a[ i ][ j ] = -INF16;
  }
  Mat operator*( const Mat& tmp ){
    Mat res( n );
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        for( int k = 0 ; k < n ; k ++ )
          res.a[ i ][ j ] = max( res.a[ i ][ j ],
                                 a[ i ][ k ] + tmp.a[ k ][ j ] );
    return res;
  }
  void Pow( LL k ){
    Mat A( n ) , I( n );
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ ){
        A.a[ i ][ j ] = a[ i ][ j ];
        I.a[ i ][ j ] = ( i == j ? 0 : -INF16 );
      }
    while( k ){
      if( k & 1 ) I = I * A;
      A = A * A; k >>= 1;
    }
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        a[ i ][ j ] = I.a[ i ][ j ];
  }
};
LL n , l , a[ N ] , vl[ N ] , aa[ N ];
vector< string > vv;
int len[ N ];
void build(){

}
bool nxt[ N ][ N ];
inline void pre_cal(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ ){
      if( a[ j ] == 0 || len[ j ] > len[ i ] ) continue;
      for( int st = 0 ; st + len[ j ] <= len[ i ] ; st ++ )
        if( vv[ i ].substr( st , len[ j ] ) == vv[ j ] ){
          aa[ i ] += a[ j ];
          if( st + len[ j ] == len[ i ] )
            vl[ i ] += a[ j ];
        }
    }
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      if( len[ j ] == 1 ) nxt[ i ][ j ] = true;
      else if( len[ j ] - 1 <= len[ i ] ){
        if( vv[ j ].substr( 0 , len[ j ] - 1 ) ==
            vv[ i ].substr( len[ i ] - len[ j ] + 1 , len[ j ] - 1 ) )
          nxt[ i ][ j ] = true;
      }
}
void init(){
  n = getint(); l = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ ){
    string _ss; cin >> _ss;
    len[ i ] = _ss.length();
    vv.push_back( _ss );
  }
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 1 ; j < len[ i ] ; j ++ )
      vv.push_back( vv[ i ].substr( 0 , j ) );
  for( size_t i = n ; i < vv.size() ; i ++ )
    len[ i ] = vv[ i ].length();
  n = (int)vv.size();
}
LL pdp[ N + N ][ N ];
LL pp[ N ] , rr[ N ];
Mat A;
void solve(){
  pre_cal();
  for( int i = 1 ; i < N ; i ++ )
    for( int j = 0 ; j < n ; j ++ ){
      if( i >= len[ j ] )
        pdp[ i ][ j ] = max( pdp[ i ][ j ] , aa[ j ] );
      if( pdp[ i ][ j ] == 0 ) continue;
      for( int u = 0 ; u < n ; u ++ )
        if( nxt[ j ][ u ] )
          pdp[ i + 1 ][ u ] = max( pdp[ i + 1 ][ u ] ,
                                   pdp[ i ][ j ] + vl[ u ] );
    }
  if( l < N ){
    LL ans = 0;
    for( int i = 0 ; i < n ; i ++ )
      ans = max( ans , pdp[ l ][ i ] );
    printf( "%lld\n" , ans );
    exit( 0 );
  }
  A.n = n;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      if( nxt[ j ][ i ] ) A.a[ i ][ j ] = vl[ i ];
      else A.a[ i ][ j ] = -INF16;
  A.Pow( l - 221 );
  for( int i = 0 ; i < n ; i ++ )
    pp[ i ] = pdp[ 221 ][ i ];
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      rr[ i ] = max( rr[ i ] , A.a[ i ][ j ] + pp[ j ] );
  LL ans = 0;
  for( int i = 0 ; i < n ; i ++ )
    ans = max( ans , rr[ i ] );
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
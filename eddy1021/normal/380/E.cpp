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
#define N 303030
#define K 45
D p2[ K ];
void build(){
  p2[ 0 ] = 1;
  for( int i = 1 ; i < K ; i ++ )
    p2[ i ] = p2[ i - 1 ] * 2.0;
}
int n;
int a[ N ];
vector< PII > v;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    v.push_back( { a[ i ] , i } );
  }
  sort( ALL( v ) );
}
int tlft[ N ] , trgt[ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    tlft[ i ] = i - 1;
    trgt[ i ] = i + 1;
  }
  D ans = 0.0;
  for( size_t _ = 0 ; _ < v.size() ; _ ++ ){
    int i = v[ _ ].SE;
    D tl = 0.0 , tr = 0.0;
    int pl = i , pr = i;
    for( int j = 0 ; j < K ; j ++ ){
      if( pl != 0 ) tl += ( pl - tlft[ pl ] ) / p2[ j ] , pl = tlft[ pl ];
      if( pr <= n ) tr += ( trgt[ pr ] - pr ) / p2[ j ] , pr = trgt[ pr ];
    }
    tlft[ trgt[ i ] ] = tlft[ i ];
    trgt[ tlft[ i ] ] = trgt[ i ];
    ans += tl * tr * a[ i ] * 0.5;
  }
  printf( "%.12f\n" , ans / ( (D)n * (D)n ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
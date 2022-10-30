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
int n , k , x[ N ] , y[ N ] , xx[ N ];
vector<int> li;
vector< tuple<int,int,int,int> > vv;
void init(){
  n = getint(); 
  k = getint();
  for( int i = 0 ; i < n ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
    li.push_back( x[ i ] );
  }
  sort( ALL( li ) );
  li.resize( unique( ALL( li ) ) - li.begin() );
  for( int i = 0 ; i < n ; i ++ )
    xx[ i ] = lower_bound( ALL( li ) , x[ i ] ) - li.begin();
  for( int i = 0 ; i < n ; i ++ ){
    vv.push_back( MT( y[ i ]     , x[ i ] , xx[ i ] , +1 ) );
    vv.push_back( MT( y[ i ] + k , x[ i ] , xx[ i ] , -1 ) );
  }
  sort( ALL( vv ) );
}
int cnt[ N + N ] , cnt2[ N + N ];
LL ans[ N ];
void solve(){
  for( auto _ : vv ){
    int ny = get<0>( _ );
    int nx = get<1>( _ );
    int cx = get<2>( _ );
    int dt = get<3>( _ );
    for( int i = 0 ; i <= k + k ; i ++ ) cnt2[ i ] = 0;
    cnt2[ k - 1 ] = cnt[ cx ];
    for( int j = cx - 1 ; j >= 0 ; j -- ){
      int xxx = k - 1 + li[ j ] - nx;
      if( xxx < 0 ) break;
      cnt2[ xxx ] = cnt[ j ];
    }
    for( int j = cx + 1 ; j < (int)li.size() ; j ++ ){
      int xxx = k - 1 + li[ j ] - nx;
      if( xxx >= k + k - 1 ) break;
      cnt2[ xxx ] = cnt[ j ];
    }
    int sum = 0;
    for( int j = 0 ; j < k ; j ++ )
      sum += cnt2[ j ];
    for( int j = 0 ; j < k ; j ++ ){
      ans[ sum      ] += ny;
      ans[ sum + dt ] -= ny;
      sum += cnt2[ j + k ] - cnt2[ j ];
    }
    cnt[ cx ] += dt;
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld%c" , ans[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
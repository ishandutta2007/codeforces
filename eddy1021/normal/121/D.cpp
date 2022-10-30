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
#define INF18 1000000000000000000ll
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
vector<LL> lucky;
void go( LL now ){
  if( now ) lucky.push_back( now );
  if( now > INF18 ) return;
  go( now * 10 + 4 );
  go( now * 10 + 7 );
}
void build(){
  go( 0 );
  sort( ALL( lucky ) );
}
LL n , k , l[ N ] , r[ N ] , mn;
void init(){
  n = getint();
  k = getint();
  mn = INF18;
  for( int i = 0 ; i < n ; i ++ ){
    l[ i ] = getint();
    r[ i ] = getint();
    mn = min( mn , r[ i ] - l[ i ] + 1 );
  }
  sort( l , l + n );
  sort( r , r + n );
}
LD suml , sumr;
int lptr , rptr;
inline bool okay( LL lv , LL rv ){
  if( rv - lv + 1 > mn ) return false;
  while( lptr < n && l[ lptr ] <= lv )
    suml -= l[ lptr ++ ];
  while( rptr < n && r[ rptr ] < rv )
    sumr += r[ rptr ++ ];
  LD cstl = suml - (LD)( n - lptr ) * (LD)lv;
  LD cstr = (LD)rptr * (LD)rv - sumr;
  return cstl + cstr <= k;
}
void solve(){
  int ans = 0;
  size_t j = 0;
  for( int i = 0 ; i < n ; i ++ )
    suml += l[ i ];
  for( size_t i = 0 ; i < lucky.size() ; i ++ ){
    j = max( j , i );
    while( j < lucky.size() && okay( lucky[ i ] , lucky[ j ] ) ) j ++;
    ans = max( ans , (int)(j - i) );
  }
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
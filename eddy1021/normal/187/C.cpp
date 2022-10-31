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
vector<int> v[ N ];
int n , m , k , s , t , p[ N ];
void init_p(){
  for( int i = 0 ; i <= n ; i ++ )
    p[ i ] = i;
}
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x == y ) return;
  p[ x ] = y;
}
vector<int> vol;
void build(){

}
void init(){
  n = getint(); m = getint(); k = getint();
  for( int i = 0 ; i < k ; i ++ )
    vol.push_back( getint() );
  while( m -- ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  s = getint();
  t = getint();
  vol.push_back( s );
  vol.push_back( t );
  sort( ALL( vol ) );
  vol.resize( unique( ALL( vol ) ) - vol.begin() );
}
bool vst[ N ];
int dst[ N ] , from[ N ];
queue< PII > Q;
inline bool okay( int q ){
  init_p();
  for( int i = 0 ; i <= n ; i ++ )
    vst[ i ] = false;
  for( int i : vol ){
    Q.push( { 0 , i } );
    vst[ i ] = true;
    dst[ i ] = 0;
    from[ i ] = i;
  }
  while( Q.size() ){
    PII tp = Q.front(); Q.pop();
    int ndst = tp.FI , nn = tp.SE;
    for( int nxt : v[ nn ] ){
      if( vst[ nxt ] ){
        if( dst[ nxt ] + ndst + 1 <= q )
          Union( from[ nxt ] , from[ nn ] );
      }else{
        vst[ nxt ] = true;
        dst[ nxt ] = ndst + 1;
        from[ nxt ] = from[ nn ];
        Q.push( { dst[ nxt ] , nxt } );
      }
    }
  }
  return find_p( s ) ==
         find_p( t );
}
void solve(){
  int l = 0 , r = n + n + n , mid , ans = -1;
  while( l <= r ){
    mid = ( l + r ) >> 1;
    if( okay( mid ) ) ans = mid , r = mid - 1;
    else l = mid + 1;
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
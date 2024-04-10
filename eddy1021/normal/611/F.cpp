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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 505050
int n , h , w;
char c[ N ];
void build(){
}
int trans( char ctmp ){
  if( ctmp == 'U' ) return 0;
  if( ctmp == 'D' ) return 1;
  if( ctmp == 'L' ) return 2;
  if( ctmp == 'R' ) return 3;
  return -1;
}
int dh[]={-1,1,0,0};
int dw[]={0,0,-1,1};
int nh , nw , dlth , dltw;
int minh , minw , maxh , maxw;
ll ans;
void init(){
  n = getint();
  h = getint();
  w = getint();
  scanf( "%s" , c + 1 );
  for( int i = 1 ; i <= n && h && w ; i ++ ){
    ans = add( ans , mul( h , w ) );
    nh += dh[ trans( c[ i ] ) ];
    nw += dw[ trans( c[ i ] ) ];
    if( nh < minh || nh > maxh ) h --;
    if( nw < minw || nw > maxw ) w --;
    minh = min( minh , nh );
    minw = min( minw , nw );
    maxh = max( maxh , nh );
    maxw = max( maxw , nw );
  }
  if( nh == 0 && nw == 0 && ( h || w ) ){
    puts( "-1" );
    exit( 0 );
  }
}
vector<int> ii , di;
void solve(){
  for( int i = 1 ; i <= n && h && w ; i ++ ){
    ans = add( ans , mul( h , w ) );
    nh += dh[ trans( c[ i ] ) ];
    nw += dw[ trans( c[ i ] ) ];
    if( nh < minh || nh > maxh ){
      ii.PB( i );
      di.PB( 0 );
      h --;
    }
    if( nw < minw || nw > maxw ){
      ii.PB( i );
      di.PB( 1 );
      w --;
    }
    minh = min( minh , nh );
    minw = min( minw , nw );
    maxh = max( maxh , nh );
    maxw = max( maxw , nw );
  }
  int pre = 0 , ptr = 0;
  int _sz = (int)ii.size();
  while( h && w ){
    int now = ii[ ptr ];
    // printf( "%d %d : " , pre , now );
    // printf( "%d %d\n" , h , w );
    if( now <= pre ) pre -= n;
    ans = add( ans , mul( now - pre , mul( h , w ) ) );
    if( di[ ptr ] ) w --; else h --;
    ptr = ( ptr + 1 ) % _sz;
    pre = now;
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
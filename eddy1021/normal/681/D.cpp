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
int n , m , p[ N ] , a[ N ];
vector<int> v[ N ] , ans;
void init(){
  n = getint(); m = getint();
  while( m -- ){
    int pi = getint();
    int si = getint();
    p[ si ] = pi;
    v[ pi ].PB( si );
  }
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
}
set<int> S[ N ];
int no[ N ];
inline void merge( int i , int j ){
  if( S[ no[ i ] ].size() < S[ no[ j ] ].size() )
    swap( no[ i ] , no[ j ] );
  for( int x : S[ no[ j ] ] )
    S[ no[ i ] ].insert( x );
}
void go( int now ){
  S[ no[ now ] ].insert( a[ now ] );
  for( int son : v[ now ] ){
    go( son );
    merge( now , son );
  }
  if( S[ no[ now ] ].count( now ) &&
      S[ no[ now ] ].size() > 1 ){
    puts( "-1" );
    exit( 0 );
  }
  if( S[ no[ now ] ].count( now ) ){
    S[ no[ now ] ].erase( now );
    ans.push_back( now );
  }
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    no[ i ] = i;
  for( int i = 1 ; i <= n ; i ++ )
    if( !p[ i ] )
      go( i );
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
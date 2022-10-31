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
typedef pair<int,int> vl;
vl leaf = { 17 , 17 };
#define BS 13131
inline vl operator+( const vl& v1 , const vl& v2 ){
  return { ( ( v1.FI * BS ) ^ v2.FI ) % mod7 ,
           ( ( v1.SE * BS ) ^ v2.SE ) % mod9 };
  // return { add( mul( v1.FI , BS , mod7 ) , v2.FI , mod7 ) ,
           // add( mul( v1.SE , BS , mod9 ) , v2.SE , mod9 ) };
}
void build(){

}
int n , sz[ N ];
vector< int > v[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i < n ; i ++ ){
    int ai = getint();
    int bi = getint();
    v[ ai ].push_back( bi );
    v[ bi ].push_back( ai );
  }
}
vl hs[ N ];
void go( int now , int prt ){
  vector< vl > vv;
  int deg = (int)v[ now ].size();
  for( int son : v[ now ] ){
    if( son == prt ){
      deg --;
      continue;
    }
    go( son , now );
    vv.push_back( hs[ son ] );
    sz[ now ] += sz[ son ];
  }
  sz[ now ] ++;
  sort( vv.begin() , vv.end() );
  hs[ now ] = leaf;
  for( vl x : vv )
    hs[ now ] = hs[ now ] + x;
  hs[ now ] = hs[ now ] + make_pair( deg , deg );
  hs[ now ] = hs[ now ] + make_pair( sz[ now ] , sz[ now ] );
}
set< PII > S[ 9 ];
void go2( int now , int prt , vl pl ){
  vector< vl > vv;
  int deg = (int)v[ now ].size();
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    vv.push_back( hs[ son ] );
  }
  if( prt != -1 )
    vv.push_back( pl );
  sort( vv.begin() , vv.end() );
  vl thsh = leaf;
  for( vl x : vv )
    thsh = thsh + x;
  thsh = thsh + make_pair( deg , deg );
  thsh = thsh + make_pair( n , n );
  S[ deg ].insert( thsh );
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    vector< vl > tv;
    bool flag = false;
    for( vl x : vv )
      if( x == hs[ son ] && !flag )
        flag = true;
      else
        tv.push_back( x );
    sort( tv.begin() , tv.end() );
    thsh = leaf;
    for( vl x : tv )
      thsh = thsh + x;
    thsh = thsh + make_pair( deg - 1 , deg - 1 );
    thsh = thsh + make_pair( n - sz[ son ] , n - sz[ son ] );
    go2( son , now , thsh );
  }
}
void solve(){
  if( n == 1 ){
    puts( "1" );
    exit( 0 );
  }
  go( 1 , -1 );
  go2( 1 , -1 , { -1 , -1 } );
  int ans = 0;
  for( int i = 1 ; i < 4 ; i ++ )
    ans += (int)S[ i ].size();
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
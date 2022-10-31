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
#define P 50
vector<int> pp;
void build(){
  for( int i = 2 ; i < P ; i ++ ){
    bool isp = true;
    for( int j = 2 ; j < i ; j ++ )
      if( i % j == 0 )
        isp = false;
    if( isp )
      pp.push_back( i );
  }
}
void init(){
  
}
char ver[ 100 ];
inline bool verdict(){
  scanf( "%s" , ver );
  return ver[ 0 ] == 'y';
}
inline int test( int x ){
  printf( "%d\n" , x ); fflush( stdout );
  return verdict() ? 1 : 0;
}
void solve(){
  int is2 = test( 2 );
  int is3 = test( 3 );
  int is5 = test( 5 );
  int is7 = test( 7 );
  if( is2 + is3 + is5 + is7 == 0 ){
    puts( "prime" );
    fflush( stdout );
    exit( 0 );
  }
  if( is2 + is3 + is5 + is7 > 1 ){
    puts( "composite" );
    fflush( stdout );
    exit( 0 );
  }
  int x = 2;
  if( is3 ) x = 3;
  if( is5 ) x = 5;
  if( is7 ) x = 7;
  for( size_t i = 0 ; i < pp.size() ; i ++ ){
    if( x * pp[ i ] > 100 ) break;
    if( test( x * pp[ i ] ) ){
      puts( "composite" );
      fflush( stdout );
      exit( 0 );
    }
  }
  puts( "prime" );
  fflush( stdout );
  exit( 0 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
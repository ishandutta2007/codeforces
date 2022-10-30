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
#define N 1010101
void build(){

}
char c[ N ];
int len;
deque<int> f , b;
void init(){
  scanf( "%s" , c );
  len = strlen( c );
  bool dot = false , got = false;;
  for( int i = 0 ; i < len ; i ++ )
    if( c[ i ] == '.' ) dot = true;
    else if( !dot ){
      if( c[ i ] != '0' || got ){
        got = true;
        f.push_back( c[ i ] - '0' );
      }
    }else b.push_back( c[ i ] - '0' );
  while( b.size() && b.back() == 0 ) b.pop_back();
}
int ee;
void solve(){
  if( f.empty() && b.empty() ){
    puts( "0" );
    exit( 0 );
  }
  while( f.size() > 1 ){
    ee ++;
    b.push_front( f.back() );
    f.pop_back();
  }
  while( f.empty() ){
    ee --;
    if( b.front() )
      f.push_back( b.front() );
    b.pop_front();
  }
  while( b.size() && b.back() == 0 ) b.pop_back();
  printf( "%d" , f[ 0 ] );
  if( b.size() ){
    putchar( '.' );
    for( size_t i = 0 ; i < b.size() ; i ++ )
      printf( "%d" , b[ i ] );
  }
  if( ee ) printf( "E%d" , ee );
  puts( "" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
#define N 111
int n , m , k;
void build(){

}
vector<int> v;
char c[ N ];
int cnt[ 10 ];
bool rl , gl , cg , cr;
void init(){
  n = getint();
  m = getint();
  k = getint();
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s" , c );
    int got = -1; bool gg = false , rr = false , ss = false;;
    for( int j = 0 ; j < m ; j ++ )
      if( c[ j ] == 'R' || c[ j ] == 'G' ){
        if( c[ j ] == 'R' ){
          rr = true;
          if( got == -1 ) got = j;
          else if( gg ) v.PB( j - got - 1 );
        }else if( c[ j ] == 'G' ){
          gg = true;
          if( got == -1 ) got = j;
          else if( rr ) v.PB( j - got - 1 );
        }
      }else ss = true;
    if( gg && ss ) cg = true;
    if( rr && ss ) cr = true;
    if( gg && !rr && ss ) gl = true;
    if( !gg && rr && ss ) rl = true;
  }
  for( size_t i = 0 ; i < v.size() ; i ++ )
    for( int j = 0 ; j < 10 ; j ++ )
      if( ( v[ i ] >> j ) & 1 )
        cnt[ j ] ++;
}
void solve(){
  for( int i = 0 ; i < 10 ; i ++ )
    if( ( cnt[ i ] % ( k + 1 ) ) && !rl ){
      puts( "First" );
      exit( 0 );
    }
  if( !gl || !cg )
    puts( "Second" );
  else if( !cr )
    puts( "First" );
  else puts( "Draw" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
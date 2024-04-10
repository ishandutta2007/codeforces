// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
ll x;
void build(){

}
void init(){
  x = getint();
}
vector< pair<ll,ll> > ans;
bool cal( ll n ){
  ll bs = n * ( n + 1ll ) * ( 2ll * n + 1ll ) / 6ll;
  if( bs > x ) return false;
  ll bs2 = n * ( n + 1ll ) / 2ll;
  if( ( x - bs ) % bs2 == 0 )
    ans.PB( MP( n , n + ( x - bs ) / bs2 ) );
  return true;
}
void solve(){
  for( ll i = 1 ; i <= 1500000 ; i ++ )
    if( !cal( i ) )
      break;
  int an = (int)ans.size();
  for( int i = 0 ; i < an ; i ++ )
    ans.PB( MP( ans[ i ].SE , ans[ i ].FI ) );
  sort( ALL( ans ) );
  ans.resize( unique( ALL( ans ) ) - ans.begin() );
  printf( "%d\n" , (int)ans.size() );
  for( int i = 0 ; i < (int)ans.size() ; i ++ )
    printf( "%lld %lld\n" , ans[ i ].FI , ans[ i ].SE );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
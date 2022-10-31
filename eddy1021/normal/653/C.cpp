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
#define N 151515
int n , t[ N ];
void build(){

}
inline bool good( int x ){
  if( x < 1 || x > n ) return true;
  if( x & 1 ){
    if( x > 1 && t[ x ] >= t[ x - 1 ] )
      return false;
    if( x < n && t[ x ] >= t[ x + 1 ] )
      return false;
  }else{
    if( x > 1 && t[ x ] <= t[ x - 1 ] )
      return false;
    if( x < n && t[ x ] <= t[ x + 1 ] )
      return false;
  }
  return true;
}
vector<int> bad;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    t[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ )
    if( !good( i ) ){
      bad.PB( i );
      if( i > 1 ) bad.PB( i - 1 );
      if( i < n ) bad.PB( i + 1 );
    }
  sort( ALL( bad ) );
  bad.resize( unique( ALL( bad ) ) - bad.begin() );
}
bool okay(){
  for( size_t i = 0 ; i < bad.size() ; i ++ )
    if( !good( bad[ i ] ) )
      return false;
  return true;
}
set<PII> ans;
void solve(){
  if( (int)bad.size() > 20 ){
    puts( "0" );
    exit( 0 );
  }
  for( size_t i = 0 ; i < bad.size() ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      if( bad[ i ] == j ) continue;
      swap( t[ bad[ i ] ] , t[ j ] );
      if( okay() && good( j ) && good( j + 1 ) && good( j - 1 ) )
        ans.insert( MP( min( bad[ i ] , j ) , max( bad[ i ] , j ) ) );
      swap( t[ bad[ i ] ] , t[ j ] );
    }
  cout << (int)ans.size() << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
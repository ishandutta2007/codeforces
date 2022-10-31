// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
int __ = 1 , cs;
/*********default*********/
#define N 101010
void build(){

}
int n , p , q;
vector< PII > v , ch;
D ans = 1e40;
PII operator-( const PII& p1 , const PII& p2 ){
  return MP( p1.FI - p2.FI , p1.SE - p2.SE );
}
ll operator^( const PII& p1 , const PII& p2 ){
  return (ll)p1.FI * (ll)p2.SE -
         (ll)p1.SE * (ll)p2.FI;
}
void Convexhull(){
  sort( ALL( v ) );
  int sz = 0;
  for( int i = 0 ; i < (int)v.size() ; i ++ ){
    while( sz > 1 && ( ( ch[ sz - 1 ] - ch[ sz - 2 ] ) ^ ( v[ i ] - ch[ sz - 1 ] ) ) >= 0ll ){
      ch.pop_back(); sz --;
    }
    ch.PB( v[ i ] ); sz ++;
  }
  v = ch;
}
void init(){
  n = getint();
  p = getint();
  q = getint();
  int mx = 0 , my = 0;
  for( int i = 0 ; i < n ; i ++ ){
    int ai = getint();
    int bi = getint();
    ans = min( ans , max( (D)p / (D)ai , (D)q / (D)bi ) );
    v.PB( MP( ai , bi ) );
    mx = max( mx , ai );
    my = max( my , bi );
  }
  v.PB( MP( mx , 0 ) );
  v.PB( MP( 0 , my ) );
  Convexhull();
}
D cal( PII p1 , PII p2 ){
  D up = (D)p - (D)q * (D)p1.FI / (D)p1.SE;
  D dn = (D)p2.FI - (D)p2.SE * (D)p1.FI / (D)p1.SE;
  if( equal( dn , 0.0 ) ) return ans;
  D _y = up / dn;
  D _x = ( (D)p - (D)p2.FI * _y ) / (D)( p1.FI );
  if( _x < 0.0 || _y < 0.0 ) return ans;
  return _x + _y;
}
void solve(){
  for( int i = 1 ; i < (int)v.size() ; i ++ )
    // for( int j = i - 1 ; j >= max( 0 , i - 100 ) ; j -- )
    ans = min( ans , cal( v[ i - 1 ] , v[ i ] ) );
  printf( "%.12f\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 200010
int n , a[ N ] , ng[ N ];
void build(){
}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i < n ; i ++ )
    ng[ i ] = __gcd( i , n );
}
ll ans;
bool domi[ N ];
int mx[ N ] , ax[ N ];
int pdp[ N ];
void cal( int dlt ){
  for( int i = 0 ; i < n ; i ++ ){
    domi[ i ] = false;
    mx[ i ] = 0;
    ax[ i ] = 0;
  }
  pdp[ 0 ] = 0;
  for( int i = 1 ; i < n ; i ++ ){
    pdp[ i ] = pdp[ i - 1 ];
    if( ng[ i ] == dlt )
      pdp[ i ] ++;
  }
  for( int i = 0 ; i < n ; i ++ )
    mx[ i % dlt ] = max( mx[ i % dlt ] , a[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    if( mx[ i % dlt ] == a[ i ] )
      domi[ i ] = true;
  int tcnt = 0;
  for( int i = 0 ; i < 2 * n ; i ++ )
    if( domi[ i % n ] ){
      tcnt ++;
      tcnt = min( tcnt , n - 1 );
      ax[ i % n ] = max( ax[ i % n ] , tcnt );
    }else tcnt = 0;
  for( int i = 0 ; i < n ; i ++ )
    ans += pdp[ ax[ i ] ];
}
void solve(){
  for( int i = 1 ; i < n ; i ++ )
    if( n % i == 0 )
      cal( i );
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
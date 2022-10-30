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
#define N 1010
int cnt[ N ];
bool dp[ N ] , dp2[ N ];
int n , m;
void build(){

}
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ )
    cnt[ getint() % m ] ++;
  dp[ 0 ] = true;
}
void add( int x ){
  for( int i = 0 ; i <= m ; i ++ ) dp2[ i ] = dp[ i ];
  for( int i = 0 ; i < m ; i ++ ) if( dp[ i ] ){
    int nxt = ( i + x ) % m;
    if( nxt == 0 ) nxt = m;
    dp2[ nxt ] = true;
  }
  for( int i = 0 ; i <= m ; i ++ ) dp[ i ] = dp2[ i ];
}
void solve(){
  if( cnt[ 0 ] ){
    puts( "YES" );
    return;
  }
  for( int i = 1 ; i < m ; i ++ ){
    for( int j = 1 ; j <= cnt[ i ] ; j <<= 1 ){
      add( ( j * i ) % m );
      cnt[ i ] -= j;
    }
    if( cnt[ i ] )
      add( ( cnt[ i ] * i ) % m );
  }
  if( dp[ m ] ) puts( "YES" );
  else puts( "NO" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
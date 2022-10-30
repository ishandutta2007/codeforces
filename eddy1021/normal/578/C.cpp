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
ll n , a[ N ];
D b[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
}
D test( D x ){
  for( int i = 0 ; i < n ; i ++ )
    b[ i ] = (D)a[ i ] - x;
  D cmax = b[ 0 ] , cmin = b[ 0 ] , tmax = b[ 0 ] , tmin = b[ 0 ];
  if( tmax < 0 ) tmax = 0;
  if( tmin > 0 ) tmin = 0;
  for( int i = 1 ; i < n ; i ++ ){
    tmax += b[ i ];
    cmax = max( cmax , tmax );
    if( tmax < 0 ) tmax = 0;
    tmin += b[ i ];
    cmin = min( cmin , tmin );
    if( tmin > 0 ) tmin = 0;
  }
  if( cmax < 0 ) cmax *= -1;
  if( cmin < 0 ) cmin *= -1;
  return max( cmax , cmin );
}
void solve(){
  D l = -1e4 , r = 1e4 , m1 , m2 , ans = 2e9;
  for( int i = 0 ; i < 200 ; i ++ ){
    m1 = ( r - l ) / 3.0 + l;
    m2 = r - ( r - l ) / 3.0;
    D ans1 = test( m1 );
    D ans2 = test( m2 );
    if( ans1 < ans2 ){
      ans = min( ans , ans1 );
      r = m2;
    }else{
      ans = min( ans , ans2 );
      l = m1;
    }
  }
  printf( "%.12f\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
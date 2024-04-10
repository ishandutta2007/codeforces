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
bool isp( int x ){
  for( int i = 2 ; i < x ; i ++ )
    if( x % i == 0 )
      return false;
  return true;
}
void build(){

}
int n;
void init(){
  n = getint();
}
void solve(){
  if( n == 1 ){
    puts( "YES" );
    puts( "1" );
    return;
  }
  if( n == 4 ){
    puts( "YES" );
    puts( "1\n3\n2\n4" );
    return;
  }
  if( !isp( n ) ){
    puts( "NO" );
    return;
  }
  puts( "YES" );
  printf( "1\n" );
  int preinv = mypow( 1 , n - 2 , n );
  for( int i = 2 ; i < n ; i ++ ){
    printf( "%d\n" , ( (ll)preinv * (ll)i ) % n );
    preinv = mypow( i , n - 2 , n );
  }
  printf( "%d\n" , n );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
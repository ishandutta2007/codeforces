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
ll a , b;
void build(){

}
void init(){
  a = getint();
  b = getint();
}
void solve(){
  if( a == b ){
    cout << a << endl;
    return;
  }
  D x1 = -1 , x2 = -1;
  ll tmpa = a - b;
  ll lx = 1 , rx = 500000000 , midx , ax = -1;
  while( lx <= rx ){
    midx = ( lx + rx ) / 2;
    if( (D)tmpa / (D)( midx * 2 ) > (D)b - eps )
      ax = midx, lx = midx + 1;
    else rx = midx - 1;
  }
  if( ax != -1 ) x1 = (D)tmpa / (D)( ax * 2 );
  tmpa = a + b;
  lx = 1 , rx = 500000000 ,  ax = -1;
  while( lx <= rx ){
    midx = ( lx + rx ) / 2;
    if( (D)tmpa / (D)( midx * 2 ) > (D)b - eps )
      ax = midx, lx = midx + 1;
    else rx = midx - 1;
  }
  if( ax != -1 ) x2 = (D)tmpa / (D)( ax * 2 );
  if( x1 < 0 && x2 < 0 ) puts( "-1" );
  else if( x1 < 0 ) printf( "%.12f\n" , x2 );
  else if( x2 < 0 ) printf( "%.12f\n" , x1 );
  else printf( "%.12f\n" , min( x1 , x2 ) );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
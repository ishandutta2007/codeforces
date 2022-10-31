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
int n;
D r, v, s, f;
const D Pi = acos( -1.0 );
void build(){

}
void init(){
  n = getint();
  r = getint();
  v = getint();
}
D dlt;
bool okay( D trnd ){
  D dx = trnd * 2 * Pi * r;
  D res = trnd - (D)((int)trnd);
  D deg = Pi * res;
  D dltx = sin( deg ) * r;
  dx += 2.0 * dltx;
  return dx > dlt;
}
void solve(){
  while( n -- ){
    s = getint();
    f = getint();
    dlt = f - s;
    D bl = 0 , br = 1e20, bmid;
    for( int i = 0 ; i < 200 ; i ++ ){
      bmid = ( bl + br ) * 0.5;
      if( okay( bmid ) ) br = bmid;
      else bl = bmid;
    }
    D rnd = v / ( 2 * Pi * r );
    printf( "%.12f\n" , bmid / rnd );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
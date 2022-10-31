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
#define N 514
string ansx;
string ansy;
int n , x[ N ] , y[ N ] , r[ N ];
void build(){
}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
    r[ i ] = getint();
  }
}
string toString( int tmp ){
  string ts;
  if( tmp < 10 ){
    ts = "0";
    while( tmp -- ) ts[ 0 ] ++;
  }else{
    ts = "00";
    int tx = tmp / 10 , ty = tmp % 10;
    while( tx -- ) ts[ 0 ] ++;
    while( ty -- ) ts[ 1 ] ++;
  }
  return ts;
}
string cali( int i ){
  return "((1-abs((t-" + toString( i ) + ")))+abs((abs((t-"
                       + toString( i ) + "))-1)))";
}
string calx( int idx ){
  return "(" + toString( x[ idx ] / 2 ) + "*" + cali( idx ) + ")";
}
string caly( int idx ){
  return "(" + toString( y[ idx ] / 2 ) + "*" + cali( idx ) + ")";
}
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    string tmpx = calx( i );
    string tmpy = caly( i );
    if( i ){
      ansx = "(" + ansx + "+" + tmpx + ")";
      ansy = "(" + ansy + "+" + tmpy + ")";
    }else ansx = tmpx, ansy = tmpy;
  }
  cout << ansx << endl;
  cout << ansy << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
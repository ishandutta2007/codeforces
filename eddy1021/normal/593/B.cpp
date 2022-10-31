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
#define N 1000010
ll n , x1 , x2;
ll k[ N ] , b[ N ];
vector< pair<ll,ll> > v;
void build(){

}
void init(){
  n = getint();
  x1 = getint();
  x2 = getint();
  for( int i = 0 ; i < n ; i ++ ){
    k[ i ] = getint();
    b[ i ] = getint();
    v.PB( MP( x1 * k[ i ] + b[ i ],
              x2 * k[ i ] + b[ i ] ) );
  }
  sort( v.begin() , v.end() );
  v.resize( unique( ALL( v ) ) - v.begin() );
}
void solve(){
  if( (int)v.size() != n ){
    puts( "Yes" );
    return;
  }
  ll tmx = -10000000000000000ll;
  for( int i = 0 ; i < n ; ){
    int j = i;
    while( j < n && v[ j ].FI == v[ i ].FI ) j ++;
    for( int u = i ; u < j ; u ++ )
      if( v[ u ].SE < tmx ){
        puts( "Yes" );
        return;
      }
    for( int u = i ; u < j ; u ++ )
      tmx = max( tmx , v[ u ].SE );
    i = j;
  }
  puts( "No" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
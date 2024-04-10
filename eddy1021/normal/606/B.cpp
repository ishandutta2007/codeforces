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
#define N 514
int x , y;
bool in( int _x , int _y ){
  return 1 <= _x && _x <= x &&
         1 <= _y && _y <= y;
}
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int trans( char ctmp ){
  if( ctmp == 'U' ) return 0;
  if( ctmp == 'D' ) return 1;
  if( ctmp == 'L' ) return 2;
  if( ctmp == 'R' ) return 3;
  return -1;
}
void build(){

}
bool got[ N ][ N ];
int xx , yy;
char c[ N * N ];
void init(){
  x = getint(); y = getint();
  xx = getint(); yy = getint();
  scanf( "%s" , c );
}
void go( int dir ){
  int nxtx = xx + dx[ dir ];
  int nxty = yy + dy[ dir ];
  if( in( nxtx , nxty ) )
    xx = nxtx, yy = nxty;
}
void solve(){
  int cnt = 0 , len = strlen( c );
  for( int i = 0 ; i < len ; i ++ ){
    // printf( "\n(%d %d)\n" , xx , yy );
    if( got[ xx ][ yy ] ) printf( "0 " );
    else printf( "1 " ), cnt ++;
    got[ xx ][ yy ] = true;
    go( trans( c[ i ] ) );
  }
  printf( "%d\n" , x * y - cnt );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
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
int n, cnt[ 26 ];
char c[ N ][ N ];
int len[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s" , c[ i ] );
    len[ i ] = strlen( c[ i ] );
  }
}
int test( int idxi , int idxj ){
  int tsum = 0;
  for( int i = 0 ; i < n ; i ++ ){
    bool ok = true;
    for( int j = 0 ; j < len[ i ] ; j ++ )
      if( c[ i ][ j ] - 'a' != idxi &&
          c[ i ][ j ] - 'a' != idxj )
        ok = false;
    if( ok ) tsum += len[ i ];
  }
  return tsum;
}
void solve(){
  int ans = 0;
  for( int i = 0 ; i < 26 ; i ++ )
    for( int j = i + 1 ; j < 26 ; j ++ )
      ans = max( ans , test( i , j ) );
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
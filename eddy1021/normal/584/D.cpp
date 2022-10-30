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
#define N 34000
bool p[ N ];
vector<int> pset;
void build(){
  p[ 0 ] = p[ 1 ];
  for( int i = 2 ; i < N ; i ++ ) if( !p[ i ] ){
    pset.PB( i );
    for( int j = N / i ; j >= i ; j -- ) p[ i * j ] = true;
  }
  p[ 2 ] = true;
}
bool isp( int x ){
  if( x < N ) return !p[ x ];
  for( int i = 0 ; i < (int)pset.size() &&
                   pset[ i ] * pset[ i ] <= x ; i ++ )
    if( x % pset[ i ] == 0 )
      return false;
  return true;
}
int n;
void init(){
  n = getint();
}
void solve(){
  if( isp( n ) ) printf( "1\n%d\n" , n );
  else{
    for( int x = n - 2 ; ; x -- )
      if( isp( x ) ){
        int res = n - x;
        if( isp( res ) ){
          printf( "2\n%d %d\n" , x , n - x );
          return;
        }
        for( int j = 2 ; j <= res / 2 ; j ++ )
          if( isp( j ) && isp( res - j ) ){
            printf( "3\n%d %d %d\n" , x , j , res - j );
            return;
          }
      }
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
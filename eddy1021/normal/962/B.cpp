#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 202020
int n , a , b;
char c[ N ];
int main(){
  scanf( "%d%d%d" , &n , &a , &b );
  scanf( "%s" , c );
  vector<int> v[ 2 ];
  vector<int> zaza;
  int s = 0;
  for( int i = 0 ; c[ i ] ; i ++ )
    if( c[ i ] == '.' ) s ++;
    else if( s ){
      v[ s & 1 ].push_back( s );
      s = 0;
    }
  if( s ) v[ s & 1 ].push_back( s );
  int ans = 0;
  for( int x : v[ 0 ] ){
    int tk = min( a , min( b , x / 2 ) );
    ans += tk + tk;
    a -= tk;
    b -= tk;
    if( tk + tk < x )
      zaza.push_back( x - (tk + tk) );
  }
  for( int x : v[ 1 ] ){
    if( a > b ) swap( a , b );
    int tk = min( a , x / 2 );
    int tk2 = min( b , tk + 1 );
    ans += tk + tk2;
    a -= tk;
    b -= tk2;
    if( tk + tk2 < x )
      zaza.push_back( x - (tk + tk2) );
  }
  if( a == 0 or b == 0 ){
    a += b;
    for( int x : zaza ){
      int tk = min( a , (x + 1) / 2 );
      a -= tk;
      ans += tk;
    }
  }
  cout << ans << endl;
}
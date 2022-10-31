#include <bits/stdc++.h>
using namespace std;
int n , a[ 11 ][ 11 ] , ans;
int read( int xn , int xm ){
  bool flag = xn < n;
  flag ?
    ( xm >= n ? read( xn + 1 , 0 ) :
      ( scanf( "%d" , &a[ xn ][ xm ] ),
        read( xn , xm + 1 ) ) ) :
    flag = false;
  return 0;
}
void init(){
  scanf( "%d" , &n );
  read( 0 , 0 );
}
int gogo( int xn , int xm , int md ){
  bool flag = true;
  md < n ? (
    a[ xn ][ xm ] = min( a[ xn ][ xm ] , a[ xn ][ md ] + a[ md ][ xm ] ),
    gogo( xn , xm , md + 1 )
      ) : flag = false;
  return 0;
}
int relax( int xn , int xm ){
  bool flag = xn < n;
  flag ?
    ( xm >= n ? relax( xn + 1 , 0 ) :
      ( gogo( xn , xm , 0 ),
        relax( xn , xm + 1 ) ) ) :
    flag = false;
  return 0;
}
int find_ans( int xn , int xm ){
  bool flag = xn < n;
  flag ?
    ( xm >= n ? find_ans( xn + 1 , 0 ) :
      ( ans = max( ans , a[ xn ][ xm ] ),
        find_ans( xn , xm + 1 ) ) ) :
    flag = false;
  return 0;
}
void solve(){
  relax( 0 , 0 );
  relax( 0 , 0 );
  relax( 0 , 0 );
  relax( 0 , 0 );
  relax( 0 , 0 );
  relax( 0 , 0 );
  relax( 0 , 0 );
  relax( 0 , 0 );
  relax( 0 , 0 );
  relax( 0 , 0 );
  find_ans( 0 , 0 );
  cout << ans << endl;
}
int main(){
  init();
  solve();
}
#include <bits/stdc++.h>
using namespace std;
#define N 10101
typedef double D;
const D eps = 1e-9;
int n , w , v , u;
void init(){
  scanf( "%d%d%d%d" , &n, &w, &v, &u );
}
void solve(){
  D lft = 1e20 , rgt = 0;
  while( n -- ){
    D x , y; scanf( "%lf%lf" , &x , &y );
    D dltt = x / v - y / u;
    lft = min( lft , dltt );
    rgt = max( rgt , dltt );
  }
  D ans = (D)w / u;
  if( lft < -eps ) ans += rgt;
  printf( "%.12f\n" , ans );
}
int main(){
  init();
  solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL l1 , r1 , l2 , r2 , k;
int main(){
  scanf( "%lld%lld%lld%lld%lld" , &l1 , &r1 , &l2 , &r2 , &k );
  l1 = max( l1 , l2 );
  r1 = min( r1 , r2 );
  printf( "%lld\n" , max( 0ll , ( r1 - l1 + 1 ) - ( l1 <= k && k <= r1 ) ) );
}
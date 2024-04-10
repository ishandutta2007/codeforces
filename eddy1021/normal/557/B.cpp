#include <bits/stdc++.h>
using namespace std;
int n , w;
vector<int> v;
int main(){
  scanf( "%d%d" , &n , &w );
  v.resize( n + n );
  for( int i = 0 ; i < n + n ; i ++ )
    scanf( "%d" , &v[ i ] );
  sort( v.begin() , v.end() );
  int xx = min( v[ n ] , v[ 0 ] + v[ 0 ] );
  long long ans = (long long)xx * 3ll * n;
  ans = min( ans , (long long)( w + w ) );
  printf( "%lld.%lld\n" , ans / 2 , ans % 2 * 5 );
}
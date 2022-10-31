#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n , k;
vector<LL> ans;
int main(){
  scanf( "%lld%lld" , &n , &k );
  vector<LL> d;
  LL tar = ( k + 1 ) * k / 2;
  if( k > 1000000 ) tar = 1e12;
  for( LL i = 1 ; i * i <= n ; i ++ )
    if( n % i == 0 ){
      d.push_back( i );
      d.push_back( n / i );
    }
  sort( d.begin() , d.end() );
  reverse( d.begin() , d.end() );
  for( auto dd : d ){
    LL ret = n / dd;
    if( ret >= tar ){
      for( LL i = 0 , nd = 1 ; i < k ; i ++ , nd ++ ){
        LL tmp = ( i + 1 == k ? n : dd * nd );
        printf( "%lld%c" , tmp , " \n"[ i + 1 == k ] );
        n -= dd * nd;
      }
      exit( 0 );
    }
  }
  puts( "-1" );
}
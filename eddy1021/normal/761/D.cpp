#include <bits/stdc++.h>
using namespace std;
#define N 101010
typedef long long LL;
LL n , l , r , a[ N ] , b[ N ] , p[ N ];
void solve(){
  vector< pair<LL,LL> > v;
  for( int i = 1 ; i <= n ; i ++ )
    v.push_back( { p[ i ] , i } );
  sort( v.begin() , v.end() );
  LL mn = -2e9;
  for( auto _ : v ){
    int idx = _.second;
    LL minc = max( mn , l - a[ idx ] );
    b[ idx ] = minc + a[ idx ];
    if( b[ idx ] < l || b[ idx ] > r ){
      puts( "-1" );
      exit( 0 );
    }
    mn = minc + 1;
  }
}
int main(){
  scanf( "%lld%lld%lld" , &n , &l , &r );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%lld" , &a[ i ] );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%lld" , &p[ i ] );
  solve();
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld%c" , b[ i ] , " \n"[ i == n ] );
}
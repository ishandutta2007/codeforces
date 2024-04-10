#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define L first
#define R second
#define MX 1001021
#define N 101010
typedef long long LL;
LL n , s;
LL x[ N ] , v[ N ] , t[ N ];
inline LL getint(){
  LL ret; scanf( "%lld" , &ret );
  return ret;
}
void init(){
  n = getint();
  s = getint();
  for( int i = 0 ; i < n ; i ++ ){
    x[ i ] = getint();
    v[ i ] = getint();
    t[ i ] = getint();
    if( t[ i ] == 2 )
      x[ i ] = 1000000 - x[ i ];
  }
}
LL tg[ MX ];
bool okay( double tar ){
  vector< pair<int,int> > v1 , v2;
  for( int i = 0 ; i < n ; i ++ )
    if( t[ i ] == 1 ){
      if( (double)x[ i ] / v[ i ] < tar ){
        v1.push_back( { 0 , 1000000 } );
        continue;
      }
      double bst = (double)x[ i ] / ( v[ i ] + s );
      if( bst > tar ) continue;
      double dlt = ( tar - (double)x[ i ] / ( s + v[ i ] ) );
      dlt /= ( 1. / ( s - v[ i ] ) -
               (double)v[ i ] / ( s - v[ i ] ) / ( s + v[ i ] ) );
      int atmst = min( 1000000LL , (LL)(x[ i ] + dlt) );
      v1.push_back( { x[ i ] , atmst } );
    }else{
      if( (double)x[ i ] / v[ i ] < tar ){
        v2.push_back( { 0 , 1000000 } );
        continue;
      }
      double bst = (double)x[ i ] / ( v[ i ] + s );
      if( bst > tar ) continue;
      double dlt = ( tar - (double)x[ i ] / ( s + v[ i ] ) );
      dlt /= ( 1. / ( s - v[ i ] ) -
               (double)v[ i ] / ( s - v[ i ] ) / ( s + v[ i ] ) );
      int atmst = min( 1000000LL , (LL)(x[ i ] + dlt) );
      v2.push_back( { 1000000 - atmst , 1000000 - x[ i ] } );
    }
  for( int i = 0 ; i < MX ; i ++ )
    tg[ i ] = 0;
  for( auto i : v1 ){
    tg[ i.L + 1 ] ++;
    tg[ i.R + 2 ] --;
  }
  for( int i = 1 ; i < MX ; i ++ )
    tg[ i ] += tg[ i - 1 ];
  for( int i = 1 ; i < MX ; i ++ )
    tg[ i ] += tg[ i - 1 ];
  for( auto i : v2 )
    if( tg[ i.R + 1 ] - tg[ i.L ] > 0 )
      return true;
  return false;
}
void solve(){
  //cout << okay( 400 ) << endl;
  //exit(0);
  double l = 0 , r = 1e7;
  for( int i = 0 ; i < 60 ; i ++ ){
    double mid = ( l + r ) * 0.5;
    if( okay( mid ) ) r = mid;
    else l = mid;
  }
  printf( "%.9f\n" , ( l + r ) * 0.5 );
}
int main(){
  init();
  solve();
}
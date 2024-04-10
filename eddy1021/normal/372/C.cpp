// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 151515
typedef long long LL;
pair<LL,LL> dq[ N ];
int dq_f , dq_e;
inline void dq_push_back( pair<LL,LL> x ){
  dq[ dq_e ++ ] = x;
}
inline pair<LL,LL> dq_front(){
  return dq[ dq_f ];
}
inline pair<LL,LL> dq_back(){
  return dq[ dq_e - 1 ];
}
inline void dq_pop_front(){
  dq_f ++;
}
inline void dq_pop_back(){
  dq_e --;
}
LL n , m , d , a[ N ] , b[ N ] , t[ N ];
void init(){
  scanf( "%lld%lld%lld" , &n , &m , &d );
  for( int i = 1 ; i <= m ; i ++ )
    scanf( "%lld%lld%lld" , &a[ i ] , &b[ i ] , &t[ i ] );
}
LL dp[ 2 ][ N ] , cst[ N ];
void solve(){
  int now = 0 , pre = 1;
  for( int l = 1 , r = 1 ; l <= m ; l = r ){
    swap( now , pre );
    while( r <= m && t[ l ] == t[ r ] ) r ++;
    for( int i = 1 ; i <= n ; i ++ ){
      cst[ i ] = 0;
      for( int j = l ; j < r ; j ++ )
        cst[ i ] += b[ j ] - abs( a[ j ] - i );
    }
    LL dlt = ( t[ l ] - t[ l - 1 ] ) * d;
    dq_f = dq_e = 0;
    LL ptr = 1;
    for( LL i = 1 ; i <= n ; i ++ ){
      while( dq_f != dq_e && dq_front().first < i - dlt )
        dq_pop_front();
      while( ptr <= min( n , i + dlt ) ){
        while( dq_f != dq_e && dq_back().second <= dp[ pre ][ ptr ] )
          dq_pop_back();
        dq_push_back( { ptr , dp[ pre ][ ptr ] } );
        ptr ++;
      }
      dp[ now ][ i ] = cst[ i ] + dq_front().second;
    }
  }
  LL ans = dp[ now ][ 1 ];
  for( int i = 1 ; i <= n ; i ++ )
    ans = max( ans , dp[ now ][ i ] );
  printf( "%lld\n" , ans );
}
int main(){
  init();
  solve();
}
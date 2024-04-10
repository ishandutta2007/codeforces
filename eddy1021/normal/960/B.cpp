#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1021
int n , k1 , k2;
LL a[ N ] , b[ N ];
priority_queue<LL> heap;
LL sqr( LL x ){ return x * x; }
int main(){
  scanf( "%d" , &n );
  scanf( "%d" , &k1 );
  scanf( "%d" , &k2 );
  k1 += k2;
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &a[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &b[ i ] );
  LL ans = 0;
  for( int i = 0 ; i < n ; i ++ ){
    heap.push( abs( a[ i ] - b[ i ] ) );
    ans += sqr( a[ i ] - b[ i ] );
  }
  while( k1 -- ){
    LL x = heap.top(); heap.pop();
    ans -= sqr( x );
    x = abs(x - 1);
    heap.push( x );
    ans += sqr( x );
  }
  cout << ans << endl;
}
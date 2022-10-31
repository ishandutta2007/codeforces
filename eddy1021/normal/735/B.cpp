#include <bits/stdc++.h>
using namespace std;
priority_queue<int> heap;
int n[ 3 ] , x;
int main(){
  scanf( "%d%d%d" , &n[ 0 ] , &n[ 1 ] , &n[ 2 ] );
  while( n[ 0 ] -- ){
    scanf( "%d" , &x ); heap.push( x );
  }
  if( n[ 1 ] > n[ 2 ] ) swap( n[ 1 ] , n[ 2 ] );
  double ans = 0.0;
  for( int i = 1 ; i <= 2 ; i ++ ){
    double sum = 0.0;
    for( int j = 0 ; j < n[ i ] ; j ++ )
      sum += heap.top(), heap.pop();
    ans += sum / n[ i ];
  }
  printf( "%.12f\n" , ans );
}
#include <bits/stdc++.h>
using namespace std;
#define N 202020
int n , m , a[ N ] , k[ N ] , nd;
int main(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  for( int i = 1 ; i <= m ; i ++ ){
    scanf( "%d" , &k[ i ] );
    if( k[ i ] ) nd ++;
  }
  int tot = accumulate( k , k + m + 1 , 0 );
  int ans = -1;
  for( int l = 1 , r = 1 ; l <= n ; l ++ ){
    while( r <= n and nd > 0 ){
      k[ a[ r ] ] --;
      if( k[ a[ r ] ] == 0 ) nd --;
      r ++;
    }
    if( nd == 0 ){
      int tans = r - l - tot;
      if( ans == -1 or tans < ans )
        ans = tans;
    }else if( r > n ) break;
    k[ a[ l ] ] ++;
    if( k[ a[ l ] ] > 0 ) nd ++;
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 111
int cst[ 4 ][ 2 ];
int n , b[ N ][ N ];
char buf[ N ];
int main(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < 4 ; i ++ ){
    for( int j = 0 ; j < n ; j ++ ){
      scanf( "%s" , buf );
      for( int k = 0 ; k < n ; k ++ ){
        int x = buf[ k ] - '0';
        if( (j + k) & 1 )
          cst[ i ][ 1 - x ] ++;
        else
          cst[ i ][ x ] ++;
      }
    }
  }
  int ans = n * n * 4;
  int id[] = {0,1,2,3};
  do{
    int tans = 0;
    for( int i = 0 ; i < 4 ; i ++ )
      tans += cst[ id[ i ] ][ i & 1 ];
    ans = min( ans , tans );
  }while( next_permutation( id , id + 4 ) );
  cout << ans << endl;
}
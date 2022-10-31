#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
pair<LL,LL> c25( LL x ){
  LL c2 = 0 , c5 = 0;
  {
    LL tx = x;
    while( tx % 2 == 0 ){
      c2 ++;
      tx /= 2;
    }
  }
  {
    LL tx = x;
    while( tx % 5 == 0 ){
      c5 ++;
      tx /= 5;
    }
  }
  return {c2, c5};
}
#define N 202
#define X 3601
int dp[ N ][ X ];
int n , k;
int main(){
  cin >> n >> k;
  //n = 200;
  //k = 200;
  for( int i = 0 ; i <= k ; i ++ )
    for( int j = 0 ; j < X ; j ++ )
      dp[ i ][ j ] = -1;
  dp[ 0 ][ 0 ] = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    LL tmp;
    cin >> tmp;
    //tmp = (LL)rand() * rand();
    //cerr << tmp << endl;
    pair<LL,LL> c = c25( tmp );
    for( int j = k - 1 ; j >= 0 ; j -- )
      for( int y = X - 1 ; y >= 0 ; y -- ){
        if( dp[ j ][ y ] == -1 ) continue;
        int ny = min( (LL)X - 1 , y + c.second );
        int tdp = dp[ j ][ y ] + c.first;
        dp[ j + 1 ][ ny ] = max( dp[ j + 1 ][ ny ] , tdp );
      }
  }
  int ans = 0;
  for( int i = 0 ; i < X ; i ++ )
    ans = max( ans , min( i , dp[ k ][ i ] ) );
  cout << ans << endl;
}
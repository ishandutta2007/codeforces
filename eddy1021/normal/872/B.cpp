#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n , k , a[ N ];
int main(){
  cin >> n >> k;
  for( int i = 0 ; i < n ; i ++ )
    cin >> a[ i ];
  if( k == 1 )
    cout << *min_element( a , a + n ) << endl;
  else if( k >= 3 )
    cout << *max_element( a , a + n ) << endl;
  else{
    int ans = -1e9;
    for( int i = 0 , mn = 1e9 ; i + 1 < n ; i ++ ){
      mn = min( mn , a[ i ] );
      ans = max( ans , mn );
    }
    for( int i = n - 1 , mn = 1e9 ; i ; i -- ){
      mn = min( mn , a[ i ] );
      ans = max( ans , mn );
    }
    cout << ans << endl;
  }
}
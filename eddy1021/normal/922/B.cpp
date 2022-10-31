#include <bits/stdc++.h>
using namespace std;
int main(){
  int ans = 0;
  int n; cin >> n;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = i ; j <= n ; j ++ ){
      int k = i ^ j;
      if( k < j ) continue;
      if( k > n ) continue;
      if( i + j > k )
        ans ++;
    }
  cout << ans << endl;
}
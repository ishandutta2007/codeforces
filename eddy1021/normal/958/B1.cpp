#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , deg[ N ];
int main(){
  cin >> n;
  for( int i = 1 ; i < n ; i ++ ){
    int a , b;
    cin >> a >> b;
    deg[ a ] ++;
    deg[ b ] ++;
  }
  int ans = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( deg[ i ] == 1 )
      ans ++;
  cout << ans << endl;
}
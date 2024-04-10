#include <bits/stdc++.h>
using namespace std;
vector<int> v[101010];
int main(){
  int n , k , m , x;
  cin >> n >> k >> m; while( n -- ){
    cin >> x;
    v[ x % m ].push_back( x );
  }
  for( int i = 0 ; i < m ; i ++ )
    if( v[ i ].size() >= k ){
      cout << "Yes\n";
      for( int j = 0 ; j < k ; j ++ )
        cout << v[ i ][ j ] << " \n"[ j + 1 == k ];
      exit(0);
    }
  cout << "No\n";
}
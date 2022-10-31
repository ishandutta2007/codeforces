#include <bits/stdc++.h>
using namespace std;
#define N 111
int n , m , k;
int ans , chg , a[ N ][ N ];
void cal( int col ){
  vector<int> v;
  for( int i = 0 ; i < n ; i ++ )
    v.push_back( a[ i ][ col ] );
  int bst = 0 , bchg = 0;
  for( int i = 0 , pre = 0 ; i < n ; i ++ ){
    int sc = 0;
    for( int j = 0 ; i + j < n and j < k ; j ++ )
      sc += v[ i + j ];
    if( sc > bst or ( sc == bst and pre < bchg ) ){
      bst = sc;
      bchg = pre;
    }
    pre += v[ i ];
  }
  ans += bst;
  chg += bchg;
}
int main(){
  cin >> n >> m >> k;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      cin >> a[ i ][ j ];
  for( int j = 0 ; j < m ; j ++ )
    cal( j );
  cout << ans << " ";
  cout << chg << "\n";
}
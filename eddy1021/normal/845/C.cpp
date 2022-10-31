#include <bits/stdc++.h>
using namespace std;
int tv[ 2 ] , n;
pair<int,int> v[ 201021 ];
int main(){
  cin >> n;
  for( int i = 0 ; i < n ; i ++ )
    cin >> v[ i ].first >> v[ i ].second;
  sort( v , v + n );
  tv[ 0 ] = -1; tv[ 1 ] = -1;
  for( int i = 0 ; i < n ; i ++ ){
    int ok = 0;
    for( int j = 0 ; j < 2 ; j ++ )
      if( tv[ j ] < v[ i ].first ){
        ok = 1;
        tv[ j ]=  v[ i ].second;
        break;
      }
    if( !ok ){
      cout << "NO" << endl;
      exit(0);
    }
  }
  cout << "YES" << endl;
}
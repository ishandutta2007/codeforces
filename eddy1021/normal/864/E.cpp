#include <bits/stdc++.h>
using namespace std;
#define N 111
int n , t[ N ] , d[ N ] , p[ N ] , id[ N ];
bool cmp( int x , int y ){
  return d[ x ] < d[ y ];
}
#define K 2222
int dp[ N ][ K ] , bk[ N ][ K ];
int main(){
  cin >> n;
  for( int i = 1 ; i <= n ; i ++ ){
    cin >> t[ i ] >> d[ i ] >> p[ i ];
    id[ i ] = i;
    d[ i ] --;
  }
  sort( id + 1 , id + n + 1 , cmp );
  for( int _ = 1 ; _ <= n ; _ ++ ){
    int i = id[ _ ];
    for( int j = 0 ; j < K ; j ++ ){
      dp[ _ ][ j ] = dp[ _ - 1 ][ j ];
      bk[ _ ][ j ] = j;
    }
    for( int j = d[ i ] ; j >= t[ i ] ; j -- )
      if( dp[ _ - 1 ][ j - t[ i ] ] + p[ i ] > dp[ _ ][ j ] ){
        dp[ _ ][ j ] = dp[ _ - 1 ][ j - t[ i ] ] + p[ i ];
        bk[ _ ][ j ] = j - t[ i ];
      }
  }
  int bi = max_element( dp[ n ] , dp[ n ] + K ) - dp[ n ];
  cout << dp[ n ][ bi ] << endl;
  vector<int> va;
  for( int i = n ; i >= 1 ; i -- ){
    if( bk[ i ][ bi ] < bi )
      va.push_back( id[ i ] );
    bi = bk[ i ][ bi ];
  }
  reverse( va.begin() , va.end() );
  cout << va.size() << endl;
  for( size_t i = 0 ; i < va.size() ; i ++ )
    cout << va[ i ] << " \n"[ i + 1 == va.size() ];
}
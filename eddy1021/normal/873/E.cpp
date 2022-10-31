#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 3002
int n , a[ N ];
vector< pair<int,int> > v;
int bwho[ N ][ N ];
int Cost( int x ){
  return v[ x ].first - ( x ? v[ x - 1 ].first : 0 );
}
int main(){
  cin >> n;
  for( int i = 0 , x ; i < n ; i ++ ){
    cin >> x;
    v.push_back( { x , i } );
  }
  sort( v.begin() , v.end() );
  for( int i = 0 ; i < n ; i ++ )
    for( int j = i ; j < n ; j ++ )
        bwho[ i ][ j ] = -1;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = i ; j < n ; j ++ ){
      bwho[ i ][ j ] = j;
      if( j > i and Cost( bwho[ i ][ j - 1 ] ) > Cost( bwho[ i ][ j ] ) )
        bwho[ i ][ j ] = bwho[ i ][ j - 1 ];
    }
  int ai = -1 , aj = -1 , ak = -1;
  tuple<int,int,int> ans = make_tuple( -1 , -1 , -1 );
  for( int i = 1 ; i < n ; i ++ )
    for( int j = i + 1 ; j < n ; j ++ ){
      int c2 = j - i , c3 = n - j;
      if( max( c2 , c3 ) > 2 * min( c2 , c3 ) )
        continue;
      int cst1 = v[ j ].first - v[ j - 1 ].first;
      int cst2 = v[ i ].first - v[ i - 1 ].first;
      int mn = min( c2 , c3 ) , mx = max( c2 , c3 );
      int rb = mn * 2 , lb = mx / 2;
      if( lb + lb < mx ) lb ++;
      rb = min( rb , i );
      lb = max( lb , 1 );
      if( lb <= rb ){
        int ql = max( i - rb , 0 );
        int qr = i - lb;
        if( ql <= qr ){
          pair<int,int> ret;
          ret.second = bwho[ ql ][ qr ];
          ret.first = Cost( bwho[ ql ][ qr ] );
          if( ret.first != -1 ){
            tuple<int,int,int> tans = make_tuple( cst1 , cst2 , ret.first );
            if( tans > ans ){
              ans = tans;
              ai = ret.second;
              aj = i;
              ak = j;
            }
          }
        }
      }
    }
  for( int i = 0 ; i < ai ; i ++ )
    a[ v[ i ].second ] = -1;
  for( int i = ai ; i < aj ; i ++ )
    a[ v[ i ].second ] = 3;
  for( int i = aj ; i < ak ; i ++ )
    a[ v[ i ].second ] = 2;
  for( int i = ak ; i < n ; i ++ )
    a[ v[ i ].second ] = 1;
  for( int i = 0 ; i < n ; i ++ )
    printf( "%d%c" , a[ i ] , " \n"[ i + 1 == n ] );
}
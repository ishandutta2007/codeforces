#include <bits/stdc++.h>
using namespace std;
#define N 202020
int n , a[ N ];
set<int> s[ N ] , mr;
int main(){
  cin >> n;
  for( int i = 1 ; i <= n ; i ++ ){
    cin >> a[ i ];
    s[ a[ i ] ].insert( i );
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( s[ i ].size() > 1u )
      for( auto j : s[ i ] )
        mr.insert( j );
  int d = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( s[ i ].empty() ){
      d ++;
      auto it = mr.begin();
      int at = *it;
      mr.erase( it );
      int ori = a[ at ];
      a[ at ] = i;
      if( ori > i ){
        s[ ori ].erase( at );
        if( s[ ori ].size() == 1u )
          mr.erase( *s[ ori ].begin() );
      }
    }else{
      auto it = mr.find( *s[ i ].begin() );
      if( it != mr.end() )
        mr.erase( it );
    }
  cout << d << "\n";
  for( int i = 1 ; i <= n ; i ++ )
    cout << a[ i ] << " \n"[ i == n ];
}
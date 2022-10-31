#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 151515
unordered_map<LL, set<int>> M;
set<LL> wt;
LL n , a[ N ];
int main(){
  scanf( "%lld" , &n );
  for( LL i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &a[ i ] );
  for( LL i = 0 ; i < n ; i ++ ){
    M[ a[ i ] ].insert( i );
    wt.insert( a[ i ] );
  }
  while( wt.size() ){
    LL x = *wt.begin();
    wt.erase( x );
    while( M[ x ].size() > 1u ){
      int i1 = *M[ x ].begin(); M[ x ].erase( M[ x ].begin() );
      int i2 = *M[ x ].begin(); M[ x ].erase( M[ x ].begin() );
      a[ i1 ] = 0;
      a[ i2 ] = x + x;
      M[ x + x ].insert( i2 );
      wt.insert( x + x );
    }
  }
  vector<LL> ans;
  for( int i = 0 ; i < n ; i ++ )
    if( a[ i ] )
      ans.push_back( a[ i ] );
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%lld%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}
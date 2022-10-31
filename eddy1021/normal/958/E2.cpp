#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 505050
int n , k;
LL t[ N ] , ans;
set<LL> pos;
set< pair<LL,pair<LL,LL>> > cand;
map< pair<LL,LL> , LL > cst;
int main(){
  scanf( "%d%d" , &k , &n );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &t[ i ] );
  sort( t , t + n );
  n = unique( t , t + n ) - t;
  for( int i = 0 ; i < n ; i ++ )
    pos.insert( t[ i ] );
  for( int i = 1 ; i < n ; i ++ ){
    cand.insert( { t[ i ] - t[ i - 1 ] , { t[ i - 1 ] , t[ i ] } } );
    cst[ {t[ i - 1 ] , t[ i ] } ] = t[ i ] - t[ i - 1 ];
  }
  while( k -- ){
    while( cand.size() ){
      auto it = *cand.begin();
      cand.erase( it );
      auto it1 = pos.find( it.second.first );
      auto it2 = pos.find( it.second.second );
      if( it1 == pos.end() or
          it2 == pos.end() )
        continue;
      ans += it.first;
      LL lft = -1 , rgt = -1;
  
      auto it4 = it1;
      if( it4 != pos.begin() ) lft = *--it4;
      auto it3 = it2; it3 ++;
      if( it3 != pos.end() ) rgt = *it3;

      if( lft != -1 and rgt != -1 ){
        LL lcst = cst[ {lft , *it1} ];
        LL rcst = cst[ {*it2 , rgt} ];
        LL ncst = lcst + rcst - it.first;

        cst[ {lft , rgt} ] = ncst;
        cand.insert( { ncst , { lft , rgt } } );
        cand.erase( {lcst , {lft , *it1}} );
        cand.erase( {rcst , {*it2 , rgt}} );
      }

      pos.erase( it1 );
      pos.erase( it2 );
      break;
    }
  }
  cout << ans << endl;
}
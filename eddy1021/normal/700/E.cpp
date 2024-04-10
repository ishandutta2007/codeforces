// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 202020
const int BS = 13131;
const int md = 1000000007;
typedef long long LL;
inline LL mul( LL x , LL y ){
  x *= y;
  return x >= md ? x % md : x;
}
inline int add( int x , int y ){
  x += y;
  return x >= md ? x - md : x;
}
inline int sub( int x , int y ){
  x -= y;
  return x < 0 ? x + md : x;
}
int bs[ N ] , hs[ N ];
inline void build(){
  bs[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    bs[ i ] = mul( bs[ i - 1 ] , BS );
}
inline int hs_vl( int l , int r ){
  if( l > r ) return 0;
  return sub( hs[ r ] , mul( hs[ l - 1 ] , bs[ r - l + 1 ] ) );
}
int n , ans;
char c[ N ];
inline void init(){
  scanf( "%d%s" , &n , c + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    hs[ i ] = add( mul( hs[ i - 1 ] , BS ) , c[ i ] );
}
map< pair<int,int> , vector<int> > dp[ N ];
inline void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    dp[ 1 ][ { hs_vl( i , i ) , 1 } ].push_back( i );
  for( int i = 1 ; i <= n ; i ++ ) if( dp[ i ].size() ){
    ans = i;
    for( auto it = dp[ i ].begin() ; it != dp[ i ].end() ; it ++ ){
      int len = it->first.second;
      vector<int> idx = it->second;
      vector< int > mid;
      for( size_t j = 0 ; j + 1 < idx.size() ; j ++ )
        mid.push_back( hs_vl( idx[ j ] + len , idx[ j + 1 ] - 1 ) );
      for( size_t l = 0 , r = 0 ; l + 1 < idx.size() ; l = r ){
        while( r + 1 < idx.size() && mid[ l ] == mid[ r ] ) r ++;
        int nxt = i + r - l;
        int nlen = idx[ r ] - idx[ l ] + len;
        dp[ nxt ][ { hs_vl( idx[ l ] , idx[ r ] + len - 1 ) , nlen } ].push_back( idx[ l ] );
      }
    }
  }
  printf( "%d\n" , ans );
}
int main(){
  build();
  init();
  solve();
}
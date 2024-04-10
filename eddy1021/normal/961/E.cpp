#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 202020
int n , a[ N ] , BIT[ N ];
int lb( int x ){ return x & (-x); }
void modify( int x ){
  for( int i = x ; i < N ; i += lb( i ) )
    BIT[ i ] ++;
}
int query( int x ){
  int ret = 0;
  for( int i = x ; i ; i -= lb( i ) )
    ret += BIT[ i ];
  return ret;
}
LL ans;
int main(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  vector< pair<int,int> > v;
  for( int i = 1 ; i <= n ; i ++ )
    v.push_back( {a[ i ] , i} );
  sort( v.begin() , v.end() );
  reverse( v.begin() , v.end() );
  size_t ptr = 0;
  for( int i = n ; i >= 1 ; i -- ){
    while( ptr < v.size() and v[ ptr ].first >= i )
      modify( v[ ptr ++ ].second );
    ans += query( min( a[ i ] , n ) );
    if( a[ i ] >= i ) ans --;
  }
  ans /= 2;
  cout << ans << endl;
}
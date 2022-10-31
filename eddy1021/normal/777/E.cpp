#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 202020
LL n , a[ N ] , b[ N ] , h[ N ] , id[ N ];
LL BIT[ N ];
inline int lb( int x ){
  return x & (-x);
}
inline void modify( int x , LL v ){
  for( int i = x ; i < N ; i += lb( i ) )
    BIT[ i ] = max( BIT[ i ] , v );
}
inline LL query( int x ){
  LL ret = 0;
  for( int i = x ; i ; i -= lb( i ) )
    ret = max( ret , BIT[ i ] );
  return ret;
}
bool cmp( LL id1 , LL id2 ){
  if( b[ id1 ] != b[ id2 ] )
    return b[ id1 ] > b[ id2 ];
  return a[ id1 ] > a[ id2 ];
}
vector<LL> li;
void init(){
  scanf( "%lld" , &n );
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%lld%lld%lld" , &a[ i ] , &b[ i ] , &h[ i ] );
    id[ i ] = i;
    li.push_back( a[ i ] );
    li.push_back( b[ i ] );
  }
  sort( id , id + n , cmp );
  sort( li.begin() , li.end() );
  li.resize( unique( li.begin() , li.end() ) - li.begin() );
}
void solve(){
  for( int _ = 0 ; _ < n ; _ ++ ){
    int i = id[ _ ];
    LL bst = query( lower_bound( li.begin() , li.end() , b[ i ] ) - li.begin() );
    modify( lower_bound( li.begin() , li.end() , a[ i ] ) - li.begin() + 1 ,
            bst + h[ i ] );
  }
  printf( "%lld\n" , query( li.size() + 1u ) );
}
int main(){
  init();
  solve();
}
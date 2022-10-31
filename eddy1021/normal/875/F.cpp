#include <bits/stdc++.h>
using namespace std;
#define N 202020
int p[ N ] , sz[ N ] , gt[ N ];
int n , m;
vector< pair<int, pair<int,int>> > e;
int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
void uni( int x , int y ){
  x = f( x );
  y = f( y );
  if( x == y ) return;
  p[ x ] = y;
  sz[ y ] += sz[ x ];
  gt[ y ] += gt[ x ];
}
int main(){
  cin >> n >> m;
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i , sz[ i ] = 1 , gt[ i ] = 0;
  while( m -- ){
    int a , b , c;
    cin >> a >> b >> c;
    e.push_back( { c , { b , a } } );
  }
  sort( e.begin() , e.end() );
  reverse( e.begin() , e.end() );
  int ans = 0;
  for( auto i : e ){
    int cst = i.first;
    int ai = i.second.first;
    int bi = i.second.second;
    uni( ai , bi );
    if( gt[ f( ai ) ] < sz[ f( ai ) ] ){
      gt[ f( ai ) ] ++;
      ans += cst;
    }
  }
  cout << ans << endl;
}
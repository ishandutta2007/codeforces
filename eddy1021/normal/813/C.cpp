#include <bits/stdc++.h>
using namespace std;
#define N 202020
vector<int> v[ N ];
int n , x , dep[ N ] , ans;
void go( int now , int prt , int ndep ){
  dep[ now ] = ndep;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now , ndep + 1 );
  }
}
int bdr;
void go2( int now , int prt ){
  if( dep[ now ] <= bdr ) return;
  ans = max( ans , dep[ now ] );
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go2( son , now );
  }
}
int main(){
  cin >> n >> x;
  for( int i = 1 ; i < n ; i ++ ){
    int a , b; cin >> a >> b;
    v[ a ].push_back( b );
    v[ b ].push_back( a );
  }
  go( 1 , 1 , 0 );
  bdr = dep[ x ] / 2;
  go2( x , x );
  printf( "%d\n" , ans << 1 );
}
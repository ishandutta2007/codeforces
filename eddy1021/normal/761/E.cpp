#include <bits/stdc++.h>
using namespace std;
#define N 55
typedef long long LL;
vector<int> v[ N ];
#define MX 1000000000000000000LL
LL n , x[ N ] , y[ N ];
LL dx[]={0,1,-1,0};
LL dy[]={-1,0,0,1};
void go( int fr , int frd , int now , LL px , LL py , LL ln ){
  x[ now ] = px; y[ now ] = py;
  int ndir = 0;
  for( int nxt : v[ now ] ){
    if( nxt == fr ) continue;
    while( ndir + frd == 3 ) ndir ++;
    go( now , ndir , nxt , px + dx[ ndir ] * ln , py + dy[ ndir ] * ln , ln / 2 );
    ndir ++;
  }
}
void solve(){
  LL mxd = 1;
  for( int i = 1 ; i <= n ; i ++ )
    if( v[ i ].size() > v[ mxd ].size() )
      mxd = i;
  int dir = 0;
  for( int nxt : v[ mxd ] ){
    go( mxd , dir , nxt , dx[ dir ] * MX / 2 , dy[ dir ] * MX / 2 , MX / 4 );
    dir ++;
  }
}
int main(){
  cin >> n;
  for( int i = 1 ; i < n ; i ++ ){
    int ui , vi; cin >> ui >> vi;
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( (int)v[ i ].size() > 4 ){
      puts( "NO" );
      exit( 0 );
    }
  solve();
  puts( "YES" );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld %lld\n" , x[ i ] , y[ i ] );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j : v[ i ] )
      assert( x[ i ] == x[ j ] || y[ i ] == y[ j ] );
}
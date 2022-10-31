#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 202020
typedef long long LL;
int n , a[ N ];
vector<int> v[ N ];
char c[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i < n ; i ++ ){
    int ui , vi;
    scanf( "%d%d" , &ui , &vi );
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  scanf( "%s" , c + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = (1 << (c[ i ] - 'a'));
}
bool died[ N ];

int sz[ N ] , n_tot , cen , bst;
void go_dp( int now , int prt ){
  sz[ now ] = 1;
  for( int son : v[ now ] ){
    if( son == prt or died[ son ] ) continue;
    go_dp( son , now );
    sz[ now ] += sz[ son ];
  }
}
void go2_dp( int now , int prt ){
  int mx = n_tot - sz[ now ];
  for( int son : v[ now ] ){
    if( son == prt or died[ son ] ) continue;
    go2_dp( son , now );
    mx = max( mx , sz[ son ] );
  }
  if( mx < bst ){
    bst = mx;
    cen = now;
  }
}

int cnt[ 1 << 20 ];
int root;
LL dp[ N ] , cdp[ N ];
void clear_cdp( int now , int prt ){
  cdp[ now ] = 0;
  for( int son : v[ now ] ){
    if( son == prt or died[ son ] ) continue;
    clear_cdp( son , now );
  }
}
void gogo( int now , int prt , int msk , int dlt ){
  cnt[ msk ] += dlt;
  for( int son : v[ now ] ){
    if( son == prt or died[ son ] ) continue;
    gogo( son , now , msk ^ a[ son ] , dlt );
  }
}
void gogogo( int now , int prt , int msk ){
  int nmsk = msk ^ a[ root ];
  cdp[ now ] += cnt[ nmsk ];
  for( int i = 0 ; i < 20 ; i ++ )
    cdp[ now ] += cnt[ nmsk ^ (1 << i) ];
  for( int son : v[ now ] ){
    if( son == prt or died[ son ] ) continue;
    gogogo( son , now , msk ^ a[ son ] );
  }
}
void climb_up( int now , int prt ){
  for( int son : v[ now ] ){
    if( son == prt or died[ son ] ) continue;
    climb_up( son , now );
    cdp[ now ] += cdp[ son ];
  }
}
void add_to_dp( int now , int prt ){
  dp[ now ] += cdp[ now ];
  for( int son : v[ now ] ){
    if( son == prt or died[ son ] ) continue;
    add_to_dp( son , now );
  }
}

void gogo2( int now , int prt , int msk ){
  if( !msk or (msk == (msk & (-msk))) )
    cdp[ now ] ++;
  for( int son : v[ now ] ){
    if( son == prt or died[ son ] ) continue;
    gogo2( son , now , msk ^ a[ son ] );
  }
}

void go( int now ){
  go_dp( now , now );
  n_tot = sz[ now ];
  cen = now; bst = sz[ now ];
  go2_dp( now , now );

  root = cen;
  clear_cdp( cen , cen );
  for( int son : v[ cen ] ){
    if( died[ son ] ) continue;
    gogo( son , cen , a[ son ] , +1 );
  }
  for( int son : v[ cen ] ){
    if( died[ son ] ) continue;
    gogo( son , cen , a[ son ] , -1 );
    gogogo( son , cen , a[ son ] );
    gogo( son , cen , a[ son ] , +1 );
  }
  climb_up( cen , cen );
  cdp[ cen ] >>= 1;
  add_to_dp( cen , cen );
  for( int son : v[ cen ] ){
    if( died[ son ] ) continue;
    gogo( son , cen , a[ son ] , -1 );
  }

  clear_cdp( cen , cen );
  gogo2( cen , cen , a[ cen ] );
  climb_up( cen , cen );
  add_to_dp( cen , cen );
  
  died[ cen ] = true;
  for( int son : v[ cen ] ){
    if( died[ son ] ) continue;
    go( son );
  }
}
void solve(){
  go( 1 );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld%c" , dp[ i ] , " \n"[ i == n ] );
}
int main(){
  init();
  solve();
}
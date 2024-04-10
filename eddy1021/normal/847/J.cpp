/*********************************************/
/*            _     _       _  ___ ____  _   */
/*    ___  __| | __| |_   _/ |/ _ \___ \/ |  */
/*   / _ \/ _` |/ _` | | | | | | | |__) | |  */
/*  |  __/ (_| | (_| | |_| | | |_| / __/| |  */
/*   \___|\__,_|\__,_|\__, |_|\___/_____|_|  */
/*                    |___/                  */
/*                                           */
/*********************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 10101
struct Arc{
  int to , si , nxt , tk;
  Arc(){
    to = si = nxt = tk = 0;
  }
  Arc( int _to , int _si , int _nxt , int _tk ){
    to = _to;
    si = _si;
    nxt = _nxt;
    tk = _tk;
  }
} e[ N ];
int n , m , from[ N ] , odeg[ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= m ; i ++ ){
    int ui , vi;
    scanf( "%d%d" , &ui , &vi );
    e[ i * 2 + 0 ] = Arc( vi , ui , from[ ui ] , 1 ); from[ ui ] = i * 2 + 0;
    e[ i * 2 + 1 ] = Arc( ui , vi , from[ vi ] , 0 ); from[ vi ] = i * 2 + 1;
    odeg[ ui ] ++;
  }
}
int ans , stmp , bs , st , vst[ N ] , se[ N ];
bool dfs( int now , int dep ){
  vst[ now ] = stmp;
  if( odeg[ now ] <= bs - 2 ){
    odeg[ now ] ++;
    odeg[ st ] --;
    for( int i = 0 ; i < dep ; i ++ ){
      int eid = se[ i ];
      e[ eid * 2 + 0 ].tk ^= 1;
      e[ eid * 2 + 1 ].tk ^= 1;
    }
    return true;
  }
  for( int idx = from[ now ] ; idx ; idx = e[ idx ].nxt ){
    if( vst[ e[ idx ].to ] == stmp ) continue;
    if( odeg[ e[ idx ].to ] > bs ) continue;
    if( !e[ idx ].tk ) continue;
    se[ dep ] = idx / 2;
    if( dfs( e[ idx ].to , dep + 1 ) )
      return true;
  }
  return false;
}
void solve(){
  ans = *max_element( odeg + 1 , odeg + n + 1 );
  while( true ){
    int mx = 1;
    for( int i = 1 ; i <= n ; i ++ )
      if( odeg[ i ] > odeg[ mx ] )
        mx = i;
    st = mx;
    bs = odeg[ mx ];
    ++ stmp;
    if( not dfs( mx , 0 ) ) break;
    ans = *max_element( odeg + 1 , odeg + n + 1 );
  }
  printf( "%d\n" , ans );
  for( int i = 2 ; i <= m + m + 1 ; i ++ )
    if( e[ i ].tk )
      printf( "%d %d\n" , e[ i ].si , e[ i ].to );
}
int main(){
  init();
  solve();
}
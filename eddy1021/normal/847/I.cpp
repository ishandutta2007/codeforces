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
#define N 256
char c[ N ][ N ];
int n , m , q , p;
int no[ N ][ N ];
void init(){
  scanf( "%d%d%d%d" , &n , &m , &q , &p );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%s" , c[ i ] );
}
int vst[ N ][ N ] , stmp;
int que[ N * N ];
int qn[ N * N ];
int qm[ N * N ];
int qf , qt;
int dn[]={0,0,1,-1};
int dm[]={1,-1,0,0};
bool ok( int xi , int yi ){
  return 0 <= xi and xi < n and
         0 <= yi and yi < m and
         c[ xi ][ yi ] != '*';
}
void go( int si , int sj ){
  qf = qt = 0; ++ stmp;
  qn[ qt ] = si;
  qm[ qt ] = sj;
  que[ qt ++ ] = ( 1 + c[ si ][ sj ] - 'A' ) * q;
  vst[ si ][ sj ] = stmp;
  for( int i = qf ; i < qt ; i ++ ){
    int cn = qn[ i ] , cm = qm[ i ];
    no[ cn ][ cm ] += que[ i ];
    if( no[ cn ][ cm ] > p )
      no[ cn ][ cm ] = p + 1;
    int xx = que[ i ] / 2;
    if( xx == 0 ) continue;
    for( int dir = 0 ; dir < 4 ; dir ++ ){
      int nxtn = cn + dn[ dir ];
      int nxtm = cm + dm[ dir ];
      if( not ok( nxtn , nxtm ) )
        continue;
      if( vst[ nxtn ][ nxtm ] == stmp )
        continue;
      vst[ nxtn ][ nxtm ] = stmp;
      qn[ qt ] = nxtn;
      qm[ qt ] = nxtm;
      que[ qt ++ ] = xx;
    }
  }
}
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      if( 'A' <= c[ i ][ j ] and
          c[ i ][ j ] <= 'Z' )
        go( i , j );
  int ans = 0;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      if( no[ i ][ j ] > p )
        ans ++;
  cout << ans << endl;
}
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  init();
  solve();
}
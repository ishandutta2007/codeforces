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
typedef long long LL;
#define N 202020
inline LL getint(){
  LL _x=0; char _tc=getchar();    
  while( _tc<'0'||_tc>'9' ) _tc=getchar();
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x;
}
LL n , t , a[ N ];
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  n = getint();
  t = getint();
  n = min( n , t - 1 );
  LL mr = t - n - 1;
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint() - mr - i;
  vector< pair<LL,LL> > vv;
  for( int i = 1 ; i <= n ; i ++ )
    vv.push_back( { a[ i ] , i } );
  sort( vv.begin() , vv.end() );
  LL til = 0;
  while( til < n and vv[ til ].first <= 0 ) til ++;
  LL ans = til , tans = til;
  for( int i = 1 , j = n ; i <= n ; i ++ , j -- ){
    if( a[ j ] <= i - 1 ) tans --;
    while( til < n and vv[ til ].first <= i ){
      if( vv[ til ].second < j )
        tans ++;
      til ++;
    }
    ans = max( ans , tans );
  }
  cout << ans << endl;
}
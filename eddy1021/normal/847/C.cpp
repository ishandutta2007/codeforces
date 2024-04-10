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
LL n , k;
string ans = "";
void go( int now ){
  if( now == 0 ){
    ans += "()";
    return;
  }
  if( k >= now ){
    ans += "(";
    k -= now;
    go( now - 1 );
    ans += ")";
    return;
  }
  ans += "()";
  go( now - 1 );
}
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  cin >> n >> k;
  go( n - 1 );
  cout << ( k > 0 ? "Impossible" : ans ) << endl;
}
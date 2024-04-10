/***********************************************************/
/*       _________________       ________________________  */
/*  ___________  /_____  /____  ___<  /_  __ \_|__ \_<  /  */
/*  _  _ \  __  /_  __  /__  / / /_  /_  / / /___/ /_  /   */
/*  /  __/ /_/ / / /_/ / _  /_/ /_  / / /_/ /_  __/_  /    */
/*  \___/\__,_/  \__,_/  _\__, / /_/  \____/ /____//_/     */
/*                       /____/                            */
/*                                                         */
/***********************************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n , c[ N ];
vector<int> v[ N ];
void go( int now , int prt , int x ){
  c[ x ] ++;
  for( int son : v[ now ] )
    if( son != prt )
      go( son , now , 1 - x );
}
int main(){
  cin >> n;
  for( int i = 1 , ui , vi ; i < n ; i ++ ){
    cin >> ui >> vi;
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  go( 1 , 1 , 0 );
  cout << (long long)c[ 0 ] * c[ 1 ] - n + 1 << endl;
}
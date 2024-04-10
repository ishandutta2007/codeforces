#include <bits/stdc++.h>
using namespace std;
#define N 202020
int n , a[ N ];
vector<int> v[ N ];
void init(){
  cin >> n;
  for( int i = 1 ; i <= n ; i ++ )
    cin >> a[ i ];
  for( int i = 1 , ui , vi ; i < n ; i ++ ){
    cin >> ui >> vi;
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
set<int> s[ N ];
void go( int now , int prt , int pre ){
  s[ now ].insert( pre );
  s[ now ].insert( __gcd( pre , a[ now ] ) );
  for( auto i : s[ prt ] )
    s[ now ].insert( __gcd( i , a[ now ] ) );
  for( auto son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now , __gcd( pre , a[ now ] ) );
  }
}
void solve(){
  go( 1 , 0 , 0 );
  for( int i = 1 ; i <= n ; i ++ )
    cout << *s[ i ].rbegin() << " \n"[ i == n ];
}
int main(){
  init();
  solve();
}
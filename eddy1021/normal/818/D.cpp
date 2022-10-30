#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int n , a , x , cnt[ N ];
bool died[ N ];
int main(){
  cin >> n >> a;
  set< pair<int,int> > S;
  for( int i = 1 ; i < N ; i ++ )
    S.insert( { 0 , i } );
  while( n -- ){
    cin >> x;
    if( not died[ x ] ){
      S.erase( S.find( { cnt[ x ] , x } ) );
      cnt[ x ] ++;
      S.insert( { cnt[ x ] , x } );
    }
    while( S.size() and S.begin()->first < cnt[ a ] ){
      died[ S.begin()->second ] = true;
      S.erase( S.begin() );
    }
  }
  for( auto i : S )
    if( i.second != a ){
      cout << i.second << endl;
      exit(0);
    }
  cout << -1 << endl;
}
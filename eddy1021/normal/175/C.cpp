#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
vector< pair<LL,LL> > v;
int n , t;
LL p[ N ];
int main(){
  cin >> n;
  for( int i = 0 ; i < n ; i ++ ){
    LL ki , ci;
    cin >> ki >> ci;
    v.push_back( { ci , ki } );
  }
  sort( v.begin() , v.end() );
  cin >> t;
  for( int i = 1 ; i <= t ; i ++ )
    cin >> p[ i ];
  for( int i = t ; i >= 1 ; i -- )
    p[ i ] -= p[ i - 1 ];
  p[ t + 1 ] = 1e16;
  int nxt = 0;
  LL score = 0;
  for( int i = 1 ; i <= t + 1 ; i ++ )
    while( nxt < n and p[ i ] ){
      while( nxt < n and v[ nxt ].second == 0 ) nxt ++;
      if( nxt >= n ) break;
      LL gt = min( v[ nxt ].second , p[ i ] );
      score += gt * v[ nxt ].first * i;
      v[ nxt ].second -= gt;
      p[ i ] -= gt;
    }
  cout << score << endl;
}
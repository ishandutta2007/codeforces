#include <bits/stdc++.h>
using namespace std;
#define N 250LL
#define P 10LL
typedef long long LL;
LL a[ N ];
int main(){
  int _; cin >> _; while( _ -- ){
    for( int i = 0 ; i < N ; i ++ )
      //a[ i ] = rand() % ( P + P + 1 );
      cin >> a[ i ];
    LL p = accumulate( a , a + N , N / 2 ) / N;
    LL uni = p * p / 3;
    LL var = 0;
    for( int i = 0 ; i < N ; i ++ )
      var += ( a[ i ] - p ) * ( a[ i ] - p );
    var /= N;
    LL ans = p;
    if( abs( var - p ) < abs( var - uni ) )
      ans = p;
    else
      ans = *max_element( a , a + N ) / 2;
    //if( ans < int(P * 0.95) or
        //ans > int(P * 1.05 + 0.5) )
      //puts( "WA" );
    cout << ans << endl;
  }
}
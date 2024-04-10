#include <bits/stdc++.h>
using namespace std;
#define N 250LL
typedef long long LL;
LL a[ N ];
int main(){
  int _; cin >> _; while( _ -- ){
    for( int i = 0 ; i < N ; i ++ )
      cin >> a[ i ];
    LL p = accumulate( a , a + N , N / 2 ) / N;
    LL uni = p * p / 3;
    LL var = 0;
    for( int i = 0 ; i < N ; i ++ )
      var += ( a[ i ] - p ) * ( a[ i ] - p );
    var /= N;
    if( abs( var - p ) < abs( var - uni ) )
      puts( "poisson" );
    else
      puts( "uniform" );
  }
}
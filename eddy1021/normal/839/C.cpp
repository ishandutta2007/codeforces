#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n;
vector<int> v[ N ];
double go( int now , int prt ){
  double ret = 0;
  int s = 0;
  for( auto son : v[ now ] ){
    if( son == prt ) continue;
    s ++;
    ret += go( son , now );
  }
  return s ? 1 + ret / s : 0;
}
int main(){
  cin >> n;
  for( int i = 1 , x , y ; i < n ; i ++ ){
    cin >> x >> y;
    v[ x ].push_back( y );
    v[ y ].push_back( x );
  }
  cout << fixed << setprecision( 12 ) << go( 1 , 1 ) << endl;
}
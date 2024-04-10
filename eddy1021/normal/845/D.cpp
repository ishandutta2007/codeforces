#include <bits/stdc++.h>
using namespace std;
int n , ot , speed , l;
vector<int> limits;
int main(){
  limits.push_back( 333 );
  int ans = 0;
  cin >> n; while( n -- ){
    int e; cin >> e;
    if( e == 1 ){
      cin >> speed;
    }else if( e == 2 ){
      ans += ot;
      ot = 0;
    }else if( e == 3 ){
      cin >> l;
      limits.push_back( l );
    }else if( e == 4 )
      ot = 0;
    else if( e == 5 )
      limits.push_back( 333 );
    else
      ot ++;
    while( speed > limits.back() ){
      ans ++;
      limits.pop_back();
    }
  }
  cout << ans << endl;
}
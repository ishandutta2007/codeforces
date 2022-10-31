#include <bits/stdc++.h>
using namespace std;
int main(){
  int h1 , a1 , c1;
  int h2 , a2;
  cin >> h1 >> a1 >> c1;
  cin >> h2 >> a2;
  vector<int> v;
  while( true ){
    if( h2 <= a1 ){
      v.push_back( 0 );
      break;
    }
    if( h1 <= a2 ){
      v.push_back( 1 );
      h1 += c1;
      h1 -= a2;
      continue;
    }
    v.push_back( 0 );
    h2 -= a1;
    h1 -= a2;
  }
  cout << v.size() << endl;
  for( int x : v )
    cout << (!x ? "STRIKE" : "HEAL") << endl;
}
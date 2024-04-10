#include <bits/stdc++.h>
using namespace std;
map<int,int> M;
int main(){
  int n; cin >> n; while( n -- ){
    int x; cin >> x;
    M[ x ] ++;
  }
  vector<int> v;
  int sum = 0;
  for( auto i : M ){
    v.push_back( i.second );
    sum += i.second;
    if( sum > 2 ) break;
  }
  if( v.size() == 1u )
    cout << 1LL * v[ 0 ] * ( v[ 0 ] - 1 ) * ( v[ 0 ] - 2 ) / 6 << endl;
  else if( v.size() == 3u )
    cout << 1LL * v[ 2 ] << endl;
  else if( v[ 0 ] == 1 )
    cout << 1LL * v[ 1 ] * ( v[ 1 ] - 1 ) / 2 << endl;
  else
    cout << 1LL * v[ 1 ] << endl;
}
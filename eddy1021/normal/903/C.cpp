#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
bool okay( int tar ){
  for( int i = tar ; i < n ; i ++ )
    if( v[ i ] == v[ i - tar ] )
      return false;
  return true;
}
int main(){
  cin >> n;
  for( int i = 0 , x ; i < n ; i ++ ){
    cin >> x;
    v.push_back( x );
  }
  sort( v.begin() , v.end() , greater<int>() );
  int bl = 1 , br = n , ba = n;
  while( bl <= br ){
    int bmid = (bl + br) >> 1;
    if( okay( bmid ) )
      ba = bmid , br = bmid - 1;
    else
      bl = bmid + 1;
  }
  cout << ba << endl;
}
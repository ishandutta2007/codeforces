#include <bits/stdc++.h>
using namespace std;
int n;
map<string,int> M;
vector<int> v;
int main(){
  cin >> n;
  while( n -- ){
    string name; int score;
    cin >> name >> score;
    M[ name ] = max( M[ name ] , score );
  }
  for( auto i : M )
    v.push_back( i.second );
  sort( v.begin() , v.end() );
  reverse( v.begin() , v.end() );
  int tot = M.size();
  cout << tot << endl;
  for( auto i : M ){
    int bst = 0;
    while( bst < tot and v[ bst ] > i.second )
      bst ++;
    cout << i.first << " ";
    if( 2 * bst > tot ) cout << "noob";
    else if( 5 * bst > tot ) cout << "random";
    else if( 10 * bst > tot ) cout << "average";
    else if( 100 * bst > tot ) cout << "hardcore";
    else cout << "pro";
    cout << endl;
  }
}
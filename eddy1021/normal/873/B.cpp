#include <bits/stdc++.h>
using namespace std;
#define N 101010
string s;
map<int,int> M;
int main(){
  int n; cin >> n;
  cin >> s;
  int len = s.length();
  M[ 0 ] = -1;
  int sum = 0 , ans = 0;
  for( int i = 0 ; i < len ; i ++ ){
    if( s[ i ] == '1' ) sum ++;
    else sum --;
    auto it = M.find( sum );
    if( it != M.end() )
      ans = max( ans , i - it->second );
    else
      M[ sum ] = i;
  }
  cout << ans << endl;
}
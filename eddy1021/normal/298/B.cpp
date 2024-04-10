#include <bits/stdc++.h>
using namespace std;
int main(){
  int t , sx , sy , ex , ey;
  cin >> t >> sx >> sy >> ex >> ey;
  string w; cin >> w;
  int dx = ex - sx , dy = ey - sy;
  for( int i = 0 ; i < t ; i ++ ){
    if( w[ i ] == 'E' and dx > 0 ) dx --;
    if( w[ i ] == 'W' and dx < 0 ) dx ++;
    if( w[ i ] == 'N' and dy > 0 ) dy --;
    if( w[ i ] == 'S' and dy < 0 ) dy ++;
    if( dx == 0 and dy == 0 ){
      cout << i + 1 << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
}
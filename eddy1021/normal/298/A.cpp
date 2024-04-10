#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n;
char c[ N ];
int main(){
  cin >> n;
  cin >> c;
  int sr = -1 , tr = -1 , sl = -1 , tl = -1;
  for( int i = 0 ; i < n ; i ++ )
    if( c[ i ] == 'R' ){
      if( sr == -1 )
        sr = tr = i;
      else
        tr = i;
    }else if( c[ i ] == 'L' ){
      if( sl == -1 )
        sl = tl = i;
      else
        tl = i;
    }
  if( sr == -1 )
    cout << tl + 1 << " " << sl << endl;
  else if( sl == -1 )
    cout << sr + 1 << " " << tr + 2 << endl;
  else
    cout << sr + 1 << " " << tr + 1 << endl;
}
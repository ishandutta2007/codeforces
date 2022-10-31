#include <bits/stdc++.h>
using namespace std;
#define N 101010
char c[ N ];
int k , cc[ 10 ];
int main(){
  cin >> k;
  cin >> c;
  int sum = 0;
  for( int i = 0 ; c[ i ] ; i ++ ){
    cc[ c[ i ] - '0' ] ++;
    sum += c[ i ] - '0';
  }
  int dif = 0 , ptr = 0;
  while( sum < k ){
    while( ptr < 10 and cc[ ptr ] == 0 ) ptr ++;
    assert( ptr < 10 );
    sum += 9 - ptr;
    dif ++;
    cc[ ptr ] --;
  }
  cout << dif << endl;
}
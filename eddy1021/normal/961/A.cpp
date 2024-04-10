#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1021
int c[ N ];
int main(){
  int n , m , x;
  cin >> n >> m;
  while( m -- ){
    cin >> x;
    c[ x ] ++;
  }
  cout << *min_element( c + 1 , c + n + 1 ) << endl;
}
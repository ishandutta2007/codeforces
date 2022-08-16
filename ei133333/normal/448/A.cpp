#include<bits/stdc++.h>
using namespace std;
int main(){
  int a, b, sa = 0, sb = 0, n;
  for(int i = 0; i < 3; i++){
    cin >> a;
    sa += a;
  }
  for(int i = 0; i < 3; i++){
    cin >> b;
    sb += b;
  }

  cin >> n;

  sa = sa / 5 + (sa % 5 != 0);
  sb = sb / 10 + (sb % 10 != 0);
  
  cout << (sa + sb <= n ? "YES": "NO") << endl;

}
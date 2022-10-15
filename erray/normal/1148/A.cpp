// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) {
    swap(a, b);
  }

  b = min(b, a + 1);
  cout << 0LL + a + b + + c * 2 << '\n';
}
// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    --a;
    int cxor = (((a + 1) / 2) % 2) ^ (a % 2 == 0 ? a : 0); 
    ++a;
    b ^= cxor;
    if (b == 0) {
      cout << a;
    } else if (b == a) {
      cout << a + 2;
    } else {
      cout << a + 1;
    }
    cout << '\n';
  }
}
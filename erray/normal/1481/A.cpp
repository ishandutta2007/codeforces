// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    vector<int> ct(256);
    for (char c : s) {
      ++ct[c];
    }
    
    cout << ((x < 0 ? ct['L'] : ct['R']) >= abs(x) && (y < 0 ? ct['D'] : ct['U']) >= abs(y) ? "YES" : "NO") << '\n';
  }
}
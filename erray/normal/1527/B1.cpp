// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    int n;
    cin >> n >> s;
    vector<int> ct(2);
    for (char c : s) {
      ++ct[c - '0'];
    }
    cout << (ct[0] % 2 == 0 || ct[0] == 1 ? "BOB" : "ALICE") << '\n';  
  }
}
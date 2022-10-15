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
    cin >> s;
    int sum = 0;
    int even = 0;
    int zero = 0;
    for (auto c : s) {
      c -= '0';
      sum += c;
      even += (c % 2 == 0);
      zero += (c == 0);
    }
    cout << (sum % 3 == 0 && even > 1 && zero > 0 ? "red" : "cyan") << '\n';
  }
}
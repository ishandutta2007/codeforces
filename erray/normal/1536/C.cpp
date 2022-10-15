// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    map<pair<int, int>, int> ct;
    int d = 0;
    int k = 0;
    for (char c : s) {
      (c == 'D' ? d : k) += 1;
      int g = __gcd(d, k);
      cout << ++ct[{d / g, k / g}] << ' ';
    }
    cout << '\n';
  }
}
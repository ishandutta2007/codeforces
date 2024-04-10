// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long p, a, b, c;
    cin >> p >> a >> b >> c;
    auto g = [&](long long x) {
      return (x - (p % x)) % x;
    };

    cout << min({g(a), g(b), g(c)}) << '\n';
  }
}
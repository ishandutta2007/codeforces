// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    auto Check = [&](long long x) {
      int sum = 0;
      long long tmp = x;
      while (x > 0) {
        sum += x % 10;
        x /= 10;
      }
      return gcd(tmp, sum) > 1;
    };

    while (!Check(n)) {
      ++n;
    }
    cout << n << '\n';
  }
}
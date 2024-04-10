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
    cout << ((n % 14) <= 6 && (n % 14) > 0 && n > 6 ? "YES" : "NO") << '\n';
  }
}
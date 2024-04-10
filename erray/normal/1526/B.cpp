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
    cin >> n;
    int left = n % 11;
    if (1LL * left * 111 <= n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
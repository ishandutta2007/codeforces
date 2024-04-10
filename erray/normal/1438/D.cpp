// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    tot ^= a[i];  
  }
  
  if (n % 2 == 0 && tot != 0) {
    return cout << "NO\n", 0;    
  }
  cout << "YES\n";
  n -= n % 2 ^ 1;
  cout << n - 1 << '\n';
  for (int j = 0; j < 2; ++j) {
    for (int i = 0; i < (n / 2); ++i) {
      cout << 1 << ' ' << 2 * i + 2 << ' ' << 2 * i + 3 << '\n';
    }
  }
}
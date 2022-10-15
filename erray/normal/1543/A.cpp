// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    if (a == b) {
      cout << 0 << ' ' << 0 << '\n';
      continue;
    }
    long long res = b - a;
    cout << res << ' ';
    long long md = b % res;
    cout << min(md, res - md) << '\n';
  }
}
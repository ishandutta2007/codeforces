// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    long long cur = 1;
    bool ok = false;
    bool first = true;
    while (cur <= n && (first || a != 1)) {
      ok |= ((n - cur) % b == 0);
      cur *= a;
      first = false;
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, sol = 0;
    cin >> n;
    while (n) {
      sol = max(sol, n % 10);
      n /= 10;
    }
    cout << sol << "\n";
  }
}


/**

**/
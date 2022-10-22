#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while(T--) {
    long long n;
    cin >> n;
    bool ok = false;
    for(long long i=1; i*i*i<n; i++) {
      long long j = cbrt(n - i*i*i);
      if(i*i*i + j*j*j == n) {
        ok = true;
        break;
      }
    }
    if(ok) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }

  return 0;
}
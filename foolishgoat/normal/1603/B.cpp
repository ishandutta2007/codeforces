#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long x, y;
  cin >> x >> y;
  long long n = -1;
  if (x > y) {
    n = (x + y);
  } else {
    long long r = y % x;
    // assert((r & 1) == 0);
    r /= 2;
    n = y - r;
  }
  cout << n << "\n";
  // assert((n % x) == (y % n));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
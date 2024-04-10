#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    n -= max(0, n % k - k / 2);
    cout << n << '\n';
  }
  return 0;
}
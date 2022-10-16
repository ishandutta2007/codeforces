#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  while (t--) {
    int h, m;
    cin >> h >> m;
    cout << (60 * (23 - h) + 60 - m) << '\n';
  }
  return 0;
}
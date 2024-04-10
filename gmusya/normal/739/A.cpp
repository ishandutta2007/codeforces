#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = n;
  while (m--) {
    int l, r;
    cin >> l >> r;
    ans = min(ans, r - l + 1);
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++)
    cout << i % ans << ' ';
  return 0;
}
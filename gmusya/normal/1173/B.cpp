#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int m = n / 2 + 1;
  cout << m << '\n';
  for (int i = 1; i <= n; i++) {
    if (i <= m)
      cout << 1 << ' ' << i << '\n';
    else
      cout << i - m + 1 << ' ' << m << '\n';
  }
  return 0;
}
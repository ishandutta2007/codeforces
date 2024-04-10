#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n <= 5) {
    cout << -1 << '\n';
  } else {
    cout << 1 << ' ' << 2 << '\n';
    for (int i = 3; i <= n; i++)
      cout << 2 - i % 2 << ' ' << i << '\n';
  }
  for (int i = 1; i < n; i++)
    cout << i << ' ' << i + 1 << '\n';
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    if (n <= 2) {
      cout << 1 << '\n';
      continue;
    }
    cout << 2 + (n - 3) / x << '\n';
  }
  return 0;
}
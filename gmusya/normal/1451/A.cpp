#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    if (n == 2) {
      cout << 1 << '\n';
      continue;
    }
    if (n % 2 == 0 || n == 3) {
      cout << 2 << '\n';
      continue;
    }
    cout << 3 << '\n';
  }
  return 0;
}
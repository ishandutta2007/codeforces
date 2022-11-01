#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 4 * n; i > 4 * n - 2 * n; i -= 2)
      cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n << '\n';
    for (int i = 1; i <= n; i++)
      cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
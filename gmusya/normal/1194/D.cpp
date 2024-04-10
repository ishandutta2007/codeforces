#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k == 3) {
      if (n % 4)
        cout << "Alice\n";
      else
        cout << "Bob\n";
    } else if (k % 3 == 0) {
      n %= k + 1;
      if (n == k || n % 3)
        cout << "Alice\n";
      else
        cout << "Bob\n";
    } else {
      if (n % 3)
        cout << "Alice\n";
      else
        cout << "Bob\n";
    }
  }
  return 0;
}
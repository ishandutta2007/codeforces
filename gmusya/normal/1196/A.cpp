#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c) / 2 << '\n';
  }
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << 0;
    return 0;
  }
  n /= 2;
  cout << (1 << n);
  return 0;
}
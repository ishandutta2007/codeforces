#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c = floor(sqrt(2 * n + (1e-6)));
    cout << (c - 1) / 2 << '\n';
  }
  return 0;
}
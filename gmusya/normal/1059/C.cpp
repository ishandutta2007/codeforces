#include <iostream>

using namespace std;

void solve(int n, int k) {
  if (n == 1)
    cout << k << ' ';
  if (n == 2)
    cout << k << ' ' << 2 * k << ' ';
  if (n == 3)
    cout << k << ' ' << k << ' ' << 3 * k << ' ';
  if (n > 3) {
    for (int i = 0; i < (n + 1) / 2; i++)
      cout << k << ' ';
    solve(n / 2, k * 2);
  }
}

int main() {
  int n;
  cin >> n;
  solve(n, 1);
  return 0;
}
#include <iostream>

using namespace std;

bool check(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  if (check(n)) {
    cout << 1 << '\n' << n;
    return 0;
  }
  n -= 3;
  if (check(n)) {
    cout << 2 << '\n' << 3 << ' ' << n;
    return 0;
  }
  int k = 2;
  while (!check(k) || !check(n - k))
    k++;
  cout << 3 << '\n' << 3 << ' ' << k << ' ' << n - k;
  return 0;
}
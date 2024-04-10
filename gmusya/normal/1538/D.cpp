#include <iostream>
#include <vector>

using namespace std;

int f(int x) {
  int res = 0;
  for (int i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      x /= i;
      res++;
    }
  }
  res += (x != 1);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, k;
    cin >> a >> b >> k;
    if (a < b) {
      swap(a, b);
    }
    if (k == 1) {
      if (a == b || a % b) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
      continue;
    }
    if (f(a) + f(b) >= k) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
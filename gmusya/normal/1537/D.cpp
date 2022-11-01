#include <iostream>
#include <vector>

using namespace std;

int f(int x) {
  int res = 0;
  while (x != 1) {
    if (x % 2 == 0) {
      x /= 2;
      res++;
    } else {
      return -1;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2) {
      cout << "Bob\n";
    } else {
      int tmp = f(n);
      if (tmp == -1 || tmp % 2 == 0) {
        cout << "Alice\n";
      } else {
        cout << "Bob\n";
      }
    }
  }
  return 0;
}
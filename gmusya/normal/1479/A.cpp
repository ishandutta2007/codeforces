#include <iostream>
#include <vector>

using namespace std;

int ask(int x) {
  cout << "? " << x << endl;
  int a;
  cin >> a;
  return a;
}

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "! " << 1;
    return 0;
  }
  {
    int x = ask(1);
    int y = ask(2);
    if (x < y) {
      cout << "! " << 1 << endl;
      return 0;
    }
  }
  {
    int x = ask(n);
    int y = ask(n - 1);
    if (x < y) {
      cout << "! " << n << endl;
      return 0;
    }
  }
  if (n == 3) {
    cout << "! " << 2 << endl;
    return 0;
  }
  int L = 2, R = n - 1;
  while (L != R) {
    int M = (L + R) / 2;
    int a = ask(M - 1);
    int b = ask(M);
    int c = ask(M + 1);
    if (b < a && b < c) {
      cout << "! " << M;
      return 0;
    }
    if (a < b)
      R = M - 1;
    else
      L = M + 1;
  }
  cout << "! " << L;
  return 0;
}
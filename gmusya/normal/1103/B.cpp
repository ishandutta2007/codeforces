#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s;
  while (cin >> s) {
    int L = 0, R = 1;
    while (true) {
      if (R > 1e9)
        break;
      cout << "? " << L << ' ' << R << endl;
      char c;
      cin >> c;
      if (c == 'x')
        break;
      if (L >= 1)
        L *= 2;
      else
        L = 1;
      R *= 2;
    }
    char c = 'y';
    if (L > 0) {
      cout << "? " << L - 1 << ' ' << L << endl;
      cin >> c;
    }
    if (c == 'x') {
      cout << "! " << L << endl;
    } else {
      int S = L;
      L++;
      if (R > 1e9)
        R = 1e9;
      while (L != R) {
        int M = (L + R) / 2;
        cout << "? " << S << ' ' << M << endl;
        char c;
        cin >> c;
        if (c == 'y')
          L = M + 1;
        else
          R = M;
      }
      cout << "! " << L << endl;
    }
  }
  return 0;
}
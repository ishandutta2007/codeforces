#include <iostream>
#include <vector>

using namespace std;

int ask(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int x;
  cin >> x;
  return x;
}

int main() {
  int n;
  cin >> n;
  int l = 1, r = n;
  int c = ask(l, r);
  while (l + 2 < r) {
    int m = (l + r) / 2;
    int a = ask(l, m);
    int b = ask(m + 1, r);
    if (a != c && b != c) {
      if (c <= m) {
        l = m + 1;
        c = b;
      } else {
        r = m;
        c = a;
      }
      continue;
    }
    if (a == c) {
      r = m;
      c = a;
    } else {
      l = m + 1;
      c = b;
    }
  }
  if (l + 2 == r) {
    int a = ask(l, l + 1);
    int b = ask(l + 1, l + 2);
    int c = ask(l, l + 2);
    if (a == b) {
      if (c == l + 2)
        cout << "! " << l << endl;
      else
        cout << "! " << l + 2 << endl;
      return 0;
    }
    cout << "! " << 3 * l + 3 - a - b << endl;
    return 0;
  }
  if (l == r) {
    cout << "! " << l << endl;
    return 0;
  }
  int x = ask(l, r);
  cout << "! " << l + r - x << endl;
  return 0;
}
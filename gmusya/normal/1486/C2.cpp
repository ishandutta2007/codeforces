#include <iostream>
#include <vector>

using namespace std;

int ask(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int x;
  cin >> x;
  return x;
}

int ans(int x) {
  cout << "! " << x;
  return 0;
}

int main() {
  int n;
  cin >> n;
  int x = ask(1, n);
  bool flag = true; //   x
  if (x != 1) {
    int c = ask(1, x);
    if (c == x)
      flag = false;
  }
  if (flag) {
    int l = x + 1, r = n;
    while (l != r) {
      int m = (l + r) / 2;
      if (ask(1, m) != x)
        l = m + 1;
      else
        r = m;
    }
    ans(l);
    return 0;
  }
  int l = 1, r = x - 1;
  while (l != r) {
    int m = (l + r + 1) / 2;
    if (ask(m, x) != x)
      r = m - 1;
    else
      l = m;
  }
  ans(l);
  return 0;
}
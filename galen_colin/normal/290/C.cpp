#include <bits/stdc++.h>

using namespace std;

int main() {
  int tux;
  cin >> tux;
  double 
    foo = 0, 
    bar = 0,
    baz = 0,
    quz = 1;
  while (tux--) {
    int pur;
    cin >> pur;
    foo = foo + pur;
    bar++;
    if (max(foo * quz, bar * baz) == foo * quz) {
      baz = foo;
      quz = bar;
    }
  }
  cout << setprecision(7) << fixed << baz / quz;
}
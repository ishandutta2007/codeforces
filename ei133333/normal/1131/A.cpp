#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;

  int64 add = 0;
  add += (w1 + 2) * (h1 + 1);
  add -= w1 * h1;
  add += (w2 + 2) * (h2 + 1);
  add -= w2 * h2;
  add += w1-w2;

  cout << add << endl;
}
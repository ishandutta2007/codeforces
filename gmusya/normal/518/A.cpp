#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  string c, d;
  for (int i = 0; i < (int) a.size(); i++) {
    if (a[i] == b[i]) {
      c += a[i];
      d += a[i];
    } else {
      c += b[i] - 1;
      d += a[i] + 1;
      for (int j = i + 1; j < (int) a.size(); j++)
        c += "z", d += "a";
      break;
    }
  }
  if (a < c && c < b) {
    cout << c;
    return 0;
  }
  if (a < d && d < b) {
    cout << d;
    return 0;
  }
  cout << "No such string";
  return 0;
}
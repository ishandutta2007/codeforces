#include <iostream>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <char> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    if (n % 2) {
      bool tf = false;
      for (int i = 0; i < n; i += 2)
        if (a[i] % 2)
          tf = true;
      if (tf)
        cout << 1 << '\n';
      else
        cout << 2 << '\n';
      continue;
    }
    bool tf = false;
    for (int i = 1; i < n; i += 2)
      if (a[i] % 2 == 0)
        tf = true;
    if (tf)
      cout << 2 << '\n';
    else
      cout << 1 << '\n';
  }
  return 0;
}
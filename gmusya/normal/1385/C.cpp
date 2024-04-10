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
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    bool tf = true, wr = false;
    for (int i = n - 2; i >= 0; i--) {
      if (tf) {
        if (a[i] < a[i + 1])
          tf = false;
        continue;
      }
      if (a[i] > a[i + 1]) {
        cout << i + 1 << '\n';
        wr = true;
        break;
      }
    }
    if (!wr)
      cout << 0 << '\n';
  }
  return 0;
}
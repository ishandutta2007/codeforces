#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)
        cout << a[i + 1] << ' ';
      else
        cout << -a[i - 1] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
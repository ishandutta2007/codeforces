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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 2) {
      cout << a[0] << ' ' << a[1] << '\n';
      continue;
    }
    int id = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] < a[id] - a[id - 1]) {
        id = i;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << (a[(i + id) % n]) << ' ';
    }
    cout << '\n';
  }
  return 0;
}
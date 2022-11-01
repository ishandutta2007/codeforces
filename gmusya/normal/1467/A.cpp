#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    a[0] = 9;
    if (n >= 1)
      a[1] = 8;
    if (n >= 2)
      a[2] = 9;
    for (int i = 3; i < n; i++)
      a[i] = (a[i - 1] + 1) % 10;
    for (auto &now : a)
      cout << now;
    cout << '\n';
  }
  return 0;
}
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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      b[i] = c - '0';
    }
    a[0] = 1;
    for (int i = 1; i < n; i++)
      if (a[i] + 1 + b[i] != a[i - 1] + b[i - 1])
        a[i]++;
    for (auto &now : a)
      cout << now;
    cout << '\n';
  }
  return 0;
}
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
    vector <int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    for (int i = 0; i < n; i++)
      cin >> c[i];
    vector <int> p(n);
    p[0] = a[0];
    for (int i = 1; i + 1 < n; i++) {
      if (a[i] != p[i - 1])
        p[i] = a[i];
      if (b[i] != p[i - 1])
        p[i] = b[i];
      if (c[i] != p[i - 1])
        p[i] = c[i];
    }
    if (a[n - 1] != p[0] && a[n - 1] != p[n - 2])
      p[n - 1] = a[n - 1];
    if (b[n - 1] != p[0] && b[n - 1] != p[n - 2])
      p[n - 1] = b[n - 1];
    if (c[n - 1] != p[0] && c[n - 1] != p[n - 2])
      p[n - 1] = c[n - 1];
    for (int &x : p)
      cout << x << ' ';
    cout << '\n';
  }
  return 0;
}
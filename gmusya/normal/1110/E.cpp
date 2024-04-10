#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector <ll> c(n), t(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n; i++)
    cin >> t[i];
  if (c[0] != t[0] || c.back() != t.back()) {
    cout << "No\n";
    return 0;
  }
  vector <ll> a(n - 1), b(n - 1);
  for (int i = 0; i + 1 < n; i++)
    a[i] = c[i + 1] - c[i];
  for (int i = 0; i + 1 < n; i++)
    b[i] = t[i + 1] - t[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i + 1 < n; i++)
    if (a[i] != b[i]) {
      cout << "No\n";
      return 0;
    }
  cout << "Yes\n";
  return 0;
}
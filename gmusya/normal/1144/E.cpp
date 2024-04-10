#include <iostream>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = (c - 'a');
  }
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    b[i] = (c - 'a');
  }
  vector <int> c(n);
  for (int i = 0; i < n; i++)
    c[i] = (a[i] + b[i]);
  for (int i = n - 1; i >= 1; i--)
    if (c[i] >= 26)
      c[i - 1] += 1, c[i] -= 26;
  vector <int> d;
  for (int i = 0; i < n; i++) {
    d.push_back(c[i] / 2);
    if (i != n - 1)
      c[i + 1] += (c[i] % 2) * 26;
  }
  for (int i = 0; i < n; i++)
    cout << (char)(d[i] + 'a');
  return 0;
}
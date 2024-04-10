#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  if (n == 1) {
    while (m--) {
      ll x;
      cin >> x;
      cout << a[0] + x << ' ';
    }
    return 0;
  }
  vector <ll> d(n - 1);
  for (int i = 0; i + 1 < n; i++)
    d[i] = a[i + 1] - a[i];
  ll g = 0;
  for (int i = 0; i + 1 < n; i++)
    g = __gcd(g, d[i]);
  vector <ll> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];
  for (int i = 0; i < m; i++)
    cout << __gcd(g, a[0] + b[i]) << ' ';
  return 0;
}
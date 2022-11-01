#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ll sum = 0;
  vector <ll> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  vector <ll> c(n);
  for (int i = 0; i < n; i++)
    sum += b[i] * n - a[i];
  for (int i = 0; i < n; i++)
    c[i] = a[i] - b[i];
  sort(c.rbegin(), c.rend());
  for (int i = 0; i < n; i++)
    sum += (i + 1) * c[i];
  cout << sum;
  return 0;
}
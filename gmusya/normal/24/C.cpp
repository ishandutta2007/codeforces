#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll j;
  cin >> n >> j;
  ll x0, y0;
  cin >> x0 >> y0;
  vector <ll> x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++)
    x.push_back(x[i]), y.push_back(y[i]);
  j %= 2 * n;
  for (int i = 0; i < j; i++)
    x0 = 2 * x[i] - x0, y0 = 2 * y[i] - y0;
  cout << x0 << ' ' << y0;
  return 0;
}
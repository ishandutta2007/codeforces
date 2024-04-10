#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll mult = 1;
  for (ll i = 1; i <= 16; i++) {
    ll g = __gcd(mult, i);
    mult = mult * i / g;
  }
  int n, m;
  cin >> n >> m;
  vector <vector <int>> a(n, vector <int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if ((i + j) & 1)
        a[i][j] = 0;
      a[i][j] *= a[i][j];
      a[i][j] *= a[i][j];
      a[i][j] += mult;
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << a[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
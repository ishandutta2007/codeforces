#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vi a;
vvi l, r;
vvi can;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  can.resize(n, vi(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      can[i][j] = (__gcd(a[i], a[j]) > 1);
  l.resize(n, vi(n)), r.resize(n, vi(n));
  for (int i = 0; i < n; i++)
    l[i][i] = r[i][i] = 1;
  for (int len = 1; len <= n; len++)
    for (int i = 0, j = i + len - 1; j < n; i++, j++)
      for (int k = i; k <= j; k++)
        if (l[i][k] && r[k][j]) {
          if (len == n) {
            cout << "Yes\n";
            return 0;
          }
          if (i - 1 >= 0)
            r[i - 1][j] |= can[i - 1][k];
          if (j + 1 < n)
            l[i][j + 1] |= can[k][j + 1];
        }
  if (l[0][n - 1])
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
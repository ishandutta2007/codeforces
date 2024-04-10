#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[1000][1000];
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  int b[1000];
  long long t = 1LL * a[0][1] * a[0][2] / a[1][2];
  b[0] = int(sqrt(t) + .5);
  for (int i = 1; i < n; i++)
    b[i] = a[0][i] / b[0];

  for (int i = 0; i < n; i++)
    cout << b[i] << ' ';
}
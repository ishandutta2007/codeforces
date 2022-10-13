#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  long long a[200200];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  long long g = 0;
  for (int i = 1; i < n; i++)
    g = __gcd(g, a[i] - a[i - 1]);

  while (m--)
  {
    long long b;
    cin >> b;
    cout << __gcd(b + a[0], g) << ' ';
  }
}
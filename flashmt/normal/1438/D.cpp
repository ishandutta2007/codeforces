#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100100], xorSum = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    xorSum ^= a[i];
  }

  if (*max_element(a, a + n) == *min_element(a, a + n))
  {
    cout << "YES" << endl << 0 << endl;
    return 0;
  }

  if (n % 2 == 0 && xorSum)
  {
    cout << "NO" << endl;
    return 0;
  }

  if (n % 2 == 0)
    n--;
  cout << "YES" << endl << n - 1 << endl;
  for (int i = 3; i <= n; i += 2)
    cout << i - 2 << ' ' << i - 1 << ' ' << i << '\n';
  for (int i = 2; i <= n; i += 2)
    cout << i - 1 << ' ' << i << ' ' << n << '\n';
}
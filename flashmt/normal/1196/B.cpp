#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, n, k, a[200200];
  cin >> test;
  while (test--)
  {
    cin >> n >> k;
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      odd += a[i] % 2;
    }

    if (odd < k || odd % 2 != k % 2) cout << "NO\n";
    else
    {
      cout << "YES\n";
      for (int i = 0; i < n - 1; i++)
        if (a[i] % 2 && k > 1)
        {
          cout << i + 1 << ' ';
          k--;
        }
      cout << n << '\n';
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int d = i + 2, x, isGood = 0;
      cin >> x;

      for (int j = 2; j <= d; j++)
        if (x % j)
        {
          isGood = 1;
          break;
        }

      ans &= isGood;
    }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}
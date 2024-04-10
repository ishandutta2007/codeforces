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
    int n, x, w[100], sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
      cin >> w[i];
      sum += w[i];
    }

    if (sum == x) cout << "NO\n";
    else
    {
      cout << "YES\n";
      sum = 0;
      for (int i = 0; i < n; i++)
      {
        sum += w[i];
        if (sum == x)
          swap(w[i], w[i + 1]);
      }
      for (int i = 0; i < n; i++)
        cout << w[i] << " \n"[i == n - 1];
    }
  }
}
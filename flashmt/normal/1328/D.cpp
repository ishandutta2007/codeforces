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
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a.push_back(x);
    }

    if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end()))
    {
      cout << 1 << '\n';
      for (int i = 0; i < n; i++)
        cout << 1 << " \n"[i == n - 1];
    }
    else
    {
      vector<int> c(n);
      c[0] = 0;
      int canFlip = -1;
      for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1])
        {
          c[i] = c[i - 1];
          canFlip = i;
        }
        else c[i] = c[i - 1] ^ 1;

      int isBad = 0;
      if (a[n - 1] != a[0] && c[n - 1] == c[0])
      {
        if (canFlip < 0)
        {
          isBad = 1;
          c[n - 1] = 2;
        }
        else
        {
          for (int i = canFlip; i < n; i++)
            c[i] ^= 1;
        }
      }
      cout << 2 + isBad << '\n';
      for (int i = 0; i < n; i++)
        cout << c[i] + 1 << " \n"[i == n - 1];
    }
  }
}
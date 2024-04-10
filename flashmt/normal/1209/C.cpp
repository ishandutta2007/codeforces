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
    string s;
    cin >> n >> s;

    int found = 0;
    for (int max1 = 0; max1 < 10; max1++)
    {
      int isGood = 1;
      vector<int> flag(n, 0);

      int last = -1, r1 = -1;
      for (int i = 0; i < n; i++)
      {
        int x = s[i] - '0';
        if (x < max1)
        {
          if (x < last)
            isGood = 0;
          flag[i] = 1;
          last = x;
          r1 = i;
        }
      }

      int l2 = n;
      for (int i = 0; i < n; i++)
      {
        int x = s[i] - '0';
        if (x > max1)
        {
          if (x < last)
            isGood = 0;
          flag[i] = 2;
          last = x;
          if (l2 == n)
            l2 = i;
        }
      }

      for (int i = 0; i < n; i++)
        if (!flag[i])
        {
          if (i < l2) flag[i] = 2;
          else if (i > r1) flag[i] = 1;
          else isGood = 0;
        }

      if (isGood)
      {
        for (int i = 0; i < n; i++)
          cout << flag[i];
        cout << '\n';
        found = 1;
        break;
      }
    }

    if (!found)
      cout << "-\n";
  }
}
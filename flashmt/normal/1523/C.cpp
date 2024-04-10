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
    int n, a[1010], sz = 0;
    cin >> n;
    while (n--)
    {
      int x;
      cin >> x;
      if (x == 1) a[sz++] = 1;
      else
      {
        int found = 0;
        while (sz)
        {
          if (a[sz - 1] + 1 != x) sz--;
          else
          {
            found = 1;
            a[sz - 1]++;
            break;
          }
        }
        assert(found);
      }

      for (int i = 0; i < sz; i++)
        cout << a[i] << ".\n"[i == sz - 1];
    }
  }
}
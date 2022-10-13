#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, m, a[300300];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int low = 0, high = m - 1, ans = m;
  while (low <= high)
  {
    int mid = (low + high) / 2, last = 0, isGood = 1;
    for (int i = 0; i < n; i++)
    {
      int value = a[i] + mid;
      if (value < m)
      {
        if (value < last)
        {
          isGood = 0;
          break;
        }

        last = max(last, a[i]);
      }
      else if (last > value % m)
      {
        last = max(last, a[i]);
      }
    }

    if (isGood) 
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }
  
  cout << ans << endl;
}
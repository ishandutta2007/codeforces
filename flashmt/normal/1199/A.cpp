#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x, y, a[100100];
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++)
    cin >> a[i];
    
  for (int i = 0; i < n; i++)
  {
    int isGood = 1;
    for (int j = max(0, i - x); j <= min(n - 1, i + y); j++)
      if (j != i && a[j] <= a[i])
        isGood = 0;
    if (isGood)
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
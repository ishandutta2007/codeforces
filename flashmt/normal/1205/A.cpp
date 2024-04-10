#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  if (n % 2 == 0)
  {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  int ans[200200];
  for (int i = 0, low = 1, high = n * 2; i < n; i++)
    if (i % 2)
    {
      ans[i] = high--;
      ans[n + i] = high--;
    }
    else
    {
      ans[i] = low++;
      ans[n + i] = low++;
    }
  for (int i = 0; i < n * 2; i++)
    cout << ans[i] << " \n"[i == n * 2 - 1];
}
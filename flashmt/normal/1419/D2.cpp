#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(begin(a), end(a));

  int low = 1, high = (n - 1) / 2, ans = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int isGood = 1;
    for (int i = 0; i < mid; i++)
      if (a[i] >= a[n - mid - 1 + i])
        isGood = 0;
    if (!isGood) high = mid - 1;
    else
    {
      ans = mid;
      low = mid + 1;
    }
  }

  cout << ans << '\n';
  for (int i = 0; i < ans; i++)
    cout << a[n - ans - 1 + i] << ' ' << a[i] << ' ';
  cout << a[n - 1] << ' ';
  for (int i = ans; i < n - ans - 1; i++)
    cout << a[i] << ' ';
}
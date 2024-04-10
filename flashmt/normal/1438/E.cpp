#include <bits/stdc++.h>
using namespace std;

int leftmostBit(int x)
{
  for (int i = 29; i >= 0; i--)
    if (x >> i & 1)
      return i;
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[200200], bit[200200];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    bit[i] = leftmostBit(a[i]);
  }

  int ans = 0;
  for (int l = 0; l < n; l++)
  {
    int sum = 0, bound = 1 << bit[l] + 1;
    for (int r = l + 2; r < n; r++)
    {
      sum += a[r - 1];
      if (sum >= bound)
        break;
      ans += (a[l] ^ a[r]) == sum;
    }
  }

  for (int r = n - 1; r; r--)
  {
    int sum = 0, bound = 1 << bit[r] + 1;
    for (int l = r - 2; l >= 0; l--)
    {
      sum += a[l + 1];
      if (sum >= bound)
        break;
      if (bit[l] < bit[r])
        ans += (a[r] ^ a[l]) == sum;
    }
  }

  cout << ans << endl;
}
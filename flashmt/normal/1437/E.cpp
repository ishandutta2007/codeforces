#include <bits/stdc++.h>
using namespace std;
const int oo = 1001000000;

int n, k, a[500500], b[500500], seq[500500];

int isGoodPair(int x, int y)
{
  return y - x <= a[y] - a[x];
}

int lis(int from, int to)
{
  int length = 0;
  for (int i = from + 1; i < to; i++)
    if (isGoodPair(from, i) && isGoodPair(i, to))
    {
      int low = 1, high = length, id = 0;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (isGoodPair(seq[mid], i))
        {
          id = mid;
          low = mid + 1;
        }
        else high = mid - 1;
      }
      seq[++id] = i;
      length = max(length, id);
    }

  return length;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a[0] = -oo;
  a[n + 1] = oo;
  for (int i = 1; i <= k; i++)
    cin >> b[i];
  b[0] = 0;
  b[k + 1] = n + 1;

  int ans = 0;
  for (int i = 0; i <= k; i++)
    if (isGoodPair(b[i], b[i + 1])) ans += b[i + 1] - b[i] - 1 - lis(b[i], b[i + 1]);
    else
    {
      cout << -1 << endl;
      return 0;
    }

  cout << ans << endl;
}
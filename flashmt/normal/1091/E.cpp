#include <bits/stdc++.h>
using namespace std;

int n, cnt[500500], a[500500];
long long sum[500500];

int eval(int x)
{
  int id = 0;
  for (int v = n; v >= 0; v--)
    for (int i = 0; i < cnt[v] + (x == v); i++)
    {
      a[++id] = v;
      sum[id] = sum[id - 1] + v;
    }

  for (int i = 1, j = n; i <= n; i++)
  {
    while (j > i && a[j] < i)
      j--;
    j = max(j, i);
    if (sum[i] > i * (j - 1LL) + sum[n] - sum[j])
      return i;
  }

  return n + 1;
}

int findMinAns()
{
  int low = 1, high = n - 1, res = n;
  while (high - low > 5)
  {
    int mid = (low + high) / 2, v = eval(mid);
    if (v > n)
    {
      res = mid;
      high = mid - 1;
    }
    else if (v < eval(mid + 1)) low = mid + 1;
    else high = mid - 1;
  }

  for (int i = low; i <= high; i++)
    if (eval(i) > n)
      res = min(res, i);

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int parity = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    cnt[x]++;
    parity ^= x % 2;
  }
  n++;

  int v0 = eval(0), minAns = 0;
  if (v0 <= n)
  {
    minAns = findMinAns();
    if (minAns >= n)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  int low = minAns + 1, high = n - 1, maxAns = minAns;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (eval(mid) > n)
    {
      maxAns = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }

  for (int i = minAns; i <= maxAns; i++)
    if (i % 2 == parity)
      cout << i << ' ';
}
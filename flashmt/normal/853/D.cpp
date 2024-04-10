#include <bits/stdc++.h>
using namespace std;

int n, a[300300], flag[300300];

int solveSkip(int budget)
{
  int bonus = 0;
  for (int i = 0; i < n; i++)
  {
    if (flag[i])
    {
      if (budget < a[i])
        return 0;
      budget -= a[i];
      bonus += a[i] / 10;
    }
    else if (bonus >= a[i]) bonus -= a[i];
    else if (bonus + budget >= a[i])
    {
      budget -= a[i] - bonus;
      bonus = 0;
    }
    else return 0;
  }

  return 1;
}

int ok(int _budget)
{
  int bonus = 0, last[2] = {-1, -1}, res = 1, budget = _budget;
  memset(flag, 0, sizeof flag);
  for (int i = 0; i < n; i++)
    if (budget >= a[i])
    {
      budget -= a[i];
      last[a[i] / 10 - 1] = i;
      flag[i] = 1;
      bonus += a[i] / 10;
    }
    else if (bonus >= a[i]) bonus -= a[i];
    else if (budget + bonus >= a[i])
    {
      budget -= a[i] - bonus;
      bonus = 0;
    }
    else
    {
      res = 0;
      break;
    }

  if (res)
    return 1;

  for (int j = 0; j < 2; j++)
    if (last[j] >= 0)
    {
      int target = -1;
      for (int k = last[j] + 1; k < n; k++)
        if (a[k] != a[last[j]] && !flag[k])
        {
          target = k;
          break;
        }

      if (target >= 0)
      {
        flag[last[j]] = 0;
        flag[target] = 1;
        if (solveSkip(_budget))
          return 1;
        flag[last[j]] = 1;
        flag[target] = 0;
      }
    }

  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i] /= 100;
  }

  int low = 0, high = n * 20, ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (ok(mid)) 
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << ans * 100 << endl;
}
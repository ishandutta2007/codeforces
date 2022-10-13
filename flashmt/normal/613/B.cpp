#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long maxA, m, cf, cm;
  cin >> n >> maxA >> cf >> cm >> m;
  vector<pair<long long, int>> a;
  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;
    a.push_back({x, i});
  }

  sort(rbegin(a), rend(a));
  vector<long long> s(n + 1);
  for (int i = 0; i < n; i++)
    s[i + 1] = s[i] + a[i].first;

  vector<long long> cost(n + 1);
  for (int i = n - 1; i; i--)
    cost[i] = cost[i + 1] + (n - i) * (a[i - 1].first - a[i].first);

  long long ans = -1;
  int numMax = 0, minId = -1, bestMinA = -1;
  for (int i = 0; i <= n; i++)
  {
    long long budget = m - (i * maxA - s[i]);
    if (budget < 0)
      continue;

    if (i == n)
    {
      long long value = n * cf + maxA * cm;
      if (value > ans)
      {
        ans = value;
        numMax = minId = n;
      }
    }
    else
    {
      int low = i + 1, high = n - 1, id = n;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (cost[mid] > budget) low = mid + 1;
        else
        {
          id = mid;
          high = mid - 1;
        }
      }

      budget -= cost[id];
      long long minA = min(a[id - 1].first + budget / (n - id + 1), maxA);
      long long value = i * cf + minA * cm;
      if (value > ans)
      {
        ans = value;
        numMax = i;
        minId = id - 1;
        bestMinA = minA;
      }
    }
  }

  vector<long long> b(n);
  for (int i = 0; i < n; i++)
    if (i < numMax) b[a[i].second] = maxA;
    else if (i >= minId) b[a[i].second] = bestMinA;
    else b[a[i].second] = a[i].first;

  cout << ans << endl;
  for (auto x : b)
    cout << x << ' ';
}
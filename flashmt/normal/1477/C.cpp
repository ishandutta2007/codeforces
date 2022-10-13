#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x[5000], y[5000];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  int last = 0;
  vector<int> flag(n, 0);
  flag[0] = 1;
  cout << 1 << ' ';
  for (int i = 1; i < n; i++)
  {
    long long maxDist = -1;
    int best = -1;
    for (int j = 0; j < n; j++)
      if (!flag[j])
      {
        long long dist = 1LL * (x[j] - x[last]) * (x[j] - x[last]) + 1LL * (y[j] - y[last]) * (y[j] - y[last]);
        if (dist > maxDist)
        {
          best = j;
          maxDist = dist;
        }
      }

    cout << best + 1 << ' ';
    flag[best] = 1;
    last = best;
  }
}
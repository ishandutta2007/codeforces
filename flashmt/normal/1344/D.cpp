#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  auto calc = [&](int i, long long minGain)
  {
    int low = 0, high = a[i] - 1, res = a[i];
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (a[i] - (3LL * mid * mid + 3LL * mid + 1) < minGain)
      {
        res = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }
    return res;
  };

  long long low = -4e18, high = 1e9, minGain = high + 1;
  while (low <= high)
  {
    long long mid = (low + high) / 2, cnt = 0;
    for (int i = 0; i < n; i++)
      cnt += calc(i, mid);
    if (cnt < k) high = mid - 1;
    else
    {
      minGain = mid;
      low = mid + 1;
    }
  }

  vector<int> b(n);
  long long sum = 0;
  vector<pair<long long, int>> cand;
  for (int i = 0; i < n; i++)
  {
    b[i] = max(0, calc(i, minGain) - 1);
    sum += b[i];
    cand.push_back({a[i] - (3LL * b[i] * b[i] + 3LL * b[i] + 1), i});
  }
  sort(rbegin(cand), rend(cand));
  for (int i = 0; i < k - sum; i++)
    b[cand[i].second]++;

  for (int x : b)
    cout << x << ' ';
}
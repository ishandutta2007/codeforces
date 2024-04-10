#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, k, b, c, a[200200];
vector< pair<int,int> > events[5];
multiset<long long> candidates[5];
long long sum[5];

void push(int mod, long long cost)
{
  if (candidates[mod].size() < k - 1)
  {
    candidates[mod].insert(cost);
    sum[mod] += cost;
  }
  else if (*candidates[mod].begin() < cost)
  {
    sum[mod] -= *candidates[mod].begin();
    candidates[mod].erase(candidates[mod].begin());
    candidates[mod].insert(cost);
    sum[mod] += cost;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> b >> c;
  b = min(b, c * 5);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = n; i; i--)
  {
    a[i] -= a[1];
    for (int add = 0; add < 5; add++)
    {
      int mod = (a[i] + add) % 5;
      events[mod].push_back({a[i] + add, add});
    }
  }

  long long ans = oo;
  for (int mod = 0; mod < 5; mod++)
  {
    sort(events[mod].begin(), events[mod].end());
    for (int i = 0; i < n; i++)
    {
      int value = events[mod][i].first, add = events[mod][i].second;
      if (i >= k - 1)
        ans = min(ans, value / 5LL * b * (k - 1) + add * c - sum[mod]);
      push(mod, value / 5LL * b - add * c);
    }
  }

  cout << ans << endl;
}
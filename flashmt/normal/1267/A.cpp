#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long t[200200];
  vector<tuple<long long, int, int>> events;
  set<pair<long long, int>> firstMade;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    long long a, b;
    cin >> a >> b >> t[i];
    events.push_back({a + t[i], 0, i});
    events.push_back({b, 1, i});
  }

  sort(events.begin(), events.end());
  set<pair<long long, int>> active;
  long long ans = 0, lastX = 0;
  for (auto [x, isClose, i] : events)
  {
    if (!active.empty() && x >= lastX)
    {
      long long minT = active.begin()->first;
      long long cnt = (x - lastX) / minT;
      ans += cnt;
      lastX += minT * cnt;
    }

    if (isClose) active.erase({t[i], i});
    else
    {
      active.insert({t[i], i});
      lastX = max(lastX, x - t[i]);
    }
  }

  cout << ans << endl;
}
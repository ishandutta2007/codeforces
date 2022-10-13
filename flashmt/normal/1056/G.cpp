#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m, n, s;
  long long t;
  cin >> n >> m >> s >> t;
  s--;

  while (t % n)
  {
    if (s < m) s = (s + t % n) % n;
    else s = (s - t % n + n) % n;
    t--;
  }
  t /= n;

  map<int, long long> seen;
  seen[s] = t;
  vector<int> stations(1, s);
  long long initialT = t;
  while (t)
  {
    for (int i = n; i; i--)
      if (s < m) s = (s + i) % n;
      else s = (s + n - i) % n;
    t--;
    if (seen.count(s))
    {
      long long cycle = seen[s] - t;
      cout << stations[initialT - seen[s] + t % cycle] + 1 << endl;
      return 0;
    }
    seen[s] = t;
    stations.push_back(s);
  }

  cout << s + 1 << endl;
}
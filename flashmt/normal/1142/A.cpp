#include <bits/stdc++.h>
using namespace std;

void solve(long long a, long long b, long long all, long long &minStop, long long &maxStop)
{
  long long dist = (b - a + all) % all;
  long long stop = all / __gcd(dist, all);
  minStop = min(minStop, stop);
  maxStop = max(maxStop, stop);
}

int main()
{
  long long n, k, a, b;
  cin >> n >> k >> a >> b;
  long long minStop = 1LL * n * k, maxStop = 1;
  for (int i = 0; i < n; i++)
  {
    solve(a, k * i + b, n * k, minStop, maxStop);
    if (a)
      solve(k - a, k * i + b, n * k, minStop, maxStop);
    if (b)
      solve(a, k * (i + 1) - b, n * k, minStop, maxStop);
    if (a && b)
      solve(k - a, k * (i + 1) - b, n * k, minStop, maxStop);
  }
  cout << minStop << ' ' << maxStop << endl;
}
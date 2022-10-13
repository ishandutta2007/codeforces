#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, x;
  long long ans = 0, remaining = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    long long withRemaining = min(remaining, x / 2LL);
    ans += withRemaining;
    remaining -= withRemaining;
    x -= withRemaining * 2;
    ans += x / 3;
    remaining += x % 3;
  }
  cout << ans << endl;
}